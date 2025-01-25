#include <iostream>
#include <array>


int sum(int x[], int size) {
    if (size == 1) {
        return x[0];
    }

    int index = size - 1;
    return x[index] + sum(x, index);
}


int main() {
    int arr[] = {1};
    int answer = sum(arr, sizeof(arr) / sizeof(arr[0]));

    std::cout << "answer: " << answer << std::endl;

    int arr2[] = {1, 2, 3, 4};
    answer = sum(arr2, sizeof(arr2) / sizeof(arr2[0]));

    std::cout << "answer: " << answer << std::endl;
}