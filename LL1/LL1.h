/*
 *Copyright (c) 2022 All rights reserved
 *@description: defination for LL1 grammar
 *@author: Zhixing Lu
 *@date: 2022-05-23
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#ifndef LL1_LL1_H_
#define LL1_LL1_H_


# include "../FIRST-FOLLOW-SELECT/FFS_set.h"
# include "../utils.h"
# define LL1_DEDUCTION std::vector<ACTION>

struct ACTION
{
    std::string residual_string;
    std::string analysis_stack;
    Rule analysis_action;
};


int LL1_analyasis(std::string &input_str, 
                  char start_symbol,
                  RuleSet &rule_set,
                  SELECT_SET &select_set, 
                  LL1_DEDUCTION &ll1_deduction);

bool showLL1analysisTable(RuleSet &rule_set, SELECT_SET &select_set, std::unordered_map<std::string, Rule> &table_map);




#endif // LL1_LL1_H_
