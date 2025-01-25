#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, bool> voted;

void price_of_groceries() {
    std::unordered_map<std::string, float> book = {
        {"apple", 0.6},
        {"amiibo", 2.50},
        {"banana", 1.50}
    };

    for (std::pair<std::string, float> pair : book) {
        std::cout << pair.first << ": " << pair.second << "$" << std::endl;
    }
}

void check_voter(const std::string& name) {
    auto search = voted.find(name);
    if (search == voted.end() || search->second == false) {
        voted.insert({name, true});
        std::cout << "Let them vote!" << std::endl;
        
    } else {
        std::cout << "Kick them out!" << std::endl;
    }
}

int main() {
    price_of_groceries();

    check_voter("derek");
    check_voter("bob");
    check_voter("cortana");
    check_voter("cortana");

    return 0;
}