/*
 *Copyright (c) 2022 All rights reserved
 *@description: LR0 grammar analysis
 *@author: Zhixing Lu
 *@date: 2022-06-05
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/


#include "LR0.hpp"

int lr0(RuleSet &rule_set) {

    Graph graph = Graph();
    Item argument_item = augmentGrammar(rule_set); // calculate the augmented item (S' -> S)
    graph.createNewClosure(argument_item); // create the first closure

    return SUCCESS;
}

Item augmentGrammar(RuleSet &rule_set) {

    // by default, the first char in the first line of the grammar is BEGIN_SYMBOL
    char BEGIN_SYMBOL = rule_set.rules[0].first;
    Item item;
    item.left = BEGIN_SYMBOL; // the left part of the augmented item should be {BEGIN_SYMBO'} but char is not a string
    item.right = BEGIN_SYMBOL;
    item.dot_pos = 0;
    return item;
}
