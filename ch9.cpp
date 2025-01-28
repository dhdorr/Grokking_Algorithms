#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <limits>


const int infinity = std::numeric_limits<int>::max();
const std::string None = "None";


std::string find_lowest_cost_node(std::unordered_map<std::string, int> costs, std::vector<std::string> processed) {
    int lowest_cost = infinity;
    std::string lowest_cost_node = None;

    for (auto node : costs) {
        int cost = node.second;
        bool is_processed = false;

        for (std::string n : processed) {
            if (n == node.first) {
                is_processed = true;
            }
        }

        if (cost < lowest_cost && !is_processed) {
            lowest_cost = cost;
            lowest_cost_node = node.first;
        }
    }

    return lowest_cost_node;
}


void dijkstra(std::unordered_map<std::string, std::unordered_map<std::string, int>>& graph,
                std::unordered_map<std::string, int>& costs,
                std::unordered_map<std::string, std::string>& parents,
                std::vector<std::string>& processed) {

    std::string node = find_lowest_cost_node(costs, processed);

    while (node != None)
    {
        int cost = costs.find(node)->second;

        std::unordered_map<std::string, int> neighbors = graph.find(node)->second;
        for (auto n : neighbors) {
            int new_cost = cost + neighbors.find(n.first)->second;

            if (costs.find(n.first)->second > new_cost) {
                costs.find(n.first)->second = new_cost;

                parents.find(n.first)->second = node;
            }
        }

        processed.push_back(node);

        node = find_lowest_cost_node(costs, processed);
    }
}


int main() {
    std::unordered_map<std::string, std::unordered_map<std::string, int>> graph;
    graph.insert({"start", {}});
    graph.find("start") -> second.insert({"a", 6});
    graph.find("start") -> second.insert({"b", 2});

    graph.insert({"a", {}});
    graph.find("a") -> second.insert({"fin", 1});

    graph.insert({"b", {}});
    graph.find("b") -> second.insert({"a", 3});
    graph.find("b") -> second.insert({"fin", 5});

    graph.insert({"fin", {}});

    std::unordered_map<std::string, int> costs;
    costs.insert({"a", 6});
    costs.insert({"b", 2});
    costs.insert({"fin", infinity});

    std::unordered_map<std::string, std::string> parents;
    parents.insert({"a", "start"});
    parents.insert({"b", "start"});
    parents.insert({"fin", None});

    std::vector<std::string> processed;

    dijkstra(graph, costs, parents, processed);

    std::cout << "Cost from the start to each node: " << std::endl;
    for (auto c : costs) {
        std::cout << c.first << " : " << c.second << std::endl;
    }

    return 0;
}