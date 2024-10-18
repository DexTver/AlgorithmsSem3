#include <iostream>
#include <chrono>

#ifdef LOCAL
    bool loc = true;
#else
    bool loc = false;
#endif

using namespace std;

const int U = 10;

void scan_set(bool t[U]) {
    char x;
    do {
        x = (char) getc(stdin);
        if ('0' <= x && x <= '9') {
            t[x - '0'] = true;
        }
    } while (x != '\n');
}

int main() {
    bool a[U]{}, b[U]{}, c[U]{}, d[U]{}, e[U]{};

    // scan
    if (loc) cout << "A: ";
    scan_set(a);
    if (loc) cout << "B: ";
    scan_set(b);
    if (loc) cout << "C: ";
    scan_set(c);
    if (loc) cout << "D: ";
    scan_set(d);

    auto start = chrono::high_resolution_clock::now();
    // e = a & b
    for (int i = 0; i < U; ++i) {
        e[i] = a[i] && b[i];
    }

    // e |= c
    for (int i = 0; i < U; ++i) {
        e[i] = e[i] || c[i];
    }

    // e |= d
    for (int i = 0; i < U; ++i) {
        e[i] = e[i] || d[i];
    }
    auto stop = chrono::high_resolution_clock::now();

    // print
    if (loc) cout << "E: ";
    for (int i = 0; i < U; ++i) {
        if (e[i]) cout << i << " ";
    }
    cout << "in " << chrono::duration_cast<chrono::nanoseconds>(stop - start).count() << " nanoseconds";

    return 0;
}
