#include <cstdlib>

int main() {
    // compile
    system("g++ ../Generator.cpp -o Generator");
    system("g++ ../Array.cpp -o Array");
    system("g++ ../List.cpp -o List");
    system("g++ ../Bits.cpp -o Bits");
    system("g++ ../MWord.cpp -o MWord");

    // running
    system("./Generator > input.txt");
    system("./Array < input.txt > out_array.txt");
    system("./List < input.txt > out_list.txt");
    system("./Bits < input.txt > out_bits.txt");
    system("./MWord < input.txt > out_mword.txt");

    return 0;
}
