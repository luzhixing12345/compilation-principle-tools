/*
 *Copyright (c) 2022 All rights reserved
 *@description: LR0 grammar analysis
 *@author: Zhixing Lu
 *@date: 2022-06-05
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#ifndef LR0_SLR1_LR0_HPP_
#define LR0_SLR1_LR0_HPP_

#include "utils.hpp"

int lr0(RuleSet &rule_set);

Item augment(RuleSet &rule_set);


#endif // LR0_SLR1_LR0_HPP_
