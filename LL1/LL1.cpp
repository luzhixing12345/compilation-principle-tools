/*
 *Copyright (c) 2022 All rights reserved
 *@description: LL1 grammar implementation
 *@author: Zhixing Lu
 *@date: 2022-05-22
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#include "LL1.h"

#define BLOCK std::vector<std::pair<bool,std::string>>

void showLL1action(LL1_DEDUCTION &ll1_deduction);

int LL1_analyasis(std::string &input_str,
                  char start_symbol,
                  RuleSet &rule_set,
                  SELECT_SET &select_set, 
                  LL1_DEDUCTION &ll1_deduction) {
    
    std::unordered_map<std::string, Rule> table_map; // use string(terminal + non terminal word) as hashmap keys
    bool collision = showLL1analysisTable(rule_set, select_set, table_map);
    if (collision) {
        std::cout << "There is collision in the select set." << std::endl;
        return RUN_TIME_ERROR;
    }

    input_str += "$"; // add end character
    std::stack<char> stk;
    stk.push('$');
    stk.push(start_symbol);

    ACTION action;
    while (!stk.empty()) {
        action.residual_string = input_str;
        action.analysis_stack = stackToString(stk);
        if (input_str.size() == 0) return INPUT_ERROR;
        if (action.residual_string[0] == action.analysis_stack[0]) {
            input_str.erase(0,1);
            stk.pop();
            action.analysis_action = std::make_pair(' ',"");
        } else {
            std::string key = "" + input_str[0] + stk.top();
            if (table_map.count(key) == 0) return INPUT_ERROR;
            action.analysis_action = table_map[key];
            stk.pop();
            for (int i = action.analysis_action.second.size()-1; i >= 0; i--) {
                if (action.analysis_action.second[i] == EMPTY) break;
                stk.push(action.analysis_action.second[i]);
            }
        }
        ll1_deduction.push_back(action);
    }
    std::cout << std::endl;
    showLL1action(ll1_deduction);
    return SUCCESS;
}


void drawLine(int length) {
    
    for (int i = 0; i < length ; i++) {
        std::cout << "|";
        for (int j = 0; j < TABLE_SIZE ; j++) {
            std::cout << "-";
        }
    }
    std::cout << "|"<< std::endl;
}

void drawBlock(BLOCK &blocks, int length) {
    int side_distance;
    for (int i = 0; i < length; i++) {
        std::cout << '|';
        side_distance = (TABLE_SIZE - blocks[i].second.size())/2;
        for (int j = 0; j < side_distance ; j++) std::cout << " ";
        std::cout << blocks[i].second;
        for (int j = 0; j < TABLE_SIZE-2*side_distance-blocks[i].second.size(); j++) std::cout << " ";
        for (int j = 0; j < side_distance ; j++) std::cout << " ";
        
    }
    std::cout << "|" << std::endl;
    drawLine(length);
}

void resetBlock(BLOCK &blocks) {
    for (auto &it : blocks) {
        it.first = false;
        it.second = "";
    }
}

bool showLL1analysisTable(RuleSet &rule_set, SELECT_SET &select_set, std::unordered_map<std::string, Rule> &table_map) {

    // only calculate terminal set in select set instead of all terminals
    std::set<char> analysis_terminal_set;
    for (auto &it : select_set) {
        for (auto &it2 : it.second) {
            analysis_terminal_set.insert(it2);
        }
    }
    int table_length = analysis_terminal_set.size() + 1;
    int table_width = rule_set.non_terminal_set.size() + 1;
    std::unordered_map<char, int> terminal_map;
    drawLine(table_length);

    BLOCK blocks(table_length);

    bool collision = false;
    for (int i = 0; i < table_width; i++) {
        resetBlock(blocks);
        if (i == 0) {
            // the first line of the table
            blocks[0].second += "+";
            int index = 1;
            for (auto &it : analysis_terminal_set) {
                blocks[index].second += it;
                terminal_map[it] = index;
                index++;
            }
        } else {
            char non_terminal_word = rule_set.non_terminal_set[i-1];
            blocks[0].first = true;
            blocks[0].second += non_terminal_word;
            for (auto &it : select_set) {
                if (it.first.first == non_terminal_word) {
                    // move item to its block
                    for (auto &item : it.second) {
                        int id = terminal_map[item];
                        if (blocks[id].first) {
                            collision = true;
                            blocks[id].second += " | " + ruleToString(it.first);
                        } else {
                            blocks[id].first = true;
                            blocks[id].second += ruleToString(it.first);
                        }
                        // add key and production to table_map
                        std::string key = "" + item + non_terminal_word;
                        table_map[key] = it.first;
                    }
                }
            }
        }
        drawBlock(blocks, table_length);
    }
    return collision;
}

void showLL1action(LL1_DEDUCTION &ll1_deduction) {

    int table_length = 3;
    int table_width = ll1_deduction.size() + 1;

    BLOCK blocks(table_length);
    for (int i = 0; i < table_width; i++) {
        resetBlock(blocks);
        
        if (i == 0) {
            blocks[0].second += "residual str";
            blocks[1].second += "analysis stk";
            blocks[2].second += "analysis act";
        } else {
            blocks[0].second += ll1_deduction[i-1].residual_string;
            blocks[1].second += ll1_deduction[i-1].analysis_stack;
            blocks[2].second += ruleToString(ll1_deduction[i-1].analysis_action);
        }
        // test
        // std::cout << i << std::endl;
        // std::cout << blocks[0].second << " "<< blocks[0].second << " ";
        // std::cout << blocks[2].second << std::endl;
        drawBlock(blocks, table_length);
    }
    
}