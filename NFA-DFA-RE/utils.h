/*
 *Copyright (c) 2022 All rights reserved
 *@description: utils for DFA-NFA-RE grammar implementation
 *@author: Zhixing Lu
 *@date: 2022-05-29
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#ifndef NFA_DFA_RE_UTILS_HPP_
#define NFA_DFA_RE_UTILS_HPP_
#define DOT_FILE_NAME "grammar.dot"
#define PNG_FILE_NAME "result.png"

#include "../utils.hpp"

class Node {
public:
    explicit Node(int status_id) : state_id(status_id) {};

private:
    bool visited = false;
    int state_id;
};

class Graph {
public:
    Graph() = default;
    ~Graph() = default;
    void addEdge(int start, int end);
    void addNode(int state_id);
private:
    std::vector<std::vector<char>> edges;
    std::vector<Node> nodes;
};


int write_dot_file(const std::string &dot_file_name, const std::string &dot_file_content);



#endif // NFA_DFA_RE_UTILS_HPP_
