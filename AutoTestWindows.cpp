#include <cstdlib>
#include <chrono>
#include <iostream>
#include <fstream>

void out_print(const char name[]) {
    std::string line;
    std::ifstream file(name);
    getline(file, line);
    file.close();
    std::cout << line;
}

using namespace std::chrono;

int main() {
    // compile
    system("g++ ../Generator.cpp -o Generator");
    system("g++ ../Array.cpp -o Array");
    system("g++ ../List.cpp -o List");
    system("g++ ../Bits.cpp -o Bits");
    system("g++ ../MWord.cpp -o MWord");

    // running
    system("Generator > input.txt");

    std::cout << "Test:\n";
    std::ifstream file("input.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();

    auto start = high_resolution_clock::now();
    system("Array < input.txt > out_array.txt");
    auto stop = high_resolution_clock::now();
    std::cout << "Array result: ";
    out_print("out_array.txt");
    std::cout << "in " << duration_cast<microseconds>(stop - start).count() << " microseconds" << "\n";

    start = high_resolution_clock::now();
    system("List < input.txt > out_list.txt");
    stop = high_resolution_clock::now();
    std::cout << "List result:  ";
    out_print("out_list.txt");
    std::cout << "in " << duration_cast<microseconds>(stop - start).count() << " microseconds" << "\n";

    start = high_resolution_clock::now();
    system("Bits < input.txt > out_bits.txt");
    stop = high_resolution_clock::now();
    std::cout << "Bits result:  ";
    out_print("out_bits.txt");
    std::cout << "in " << duration_cast<microseconds>(stop - start).count() << " microseconds" << "\n";

    start = high_resolution_clock::now();
    system("MWord < input.txt > out_mword.txt");
    stop = high_resolution_clock::now();
    std::cout << "MWord result: ";
    out_print("out_mword.txt");
    std::cout << "in " << duration_cast<microseconds>(stop - start).count() << " microseconds" << "\n";

    return 0;
}
