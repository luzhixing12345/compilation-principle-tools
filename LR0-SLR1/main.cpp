/*
 *Copyright (c) 2022 All rights reserved
 *@description: main function for LR0 grammar analysis and SLR1 grammar analysis
 *@author: Zhixing Lu
 *@date: 2022-06-05
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#include "LR0.h"
#include "SLR1.h"
#include "../utils.h"




int main(int argc, char *argv[]) {
    std::vector<std::string> grammar_lines;
    int read_signal = read_grammar_lines(argc, argv, grammar_lines);
    if (read_signal != SUCCESS) {
        std::cout << "read file "<< argv[1] << " unsuccessfully";
        return 0;
    }



    return 0;
}