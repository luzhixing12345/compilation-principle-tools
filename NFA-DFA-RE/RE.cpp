/*
 *Copyright (c) 2022 All rights reserved
 *@description: anlayze regular expression
 *@author: Zhixing Lu
 *@date: 2022-05-30
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

# include "RE.h"

int RE_analyasis(const std::string &regular_expression, Graph &nfa_graph) {

    int pos = 0;
    while (pos != regular_expression.size()) {
        if (regular_expression[pos] == LEFT_BRACKET) {
            int position_start = pos;
            int position_end = regular_expression.find(RIGHT_BRACKET, pos);
            if (position_end == std::string::npos) {
                std::cout << "error: lack of right bracket" << std::endl;
                return RUN_TIME_ERROR;
            } else {
                std::string sub_regular_expression = regular_expression.substr(position_start + 1, position_end - position_start - 1);
                int signal = RE_analyasis(sub_regular_expression, nfa_graph);
                if (signal != SUCCESS) {
                    return signal;
                }
            }
        } else if (regular_expression[pos] == OR) {
            int position_start = pos;
            int position_end = pos + 1;
            std::string sub_regular_expression = regular_expression.substr(position_start, position_end - position_start);
            int signal = RE_analyasis(sub_regular_expression, nfa_graph);
            if (signal != SUCCESS) {
                return signal;
            }
        } else if (regular_expression[pos] == STAR) {
            int position_start = pos;
            int position_end = pos + 1;
            std::string sub_regular_expression = regular_expression.substr(position_start, position_end - position_start);
            int signal = RE_analyasis(sub_regular_expression, nfa_graph);
            if (signal != SUCCESS) {
                return signal;
            }
        } else {
            int position_start = pos;
            int position_end = pos + 1;
            std::string sub_regular_expression = regular_expression.substr(position_start, position_end - position_start);
            int signal = NFA_analyasis(sub_regular_expression, nfa_graph);
            if (signal != SUCCESS) {
                return signal;
            }
        }
    }
}
