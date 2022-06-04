/*
 *Copyright (c) 2022 All rights reserved
 *@description: anlayze regular expression
 *@author: Zhixing Lu
 *@date: 2022-05-30
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#ifndef TOOLS_NFA_DFA_RE_RE_H_
#define TOOLS_NFA_DFA_RE_RE_H_

#define LEFT_BRACKET '('
#define RIGHT_BRACKET ')'
#define OR '|'
#define STAR '*'


# include "utils.h"

int RE_analyasis(const std::string &regular_expression, Graph &nfa_graph);



#endif // TOOLS_NFA_DFA_RE_RE_H_
