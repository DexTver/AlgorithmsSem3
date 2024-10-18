#include <iostream>
#include <chrono>

#ifdef LOCAL
    bool loc = true;
#else
    bool loc = false;
#endif

using namespace std;

unsigned short scan_set() {
    unsigned short t = 0;
    char x;
    do {
        x = (char) getc(stdin);
        if ('0' <= x && x <= '9') {
            t |= 1 << (int) (x - '0');
        }
    } while (x != '\n');
    return t;
}

int main() {
    unsigned short a = 0, b = 0, c = 0, d = 0, e;

    // scan
    if (loc) cout << "A: ";
    a = scan_set();
    if (loc) cout << "B: ";
    b = scan_set();
    if (loc) cout << "C: ";
    c = scan_set();
    if (loc) cout << "D: ";
    d = scan_set();

    auto start = chrono::high_resolution_clock::now();
    e = a & b | c | d;
    auto stop = chrono::high_resolution_clock::now();

    //print
    if (loc) cout << "E: ";
    for (int i = 0; i < 10; ++i) {
        if ((e >> i) & 1) cout << i << " ";
    }
    cout << "in " << chrono::duration_cast<chrono::nanoseconds>(stop - start).count() << " nanoseconds";

    return 0;
}
