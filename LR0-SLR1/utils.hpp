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

#include "../utils.hpp"


struct Item {
    char left;
    int dot_pos;
    std::string right;
};

class Closure {
public:
    Closure(){};
    Closure(int state_num, Item &item) {
        this -> state_num = state_num;
        this -> items.push_back(item);
    }
    ~Closure();
    void calculateClosure(RuleSet &rule_set);
    void printClosure();
    std::vector<Item> getClosure();
private:
    bool SR_collapse; // shift reduce collapse
    bool RR_collapse; // reduce reduce collapse
    int state_num;
    std::vector<Item> items;
    std::vector<int> shift_items;
    std::vector<int> reduce_items;

    std::vector<std::pair<char,Closure*>> goto_table;

};

class Graph {
public:
    Graph(){
        this -> state_num = 0;
        this -> start_symbol = "START";
    };
    ~Graph();
    void createNewClosure(Item &item){
        Closure clouse = Closure(this->state_num, item);
        this -> state_num++;
    };
private:
    int state_num;
    std::string start_symbol;
    std::vector<Closure> closures;
};


#endif // LR0_SLR1_UTILS_HPP_
