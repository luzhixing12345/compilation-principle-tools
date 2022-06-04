/*
 *Copyright (c) 2022 All rights reserved
 *@description: calculate the first and follow and select set of a grammar
 *@author: Zhixing Lu
 *@date: 2022-05-20
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#include "FFS_set.h"

char BEGIN_SYMBOL = 'S';

// remove the space in the string
void clearSpace(std::string &str) {
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

// check if the char c is a terminal word
bool checkTerminal(char c, std::vector<char>&non_terminal_set) {
    for (char &s : non_terminal_set) {
        if (c == s) return false;
    }
    return true;
}

std::string ruleToString(Rule &rule) {
    std::string rule_str = " -> " + rule.second;
    if (rule.first == ' ') rule_str = " ";
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

int ffs(std::vector<std::string> &grammar_lines, FFS_set &ffs_set) {

    BEGIN_SYMBOL = grammar_lines[0][0]; // by default, the first character in the first line is the begin symbol

    RuleSet rule_set;
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
        for (char &word : production) {
            if (checkTerminal(word, rule_set.non_terminal_set)) {
                first_set[key].insert(word);
                break;
            } else {
                for (auto &it : first_set[word]) first_set[key].insert(it);
                // if the non terminal word could produce EMPTY, then check the next word
                if (first_set[word].count(EMPTY) == 0) break;
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
            if (!checkTerminal(before, rule_set.non_terminal_set)) {
                for (int j = i+1; j < production.size() ; j++) {
                    char after = production[j];
                    if (checkTerminal(after, rule_set.non_terminal_set)) {
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
            if (checkTerminal(end, rule_set.non_terminal_set)) {
                break;
            } else {
                for (auto &it : follow_set[key]) follow_set[end].insert(it);
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
            if (checkTerminal(first_word, rule_set.non_terminal_set)) {
                std::set<char> temp;
                temp.insert(first_word);
                select_set.push_back(std::make_pair(rule, temp));
            } else {
                select_set.push_back(std::make_pair(rule, first_set[first_word]));
            }
        }
    }
}

int getRuleSet(std::vector<std::string> &grammar_lines, RuleSet &rule_set) {

    std::vector<char> non_terminal_set, terminal_set;
    std::vector<Rule> rules;
    std::string line;
    for (int i = 0; i < grammar_lines.size(); i++) {
        line = grammar_lines[i];
        // split from '->'
        std::string left_side = line.substr(0, line.find("->"));
        clearSpace(left_side);

        char left_side_char;
        if (left_side.size() !=1) {
            std::cout<< "left side to be "<< left_side << std::endl;
            std::cout<< "non terminal word should be a single char "<< std::endl;
            return RUN_TIME_ERROR;
        } else {
            left_side_char = left_side[0];
        }
        // left side to be in non_terminal_set
        non_terminal_set.push_back(left_side_char);

        std::string right_side = line.substr(line.find("->") + 2);
        // split from '|'
        std::vector<std::string> right_side_rules;
        std::string right_side_rule;
        for (auto &c : right_side) {
            if (c == '|') {
                clearSpace(right_side_rule);

                right_side_rules.push_back(right_side_rule);
                right_side_rule = "";
            } else {
                right_side_rule += c;
            }
        }
        clearSpace(right_side_rule);
        right_side_rules.push_back(right_side_rule);

        for (auto &right_side_rule : right_side_rules) {
            Rule t_rule;
            t_rule.first = left_side_char;
            t_rule.second = right_side_rule;
            rules.push_back(t_rule);
        }
    }

    // right side && not in left side to be in terminal_set
    for (auto &pair : rules) {
        for (char &c : pair.second) {
            if (checkTerminal(c, non_terminal_set)) {
                terminal_set.push_back(c);
            }
        }
    }
    
    rule_set.non_terminal_set = non_terminal_set;
    rule_set.terminal_set = terminal_set;
    rule_set.rules = rules;
    //showSet(rules, non_terminal_set, terminal_set);
    return SUCCESS;
}