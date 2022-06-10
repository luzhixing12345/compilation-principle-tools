/*
 *Copyright (c) 2022 All rights reserved
 *@description: main function to compile
 *@author: Zhixing Lu
 *@date: 2022-05-21
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

# include "FFS_set.hpp"


void showFFS(FFS_set &ffs_set) {

    for (int i = 0; i <= 20 ; i++) std::cout << "-";
    std::cout << std::endl;
    std::cout << "FIRST SET: "<<std::endl;
    for (auto &it : ffs_set.first_set) {
        std::cout << it.first << ": ";
        for (auto &i : it.second) {
            std:: cout<< i << " ";
        }
        std::cout<<std::endl;
    }
    for (int i = 0; i <= 20 ; i++) std::cout << "-";
    std::cout << std::endl;
    std::cout << "FOLLOW SET: "<<std::endl;
    for (auto &it : ffs_set.follow_set) {
        std::cout << it.first << ": ";
        for (auto &i : it.second) {
            std:: cout<< i << " ";
        }
        std::cout<<std::endl;
    }
    for (int i = 0; i <= 20 ; i++) std::cout << "-";
    std::cout << std::endl;
    std::cout << "SELECT SET: "<<std::endl;
    for (auto &it : ffs_set.select_set) {
        std::string production = ruleToString(it.first);
        std::cout << std::left << std::setw(10) << production << ": ";
        for (auto &i : it.second) {
            std:: cout<< i << " ";
        }
        std::cout<<std::endl;
    }
}

int main(int argc, char *argv[]) {

    FFS_set ffs_set;
    std::vector<std::string> grammar_lines;
    int read_signal = read_grammar_lines(argc, argv, grammar_lines);
    if (read_signal != SUCCESS) {
        std::cout << "read file "<< argv[1] << " unsuccessfully";
        return 0;
    }
    RuleSet rule_set;
    int signal = ffs(grammar_lines, ffs_set, rule_set);
    
    signalCheck(signal, "ffs set");
    
    showFFS(ffs_set);
    return 0;

}
