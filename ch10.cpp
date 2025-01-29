#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>


std::unordered_set<std::string> set_intersection(const std::unordered_set<std::string>& a, const std::unordered_set<std::string>& b) {
    std::unordered_set<std::string> result;

    for (const auto& i : a) {
        for (const auto& j : b) {
            if (i == j) {
                result.insert(i);
            }
        }
    }

    return result;
}


void operator -= (std::unordered_set<std::string>& a,
		  const std::unordered_set<std::string>& b) {
	for (auto j = b.begin(); j != b.end(); ++j)
		for (auto i = a.begin(); i != a.end(); )
			if (*i == *j) i = a.erase(i);
			else ++i;
 }


int main() {
    std::unordered_set<std::string> states_needed({ "mt", "wa", "or", "id", "nv", "ut", "ca", "az" });

    std::unordered_map<std::string, std::unordered_set<std::string>> stations;
    stations.insert({ "kone", {"id", "nv", "ut"} });
	stations.insert({ "ktwo", {"wa", "id", "mt" } });
	stations.insert({ "kthree", {"or", "nv", "ca" } });
	stations.insert({ "kfour", {"nv", "ut" } });
	stations.insert({ "kfive", {"ca", "az" } });

    std::unordered_set<std::string> final_stations;

    while (!states_needed.empty())
    {
        std::string best_station;
        std::unordered_set<std::string> states_covered;

        for (const auto& i : stations) {
            std::unordered_set<std::string> coverage = set_intersection(i.second, states_needed);

            if (coverage.size() > states_covered.size()) {
                best_station = i.first;
                states_covered = coverage;
            }
        }

        states_needed -= states_covered;
        std::cout << "best station" << best_station << std::endl;
        final_stations.insert(best_station);
    }

    for (const auto& i : final_stations) {
            std::cout << i << std::endl;
    }

    return 0;
}