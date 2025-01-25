#include <iostream>
#include <vector>


template <typename T> T sum(std::vector<T>& arr) {
    T front_element = arr.back();
    arr.pop_back();

    if (arr.size() == 0) {
        return front_element;
    }

    return front_element + sum(arr);
}


template <typename T> T count(std::vector<T>& arr) {
    if (arr.empty()) {
        return 0;
    }

    arr.pop_back();  

    return count(arr) + 1;
}


template <typename T> T maximum(std::vector<T>& arr, T current_max) {
    if (arr.empty()) {
        return current_max;
    }

    if (arr.back() >= current_max) {
        current_max = arr.back();
    }

    arr.pop_back();

    return maximum(arr, current_max);
}

template <typename T> T maximum2(std::vector<T>& arr) {
    if (arr.size() == 1) {
        return arr.front();
    }

    T last_element = arr.back();
    arr.pop_back();

    T testme = maximum2(arr);
    
    if (testme > last_element) {
        return testme;
    } else {
        return last_element;
    }
}


template <typename T> std::vector<T> quick_sort(std::vector<T>& sub_arr) {
    if (sub_arr.size() < 2) {
        return sub_arr;
    }

    T pivot = sub_arr[0];
    std::vector<T> lesser;
    std::vector<T> greater;

    for (int i = 1; i < sub_arr.size(); i++) {
        if (sub_arr[i] > pivot) {
            greater.push_back(sub_arr[i]);
        } else if (sub_arr[i] <= pivot) {
            lesser.push_back(sub_arr[i]);
        }
    }
    
    std::vector<T> lesser_sorted = quick_sort(lesser);
    std::vector<T> greater_sorted = quick_sort(greater);

    std::vector<T> sorted;
    sorted.insert(sorted.begin(), lesser_sorted.begin(), lesser_sorted.end());
    sorted.insert(sorted.end(), pivot);
    sorted.insert(sorted.end(), greater_sorted.begin(), greater_sorted.end());

    return sorted;
}

template <typename T> std::vector<T> quick_sort_improved(std::vector<T>& sub_arr) {
    if (sub_arr.size() < 2) {
        return sub_arr;
    }

    T* pivot = &sub_arr.front() + sub_arr.size() / 2 - 1;
    std::vector<T> lesser;
    std::vector<T> greater;

    for (const T* item = &sub_arr.front(); item <= &sub_arr.back(); item++) {
        if (item == pivot) {
            continue;
        }
        if (*item > *pivot) {
            greater.push_back(*item);
        } else if (*item <= *pivot) {
            lesser.push_back(*item);
        }
    }
    
    std::vector<T> lesser_sorted = quick_sort(lesser);
    std::vector<T> greater_sorted = quick_sort(greater);

    std::vector<T> sorted;
    sorted.insert(sorted.begin(), lesser_sorted.begin(), lesser_sorted.end());
    sorted.insert(sorted.end(), *pivot);
    sorted.insert(sorted.end(), greater_sorted.begin(), greater_sorted.end());

    return sorted;
}


int main() {
    // SUM
    std::vector<int> arr_int = {1, 2, 3, 4};
    std::vector<float> arr_float = {0.1, 0.2, 0.3, 0.4};

    std::cout << "int answer: " << sum(arr_int) << std::endl;
    std::cout << "float answer: " << sum(arr_float) << std::endl;

    // COUNT
    std::vector<int> arr_int2 = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<float> arr_float2 = {0.1, 0.2, 0.3, 0.4};

    std::cout << "count int: " << count(arr_int2) << std:: endl;
    std::cout << "count float: " << count(arr_float2) << std::endl;

    // MAXIMUM
    std::vector<int> arr_int3 = {1, 5, 3, 4, 2, 6, 0, 1, 2};
    std::cout << "max int: " << maximum(arr_int3, arr_int3[0]) << std:: endl;
    std::vector<int> arr_int30 = {1, 5, 3, 4, 2, 6, 0, 2, 7, 1, 4};
    std::cout << "max int2: " << maximum2(arr_int30) << std:: endl;

    // QUICK SORT
    std::vector<int> arr_int_qs = {1, 5, 3, 4, 2, 6, 0, 2, 7, 1, 4};
    std::vector<int> sorted = quick_sort(arr_int_qs);
    std::cout << "quick sort ints: ";
    for (int i : sorted) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    std::vector<int> arr_int_qs_2 = {69, 60, 38, 82, 99, 15, 8, 94, 30, 42, 35, 40, 63, 1, 49, 66, 93, 83, 20, 32, 87, 6, 78, 17, 2, 61, 91, 25, 7, 4, 97, 31, 23, 67, 95, 47, 55, 92, 37, 59, 73, 81, 74, 41, 39};
    std::vector<int> sorted_2 = quick_sort_improved(arr_int_qs_2);
    std::cout << "quick sort ints 2: ";
    for (int i : sorted_2) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}