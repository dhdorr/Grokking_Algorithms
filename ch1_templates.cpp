#include <iostream>
#include <vector>

template <typename T> int binarySearch(const std::vector<T>& list, const T& item) {
    int low = 0;
    int high = list.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        T guess = list[mid];

        if (guess == item) {
            return mid;
        }
        else if (guess > item) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return -1;
}

// returns pointer to element rather than the index of the element
template <typename T> const T* binarySearch2(const std::vector<T>& list, const T& item) {
    const T* low = &list.front();
    const T* high = &list.back();

    while (low <= high) {
        const T* guess = low + ((high - low) / 2);

        if (*guess == item) {
            return guess;
        }
        if (*guess > item) {
            high = guess - 1;
        }
        else {
            low = guess + 1;
        }
    }

    return nullptr;
}

int main() {
    std::vector<int> my_list = {1, 2, 10, 11, 44, 66, 100, 121};
    const int* binarySearch2_result = binarySearch2(my_list, 44);
    const int* binarySearch2_null = binarySearch2(my_list, 4);

    std::cout << "Binary search for index of 10: " << binarySearch(my_list, 10) << std::endl;
    std::cout << "Binary search for pointer to 44: " << binarySearch2_result << " | " << *binarySearch2_result << std::endl;

    if (binarySearch2_null == nullptr) {
        std::cout << "4 was not found in the list" << std::endl;
    }

    return 0;
}