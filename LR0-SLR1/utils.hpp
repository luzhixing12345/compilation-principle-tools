/*
 *Copyright (c) 2022 All rights reserved
 *@description: basic data structure for LR0 and SLR1
 *@author: Zhixing Lu
 *@date: 2022-06-05
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/


#ifndef LR0_SLR1_UTILS_HPP_
#define LR0_SLR1_UTILS_HPP_

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

struct Graph {
    std::string start_symbol = "START";
    std::vector<Closure> closures;
};


#endif // LR0_SLR1_UTILS_HPP_
