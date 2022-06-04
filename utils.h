/*
 *Copyright (c) 2022 All rights reserved
 *@description: utils for compilation principle
 *@author: Zhixing Lu
 *@date: 2022-05-23
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#ifndef TOOLS_UTILS_H_
#define TOOLS_UTILS_H_ 

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <stack>
#include <string>

#define INPUT_ERROR -1
#define SUCCESS 0
#define RUN_TIME_ERROR 1
#define EMPTY 'e'
#define TABLE_SIZE 15 // size of the table

static int read_grammar_lines(int argc, char *argv[], std::vector<std::string> &grammar_lines) {

    if (argc != 2) {
        std::cout << "Usage: main.exe grammar.txt" << std::endl;
        return INPUT_ERROR;
    }
    std::string grammar_file = argv[1];
    // read grammar file
    std::string line;
    std::ifstream grammar_file_stream;
    grammar_file_stream.open(grammar_file, std::ios::in);
    if (!grammar_file_stream.is_open()) {
        std::cout << "Error: cannot open grammar file" << std::endl;
        return RUN_TIME_ERROR;
    }
    while (std::getline(grammar_file_stream, line)) {
        if (line.empty()) {
            continue;
        }
        // remove the space in the line
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                line.erase(i, 1);
                i--;
            }
        }
        grammar_lines.push_back(line);
    }
    grammar_file_stream.close();
    // test
    // for (auto &line : grammar_lines) {
    //     std::cout << line << std::endl;
    // }
    return SUCCESS;
}

static void signalCheck(int signal, std::string checkItemDescription) {
    for (int i = 0; i <= 20 ; i++) std::cout << "-";
    std::cout << std::endl;

    if (signal == SUCCESS) {
        std::cout << "SUCCESS to calculate " << checkItemDescription << std::endl;
    } else if (signal == RUN_TIME_ERROR) {
        std::cout << "RUN_TIME_ERROR" << std::endl;
    } else if (signal == INPUT_ERROR) {
        std::cout << "INPUT_ERROR" << std::endl;
    } else {
        std::cout << "STANGE ERROR ???" << std::endl;
    }

    for (int i = 0; i <= 20 ; i++) std::cout << "-";
    std::cout << std::endl;
}

// pass by value instead of pointer to avoid recoverying stack
static std::string stackToString(std::stack<char> stk) {
    std::string str = "";
    while (!stk.empty()) {
        str.push_back(stk.top());
        stk.pop();
    }
    return str;
}


#endif  // TOOLS_UTILS_H_ 
