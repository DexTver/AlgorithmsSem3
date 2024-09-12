#include <iostream>

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

    printf("A: ");
    a = scan_set();
    printf("B: ");
    b = scan_set();
    printf("C: ");
    c = scan_set();
    printf("D: ");
    d = scan_set();

    e = a & b | c | d;
    printf("E: ");
    for (int i = 0; i < 10; ++i) {
        if ((e >> i) & 1) printf("%i ", i);
    }

    return 0;
}
