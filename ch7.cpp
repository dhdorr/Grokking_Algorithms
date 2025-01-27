#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

const std::string folder_icon = "/"; 

bool is_file(std::string path) {
    if (path[0] == '/') {
        return false;
    }
    return true;
}


void print_names(std::string name, std::unordered_map<std::string, std::vector<std::string>> dir) {    
    for (std::string child : dir.find(name) -> second) {
        std::cout << "->" << name << std::endl;
        if (is_file(child)) {
            std::cout << child << std::endl;
        }
        else {
            print_names(child, dir);
        }
    }
}


int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph;
    graph.insert({"/root", {"alice.txt", "/claire"}});
    graph.insert({"bob.png", {"anuj.txt", "peggy.jpg"}});
    graph.insert({"alice.txt", {}});
    graph.insert({"/claire", {"/thom", "jonny.txt"}});
    graph.insert({"anuj", {}});
    graph.insert({"peggy", {}});
    graph.insert({"/thom", {"test.exe"}});
    graph.insert({"jonny", {}});

    std::string name = "/root";
    print_names(name, graph);
}