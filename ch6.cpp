#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>


bool is_seller(const std::string& name) {
    return name == "jonny";
}


template <typename T> bool search(const T& name, const std::unordered_map<T, std::vector<T>>& graph) {
    std::queue<T> search_queue;
    std::unordered_set<T> searched;

    for (auto&& friend_name : graph.find(name) -> second) {
        search_queue.push(friend_name);
    }
    
    while (!search_queue.empty()) {
        T& person = search_queue.front();
        search_queue.pop();

        if (searched.find(person) == searched.end()) {
            if (is_seller(person)) {
                std::cout << person << " is a seller!" << std::endl;
                return true;
            }

            for (auto&& friend_name : graph.find(person) -> second) {
                search_queue.push(friend_name);
            }

            searched.insert(person);
        }
    }

    return false;
}


int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph;
    graph.insert({"you", {"alice", "bob", "claire"}});
    graph.insert({"bob", {"anuj", "peggy"}});
    graph.insert({"alice", {"peggy"}});
    graph.insert({"claire", {"thom", "jonny"}});
    graph.insert({"anuj", {}});
    graph.insert({"peggy", {}});
    graph.insert({"thom", {}});
    graph.insert({"jonny", {}});

    std::string name = "you";
    bool result = search(name, graph);
    std::cout << "Found a seller: " << result << std::endl;
}