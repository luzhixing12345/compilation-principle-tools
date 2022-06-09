/*
 *Copyright (c) 2022 All rights reserved
 *@description: graph to dot file
 *@author: Zhixing Lu
 *@date: 2022-06-10
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#pragma once
#ifndef LR0_SLR1_GRAPH2DOT_HPPPP_
#define LR0_SLR1_GRAPH2DOT_HPPPP_

#include "utils.hpp"
#include "../utils.hpp"

void graph2dot(Graph &graph, std::string filename) {
    std::ofstream outfile(filename);
    std::string head = "digraph G {\n";
    std::string tail = "}";
    std::string content;

    // analyze graph into dot file

    outfile << head << content << tail;
    outfile.close();
    std::cout << "write graph to " << filename << " successfully" << std::endl;
}



#endif // LR0_SLR1_GRAPH2DOT_HPPPP_
