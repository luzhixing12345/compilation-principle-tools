/*
 *Copyright (c) 2022 All rights reserved
 *@description: calculate the first and follow and select set of a grammar
 *@author: Zhixing Lu
 *@date: 2022-05-20
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#include "FFS_set.hpp"

char BEGIN_SYMBOL = 'S';

std::string ruleToString(Rule &rule) {
    std::string rule_str = " -> " + rule.second;
    if (rule.first == ' ') rule_str = rule.second;
    else rule_str = rule.first + rule_str;
    return rule_str;
}

void showSet(std::vector<Rule>&rules, std::vector<char> &non_terminal_set, std::vector<char> &terminal_set) {
    // test
    std::cout << "rules:" << std::endl;
    for (auto &rule : rules) {
        std::cout << rule.first << " -> " << rule.second << std::endl;
    }
    std::cout << "terminal set: { ";
    for (auto &i : terminal_set) {
        std::cout<< i << " ";
    }
    std::cout << "}" << std::endl;
    std::cout << "non terminal set: { ";
    for (auto &i : non_terminal_set) {
        std::cout<< i << " ";
    }
    std::cout<< "}" << std::endl;
}

int ffs(std::vector<std::string> &grammar_lines, FFS_set &ffs_set, RuleSet &rule_set) {

    BEGIN_SYMBOL = grammar_lines[0][0]; // by default, the first character in the first line is the begin symbol

    getRuleSet(grammar_lines, rule_set);

    // calculate first set
    calculateFirstSet(rule_set, ffs_set.first_set);

    // calcualte follow set
    calculateFollowSet(ffs_set.first_set, rule_set, ffs_set.follow_set);

    // calcualte select set
    calculateSelectSet(ffs_set.first_set, ffs_set.follow_set, rule_set, ffs_set.select_set);

    return 0;
}

void calculateFirstSet(RuleSet &rule_set, Set &first_set) {

    Set temp_set = first_set;
    for (Rule &rule : rule_set.rules) {
        char key = rule.first;
        std::string production = rule.second;
        
        for (int i = 0; i < production.size(); i++) {
            char word = production[i];
            bool exist_empty = false;
            if (isTerminal(word, rule_set.non_terminal_set)) {
                first_set[key].insert(word);
                break;
            } else {
                for (auto &it : first_set[word]) {
                    if (it != EMPTY) {
                        first_set[key].insert(it);
                    } else {
                        exist_empty = true;
                    }
                }
                // if EMPTY is not in the first set of word, then break
                if (!exist_empty) {
                    break;
                } else {
                    // if EMPTY is in the first set of word, then continue
                    // if word is the last word in the production, then add EMPTY to the first set of key
                    if (i == production.size() - 1) {
                        first_set[key].insert(EMPTY);
                    }
                }
            }
        }
    }
    if (temp_set == first_set) return;
    else calculateFirstSet(rule_set, first_set);
}

void calculateFollowSet(Set &first_set, RuleSet &rule_set, Set &follow_set) {

    Set temp_set = follow_set;
    follow_set[BEGIN_SYMBOL].insert('$');
    for (Rule &rule : rule_set.rules) {

        std::string production = rule.second;
        if (production[0] == EMPTY) {
            continue;
        }
        // if A is a non terminal word
        // then the word after A is the follow set of A
        for (int i = 0; i < production.size() ; i++) {
            char before = production[i];
            if (!isTerminal(before, rule_set.non_terminal_set)) {
                for (int j = i+1; j < production.size() ; j++) {
                    char after = production[j];
                    if (isTerminal(after, rule_set.non_terminal_set)) {
                        follow_set[before].insert(after);
                        break;
                    } else {
                        for (auto &it : first_set[after]) follow_set[before].insert(it);
                        if (follow_set[before].count(EMPTY) == 0) {
                            break;
                        } else {
                            follow_set[before].erase(EMPTY);
                        }
                    }
                }
            }
        }
        char key = rule.first;
        
        // if the last word is a non terminal word
        // then the follow set of the last word includes the follow set of the rule
        for (int i = production.size()-1; i >= 0; i--) {
            char end = production[i];
            bool exist_empty = false;
            if (isTerminal(end, rule_set.non_terminal_set)) {
                break;
            } else {
                for (auto &it : follow_set[key]) follow_set[end].insert(it);
                for (auto &it : first_set[end]) {
                    if (it == EMPTY) {
                        exist_empty = true;
                        break;
                    }
                }
                if (!exist_empty) break;
            }
        }
    }
    if (temp_set == follow_set) return;
    else calculateFollowSet(first_set, rule_set, follow_set);
}

void calculateSelectSet(Set &first_set,
                        Set &follow_set,
                        RuleSet &rule_set, 
                        SELECT_SET &select_set)
{
    // for each rule
    // if the first word is a non terminal word
    // then the first set of the first word is the select set of the rule
    // if the first word is a terminal word
    // then the first word is the select set of the rule
    // if the first word is EMPTY
    // then the follow set of the rule is the select set of the rule
    for (Rule &rule : rule_set.rules) {
        char first_word = rule.second[0];
        if (first_word == EMPTY) {
            char key = rule.first;
            select_set.push_back(std::make_pair(rule, follow_set[key]));
        } else {
            if (isTerminal(first_word, rule_set.non_terminal_set)) {
                std::set<char> temp;
                temp.insert(first_word);
                select_set.push_back(std::make_pair(rule, temp));
            } else {
                select_set.push_back(std::make_pair(rule, first_set[first_word]));
            }
        }
    }
}

void showFFS(FFS_set &ffs_set) {
    showFirstSet(ffs_set.first_set);
    showFollowSet(ffs_set.follow_set);
    showSelectSet(ffs_set.select_set);
}

void showFirstSet(Set &first_set) {

    for (int i = 0; i <= 20 ; i++) std::cout << "-";
    std::cout << std::endl;
    std::cout << "FIRST SET: "<<std::endl;
    for (auto &it :first_set) {
        std::cout << it.first << ": ";
        for (auto &i : it.second) {
            std:: cout<< i << " ";
        }
        std::cout<<std::endl;
    }
}

void showFollowSet(Set &follow_set) {

    for (int i = 0; i <= 20 ; i++) std::cout << "-";
    std::cout << std::endl;
    std::cout << "FOLLOW SET: "<<std::endl;
    for (auto &it : follow_set) {
        std::cout << it.first << ": ";
        for (auto &i : it.second) {
            std:: cout<< i << " ";
        }
        std::cout<<std::endl;
    }
}

void showSelectSet(SELECT_SET &select_set) {

    for (int i = 0; i <= 20 ; i++) std::cout << "-";
    std::cout << std::endl;
    std::cout << "SELECT SET: "<<std::endl;
    for (auto &it : select_set) {
        std::string production = ruleToString(it.first);
        std::cout << std::left << std::setw(10) << production << ": ";
        for (auto &i : it.second) {
            std:: cout<< i << " ";
        }
        std::cout<<std::endl;
    }

}