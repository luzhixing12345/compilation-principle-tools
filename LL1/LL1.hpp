/*
 *Copyright (c) 2022 All rights reserved
 *@description: defination for LL1 grammar
 *@author: Zhixing Lu
 *@date: 2022-05-23
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#ifndef LL1_LL1_HPP_
#define LL1_LL1_HPP_

# include "../utils.hpp"
# include "../FIRST-FOLLOW-SELECT/FFS_set.hpp"
# define LL1_DEDUCTION std::vector<ACTION>

struct ACTION
{
    std::string residual_string;
    std::string analysis_stack;
    Rule analysis_action;
};


int LL1_analyasis(char start_symbol,
                  RuleSet &rule_set,
                  SELECT_SET &select_set, 
                  LL1_DEDUCTION &ll1_deduction);

bool showLL1analysisTable(RuleSet &rule_set, SELECT_SET &select_set, std::unordered_map<std::string, std::vector<Rule>> &table_map);

// pass by value instead of pointer to avoid recoverying stack
static std::string stackToString(std::stack<char> stk) {
    std::string str = "";
    while (!stk.empty()) {
        str.push_back(stk.top());
        stk.pop();
    }
    return str;
}


#endif // LL1_LL1_HPP_
