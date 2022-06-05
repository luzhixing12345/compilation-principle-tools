/*
 *Copyright (c) 2022 All rights reserved
 *@description: basic data structure for LR0 and SLR1
 *@author: Zhixing Lu
 *@date: 2022-06-05
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/


#ifndef LR0_SLR1_UTILS_H_
#define LR0_SLR1_UTILS_H_

#include <iostream>
#include <vector>

struct Item {
    char left;
    int dot_pos;
    std::string right;
};

struct Closure {
    bool SR_collapse; // shift reduce collapse
    bool RR_collapse; // reduce reduce collapse
    int state_num;
    std::vector<Item> items;
    std::vector<int> shift_items;
    std::vector<int> reduce_items;

    std::vector<std::pair<char,Closure*>> goto_table;
};





#endif // LR0_SLR1_UTILS_H_
