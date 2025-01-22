#include "iostream"

void binarySearch(int[], int, int);

int main() {
    int data_array[] = {2, 10, 11, 23, 44, 66, 100, 121};
    int length = sizeof(data_array) / sizeof(int);

    binarySearch(data_array, 3, length);
    binarySearch(data_array, 2, length);
    binarySearch(data_array, 44, length);

    return 0;
}

void binarySearch(int data_array[], int element, int len) {
    int low = 0;
    int high = len;
    while (low <= high) {
        int mid = (low + high) / 2;
        int guess = data_array[mid];

        if (guess == element) {
            std::cout << "Element found at index: " << mid << std::endl;
            return ;
        }
        else if (guess > element) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    std::cout << "Element not found" << std::endl;
    return ;
}