/*
 *Copyright (c) 2022 All rights reserved
 *@description: basic data structure for first and follow set
 *@author: Zhixing Lu
 *@date: 2022-05-21
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#ifndef FIRST_FOLLOW_SELECT_FFS_SET_H_
#define FIRST_FOLLOW_SELECT_FFS_SET_H_

#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
#include "../utils.h"

#define Rule std::pair<char,std::string> // {A , abcd}
#define Set std::unordered_map<char, std::set<char>> // [A] -> {a,b,c,d}
#define SELECT_SET std::vector<std::pair<Rule,std::set<char>>>

struct FFS_set {
    Set first_set;
    Set follow_set;
    SELECT_SET select_set;
};

struct RuleSet
{
    std::vector<char> non_terminal_set;
    std::vector<char> terminal_set;
    std::vector<Rule> rules;
};

std::string ruleToString(Rule &rule);

int ffs(std::vector<std::string> &grammar_lines, FFS_set &ffs_set);

int getRuleSet(std::vector<std::string> &grammar_lines, RuleSet &rule_set);

void calculateFirstSet(RuleSet &rule_set, Set&first_set);

void calculateFollowSet(Set&first_set, RuleSet &rule_set, Set&follow_set);

void calculateSelectSet(Set&first_set,
                        Set&follow_set, 
                        RuleSet &rule_set, 
                        SELECT_SET&select_set);

#endif // FIRST_FOLLOW_SELECT_FFS_SET_H_
