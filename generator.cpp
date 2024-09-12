#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>


void generator(std::vector<char> &a) {
    std::mt19937 rnd(std::random_device{}());
    int len = std::uniform_int_distribution<int>(1, 10)(rnd);

    std::vector<char> digits;
    for (char i = '0'; i <= '9'; ++i) {
        digits.push_back(i);
    }

    std::shuffle(digits.begin(), digits.end(), rnd);
    a.assign(digits.begin(), digits.begin() + len);
}

int main() {
    std::ofstream f("test.txt");

    for (int i = 0; i < 4; ++i) {
        std::vector<char> a;
        generator(a);

        for (char j : a) {
            f << j << " ";
        }
        f << "\n";
    }

    return 0;
}
