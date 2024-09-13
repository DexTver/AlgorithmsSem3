#include <iostream>
#include <algorithm>
#include <random>
#include <fstream>

void generator(char a[], int &len) {
    std::mt19937 rnd(std::random_device{}());
    len = std::uniform_int_distribution<int>(1, 10)(rnd);

    char digits[10];
    for (char i = '0'; i <= '9'; ++i) {
        digits[i - '0'] = i;
    }

    for (int i = 0; i < len; ++i) {
        if (std::uniform_int_distribution<int>(0, 1)(rnd)) {
            a[i] = digits[i];
        } else {
            a[i] = '\0';
        }
    }
    std::shuffle(a, a + len, rnd);
}

int main() {
    for (int i = 0; i < 4; ++i) {
        char a[10];
        int len = 0;
        generator(a, len);

        for (int j = 0; j < len; ++j) {
            if (a[j] != '\0') {
                std::cout << a[j] << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}
