/*
 *Copyright (c) 2022 All rights reserved
 *@description: basic data structure for first and follow set
 *@author: Zhixing Lu
 *@date: 2022-05-21
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#ifndef FIRST_FOLLOW_SELECT_FFS_SET_HPP_
#define FIRST_FOLLOW_SELECT_FFS_SET_HPP_

#include "../utils.hpp"


struct FFS_set {
    Set first_set;
    Set follow_set;
    SELECT_SET select_set;
};



std::string ruleToString(Rule &rule);

int ffs(std::vector<std::string> &grammar_lines, FFS_set &ffs_set);

void calculateFirstSet(RuleSet &rule_set, Set&first_set);

void calculateFollowSet(Set&first_set, RuleSet &rule_set, Set&follow_set);

void calculateSelectSet(Set&first_set,
                        Set&follow_set, 
                        RuleSet &rule_set, 
                        SELECT_SET&select_set);

#endif // FIRST_FOLLOW_SELECT_FFS_SET_HPP_
