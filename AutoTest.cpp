#include <cstdlib>
#include <chrono>
#include <iostream>
#include <fstream>

using namespace std;

void out_print(const char name[]) {
    string line;
    ifstream file(name);
    getline(file, line);
    file.close();
    cout << line;
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

    // running
    for (int i = 1; i <= 11; ++i) {
        if (i < 11) system(format("Generator {} > input.txt", i).c_str());
        else system("Generator > input.txt");

        cout << "Test " << i << ":\n";
        ifstream file("input.txt");
        string line;
        while (getline(file, line)) {
            cout << line << "\n";
        }
        file.close();

        system("Array < input.txt > out_array.txt");
        cout << "Array result: ";
        out_print("out_array.txt");

        system("List < input.txt > out_list.txt");
        cout << "\nList result:  ";
        out_print("out_list.txt");

        system("Bits < input.txt > out_bits.txt");
        cout << "\nBits result:  ";
        out_print("out_bits.txt");

        system("MWord < input.txt > out_mword.txt");
        cout << "\nMWord result: ";
        out_print("out_mword.txt");
        cout << "\n\n";
    }

    return 0;
}
