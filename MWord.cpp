#include <iostream>
#include <chrono>

#ifdef LOCAL
    bool loc = true;
#else
    bool loc = false;
#endif

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
    if (loc) printf("A: ");
    a = scan_set();
    if (loc) printf("B: ");
    b = scan_set();
    if (loc) printf("C: ");
    c = scan_set();
    if (loc) printf("D: ");
    d = scan_set();

    auto start = std::chrono::high_resolution_clock::now();
    e = a & b | c | d;
    auto stop = std::chrono::high_resolution_clock::now();

    //print
    if (loc) printf("E: ");
    for (int i = 0; i < 10; ++i) {
        if ((e >> i) & 1) printf("%i ", i);
    }
    printf("in %lli nanoseconds", std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());

    return 0;
}
