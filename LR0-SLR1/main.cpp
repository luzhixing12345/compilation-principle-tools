/*
 *Copyright (c) 2022 All rights reserved
 *@description: main function for LR0 grammar analysis and SLR1 grammar analysis
 *@author: Zhixing Lu
 *@date: 2022-06-05
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#include "LR0.hpp"
#include "SLR1.hpp"
#include "../utils.hpp"
#include "../FIRST-FOLLOW-SELECT/FFS_set.hpp"



int main(int argc, char *argv[]) {
    std::vector<std::string> grammar_lines;
    int read_signal = read_grammar_lines(argc, argv, grammar_lines);
    if (read_signal != SUCCESS) {
        std::cout << "read file "<< argv[1] << " unsuccessfully";
        return 0;
    }

    FFS_set ffs_set;
    RuleSet rule_set;
    int signal = ffs(grammar_lines, ffs_set, rule_set);
    signalCheck(signal, "ffs set");

    // LR0 only needs rule_set
    signal = lr0(rule_set);
    signalCheck(signal, "lr0 set");

    // SLR1 needs rule_set and ffs_set
    signal = slr1(rule_set, ffs_set);
    signalCheck(signal, "slr1 set");

    return 0;
}