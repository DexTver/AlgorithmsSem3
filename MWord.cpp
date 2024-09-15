#include <iostream>

#ifdef LOCAL
    bool loc = true;
#else
    bool loc = false;
#endif

void scan_set(unsigned short t) {
    char x;
    do {
        x = (char) getc(stdin);
        if ('0' <= x && x <= '9') {
            t |= 1 << (int) (x - '0');
        }
    } while (x != '\n');
}

int main() {
    unsigned short a = 0, b = 0, c = 0, d = 0, e;

    // scan
    if (loc) printf("A: ");
    scan_set(a);
    if (loc) printf("B: ");
    scan_set(b);
    if (loc) printf("C: ");
    scan_set(c);
    if (loc) printf("D: ");
    scan_set(d);

    e = a & b | c | d;

    //print
    if (loc) printf("E: ");
    for (int i = 0; i < 10; ++i) {
        if ((e >> i) & 1) printf("%i ", i);
    }

    return 0;
}
