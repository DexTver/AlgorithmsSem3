#include <iostream>
#include <algorithm>
#include <random>

#ifdef LOCAL
    bool loc = true;
#else
    bool loc = false;
#endif

void generator(char a[], int &len) {
    std::mt19937 rnd(std::random_device{}());
    len = std::uniform_int_distribution(1, 10)(rnd);

    char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (int i = 0; i < len; ++i) {
        if (std::uniform_int_distribution<int>(0, 1)(rnd)) {
            a[i] = digits[i];
        } else {
            a[i] = '\0';
        }
    }

    std::shuffle(a, a + len, rnd);
}

void generatorWithFixedLen(char a[], int len) {
    std::mt19937 rnd(std::random_device{}());

    char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (int i = 9; i > 0; --i) {
        int j = std::uniform_int_distribution<int>(0, i)(rnd);
        std::swap(digits[i], digits[j]);
    }

    for (int i = 0; i < len; ++i) {
        a[i] = digits[i];
    }
}

int main(int argc, char *argv[]) {
    int len = 0;
    if (loc) {
        std::cout << "Enter length of generated sets (from 0 to 10):\n";
        std::cin >> len;
    } else {
        if (argc > 1) {
            len = std::atoi(argv[1]);
        }
    }
    for (int i = 0; i < 4; ++i) {
        char a[10];
        if (!loc && argc <= 1) {
            generator(a, len);
        } else {
            generatorWithFixedLen(a, len);
        }

        for (int j = 0; j < len; ++j) {
            if (a[j] != '\0') {
                std::cout << a[j] << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}
