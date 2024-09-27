#include <bits/stdc++.h>

void out_print(const char name[]) {
    std::string line;
    std::ifstream file(name);
    getline(file, line);
    file.close();
    std::cout << line;
}

int main() {

    // compile
#ifdef LOCAL
    system("g++ ../Generator.cpp -o Generator");
    system("g++ ../Array.cpp -o Array");
    system("g++ ../List.cpp -o List");
    system("g++ ../Bits.cpp -o Bits");
    system("g++ ../MWord.cpp -o MWord");
#else
    system("g++ Generator.cpp -o Generator");
    system("g++ Array.cpp -o Array");
    system("g++ List.cpp -o List");
    system("g++ Bits.cpp -o Bits");
    system("g++ MWord.cpp -o MWord");
#endif
    freopen("../logs.txt", "w", stdout);
    // running
    for (int tt = 0; tt < 100; ++tt) {
        for (int i = 1; i <= 10; ++i) {
            if (i < 11) system(std::format("Generator {} > input.txt", i).c_str());
            else system("Generator > input.txt");

            system("Array < input.txt > out_array.txt");
            std::cout << i << "\n";
            std::cout << "Array result: ";
            out_print("out_array.txt");

            system("List < input.txt > out_list.txt");
            std::cout << "\nList result:  ";
            out_print("out_list.txt");

            system("Bits < input.txt > out_bits.txt");
            std::cout << "\nBits result:  ";
            out_print("out_bits.txt");

            system("MWord < input.txt > out_mword.txt");
            std::cout << "\nMWord result: ";
            out_print("out_mword.txt");
            std::cout << "\n";
        }
    }
    return 0;
}
