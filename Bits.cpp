#include <iostream>
#include <chrono>

#ifdef LOCAL
    bool loc = true;
#else
    bool loc = false;
#endif

void scan_set(bool t[10]) {
    char x;
    do {
        x = (char) getc(stdin);
        if ('0' <= x && x <= '9') {
            t[x - '0'] = true;
        }
    } while (x != '\n');
}

int main() {
    bool a[10]{}, b[10]{}, c[10]{}, d[10]{}, e[10]{};

    // scan
    if (loc) printf("A: ");
    scan_set(a);
    if (loc) printf("B: ");
    scan_set(b);
    if (loc) printf("C: ");
    scan_set(c);
    if (loc) printf("D: ");
    scan_set(d);

    auto start = std::chrono::high_resolution_clock::now();
    // e = a & b
    for (int i = 0; i < 10; ++i) {
        e[i] = a[i] && b[i];
    }

    // e |= c
    for (int i = 0; i < 10; ++i) {
        e[i] = e[i] || c[i];
    }

    // e |= d
    for (int i = 0; i < 10; ++i) {
        e[i] = e[i] || d[i];
    }
    auto stop = std::chrono::high_resolution_clock::now();

    // print
    if (loc) printf("E: ");
    for (int i = 0; i < 10; ++i) {
        if (e[i]) printf("%i ", i);
    }
    printf("in %lli nanoseconds", std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());

    return 0;
}
