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

    // running
    for (int i = 1; i <= 11; ++i) {
        switch (i) {
            case 1:
                system("Generator 1 > input.txt");
                break;
            case 2:
                system("Generator 2 > input.txt");
                break;
            case 3:
                system("Generator 3 > input.txt");
                break;
            case 4:
                system("Generator 4 > input.txt");
                break;
            case 5:
                system("Generator 5 > input.txt");
                break;
            case 6:
                system("Generator 6 > input.txt");
                break;
            case 7:
                system("Generator 7 > input.txt");
                break;
            case 8:
                system("Generator 8 > input.txt");
                break;
            case 9:
                system("Generator 9 > input.txt");
                break;
            case 10:
                system("Generator 10 > input.txt");
                break;
            default:
                system("Generator > input.txt");
                break;
        }
//        system(std::format("Generator {} > input.txt", i));

        std::cout << "\nTest " << i << ":\n";
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
    }

    return 0;
}
