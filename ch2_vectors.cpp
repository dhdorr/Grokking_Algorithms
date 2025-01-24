#include <iostream>
#include <vector>


template <typename T> int find_smallest(const std::vector<T>& arr) {
    T smallest = arr[0];
    int smallest_index = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
            smallest_index = i;
        }
    }

    return smallest_index;
}

template <typename T> std::vector<T> selection_sort(std::vector<T> arr) {
    std::vector<T> sorted;

    while(!arr.empty()) {
        int smallest_index = find_smallest(arr);
        sorted.push_back(arr[smallest_index]);

        arr.erase(arr.begin() + smallest_index);
    }

    return sorted;
}

int main() {
    std::vector<int> arr = {1, 4, 2, 9, -1, 3, 7};
    std::vector<int> sorted = selection_sort(arr);

    std::cout << "Sorted array: ";
    for (int num : sorted) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;

    return 0;

}