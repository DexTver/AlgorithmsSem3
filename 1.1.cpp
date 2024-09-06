#include <iostream>

ushort scan_set() {
    ushort t = 0;
    char x;
    do {
        x = getc(stdin);
        if ('0' <= x && x <= '9') {
            t |= 1 << (int) (x - '0');
        }
    } while (x != '\n');
    return t;
}

int main() {
    ushort a = 0, b = 0, c = 0, d = 0, e;
    char x;

    printf("A: ");
    a = scan_set();
    printf("\nB: ");
    b = scan_set();
    printf("\nC: ");
    c = scan_set();
    printf("\nD: ");
    d = scan_set();

    e = a & b | c | d;
    printf("\nE: ");
    for (int i = 0; i < 10; ++i) {
        if ((e >> i) & 1) printf("%i ", i);
    }

    return 0;
}
