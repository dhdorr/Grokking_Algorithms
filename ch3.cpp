#include <iostream>

int factorial(int x) {
    if (x == 1) {
        return 1;
    } else {
        return x * factorial(x - 1);
    }
}

template <typename T> T factorial_generic(T x) {
    if (x == 1) {
        return 1;
    } else {
        return x * factorial(x - 1);
    }
}

int main() {
    int num = 5;
    double num2 = 5;
    int answer = factorial(num);
    double answer2 = factorial_generic(num2);

    std::cout << "!" << num << " = " << answer << std::endl;
    std::cout << "!" << num2 << " = " << answer2 << std::endl;
}