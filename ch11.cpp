#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>


void print_matrix(std::vector<std::vector<int>> table) {
    // print matrix
    for (auto r : table) {
        for (auto c : r) {
            std::cout << c << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


void find_longest_substring(std::vector<std::string> a, std::vector<std::string> b, std::vector<std::vector<int>> table) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (b[j] == a[i]) {
                if (i - 1 < 0 || j - 1 < 0) {
                    table[i][j] = 1;    // safety first
                } else {
                    table[i][j] = table[i-1][j-1] + 1;
                }
            } else {
                table[i][j] = 0;
            }
        }
    }

    print_matrix(table);
}


int max(int a, int b) {
    if (a > b) {
        return a;
    } else if (b > a) {
        return b;
    }

    return a;
}


void find_longest_subsequence(std::vector<std::string> a, std::vector<std::string> b, std::vector<std::vector<int>> table) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (b[j] == a[i]) {
                if (i - 1 < 0 || j - 1 < 0) {
                    table[i][j] = 1;    // safety first
                } else {
                    table[i][j] = table[i-1][j-1] + 1;
                }
            } else {
                int local_max = 0;
                if (i - 1 < 0 && j - 1 >= 0) {
                    local_max = max(0, table[i][j-1]);
                } else if (i - 1 < 0 && j - 1 < 0) {
                    local_max = max(0, 0);
                } else if (i - 1 >= 0 && j - 1 < 0) {
                    local_max = max(table[i-1][j], 0);
                } else {
                    local_max = max(table[i-1][j], table[i][j-1]);
                }
                table[i][j] = local_max;
            }
        }
    }
    
    print_matrix(table);
}

int main() {
    std::vector<std::string> blue_vec = {"f", "o", "s", "h"};
    std::vector<std::string> clues_vec = {"f", "i", "s", "h"};
    std::vector<std::vector<int>> substring_table;

    // create the dynamic programming matrix
    for (int i = 0; i < blue_vec.size(); i++) {
        substring_table.push_back({});
        for (int j = 0; j < clues_vec.size(); j++) {
            substring_table[i].push_back(0);
        }
    }

    find_longest_substring(blue_vec, clues_vec, substring_table);
    find_longest_subsequence(blue_vec, clues_vec, substring_table);

    return 0;
}