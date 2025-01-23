#include <iostream>

int find_smallest(int data_array[], int &size) {
    int smallest = data_array[0];
    int smallest_index = 0;

    for (int i = 0; i < size; i++) {
        if (data_array[i] < smallest) {
            smallest_index = i;
            smallest = data_array[i];
        }
    }
    return smallest_index;
}

void selection_sort(int data_array[], int &size) {
    int length = 6;
    int* sorted_array = new int[size];
    for (int i = 0; i < size; i++) {
        sorted_array[i] = data_array[i];
    }

    for (int i = 0; i < size; i++) {
        int smallest_index = find_smallest(sorted_array, size);

        data_array[i] = sorted_array[smallest_index];
        sorted_array[smallest_index] = 999;
    }

}

int main() {
    int data_array[] = {1, 5, 2, 6, 3, 4, 8, 7};
    int length = sizeof(data_array) / sizeof(int);

    selection_sort(data_array, length);
    
    std::cout << "The sorted array: ";
    for (int i = 0; i < length; i++) {
        std::cout << data_array[i] << ", ";
    }
}