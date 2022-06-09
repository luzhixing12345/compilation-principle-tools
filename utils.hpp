/*
 *Copyright (c) 2022 All rights reserved
 *@description: utils for compilation principle
 *@author: Zhixing Lu
 *@date: 2022-05-23
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/
#pragma once
#ifndef UTILS_HPP_
#define UTILS_HPP_ 

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <stack>
#include <string>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>

#define INPUT_ERROR -1
#define SUCCESS 0
#define RUN_TIME_ERROR 1
#define EMPTY 'e'
#define TABLE_SIZE 15 // size of the table



#define Rule std::pair<char,std::string> // {A , abcd}
#define Set std::unordered_map<char, std::set<char>> // [A] -> {a,b,c,d}
#define SELECT_SET std::vector<std::pair<Rule,std::set<char>>> // {A -> abcd, {a,b,c,d}}

struct RuleSet
{
    std::vector<char> non_terminal_set;
    std::vector<char> terminal_set;
    std::vector<Rule> rules;
};


static int read_grammar_lines(int argc, char *argv[], std::vector<std::string> &grammar_lines) {

    if (argc != 2) {
        std::cout << "Usage: main.exe grammar.txt" << std::endl;
        return INPUT_ERROR;
    }
    std::string grammar_file = argv[1];
    // read grammar file
    std::string line;
    std::ifstream grammar_file_stream;
    grammar_file_stream.open(grammar_file, std::ios::in);
    if (!grammar_file_stream.is_open()) {
        std::cout << "Error: cannot open grammar file" << std::endl;
        return RUN_TIME_ERROR;
    }
    while (std::getline(grammar_file_stream, line)) {
        if (line.empty()) {
            continue;
        }
        // remove the space in the line
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                line.erase(i, 1);
                i--;
            }
        }
        grammar_lines.push_back(line);
    }
    grammar_file_stream.close();
    // test
    // for (auto &line : grammar_lines) {
    //     std::cout << line << std::endl;
    // }
    return SUCCESS;
}

static void signalCheck(int signal, std::string checkItemDescription) {
    for (int i = 0; i <= 20 ; i++) std::cout << "-";
    std::cout << std::endl;

    if (signal == SUCCESS) {
        std::cout << "SUCCESS to calculate " << checkItemDescription << std::endl;
    } else if (signal == RUN_TIME_ERROR) {
        std::cout << "RUN_TIME_ERROR" << std::endl;
    } else if (signal == INPUT_ERROR) {
        std::cout << "INPUT_ERROR" << std::endl;
    } else {
        std::cout << "STANGE ERROR ???" << std::endl;
    }

    for (int i = 0; i <= 20 ; i++) std::cout << "-";
    std::cout << std::endl;
}



// remove the space in the string
static void clearSpace(std::string &str) {
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

// check if the char c is a terminal word
static bool checkTerminal(char c, std::vector<char>&non_terminal_set) {
    for (char &s : non_terminal_set) {
        if (c == s) return false;
    }
    return true;
}

static int getRuleSet(std::vector<std::string> &grammar_lines, RuleSet &rule_set) {

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


#endif  // UTILS_HPP_ 
