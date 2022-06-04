/*
 *Copyright (c) 2022 All rights reserved
 *@description: DFA-NFA-RE grammar implementation
 *@author: Zhixing Lu
 *@date: 2022-05-29
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

# include "utils.h"
# include "DFA.h"
# include "NFA.h"
# include "RE.h"

int main(int argc, char *argv[]) {
    

    if (argc == 2) {
        std::string regular_expression = argv[1];
        std::cout << "using regular expression: " << regular_expression << std::endl;
        // analyse regular expression
        Graph nfa_graph;
        int signal = RE_analyasis(regular_expression, nfa_graph);
    } else {
        std::vector<std::string> grammar_lines;
        read_grammar_lines(argc, argv, grammar_lines);
        std::string FA_type = argv[2];
    }
    return 0;
}