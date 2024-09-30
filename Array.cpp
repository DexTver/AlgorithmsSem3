#include <iostream>
#include <chrono>

#ifdef LOCAL
    bool loc = true;
#else
    bool loc = false;
#endif

using namespace std;

const int U = 10;

void scan_set(char t[U + 1]) {
    char x;
    int cnt = 0;
    do {
        x = (char) getc(stdin);
        if ('0' <= x && x <= '9') {
            bool found = false;
            for (int i = 0; i < cnt; ++i) {
                if (t[i] == x) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                t[cnt++] = x;
            }
        }
    } while (x != '\n');
}

int main() {
    char a[U + 1]{}, b[U + 1]{}, c[U + 1]{}, d[U + 1]{}, e[U + 1]{};
    int cnt_e = 0;

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
    // removing repetitions
    for (int i = 0; i <= U; ++i) {
        for (int j = i + 1; j <= U; ++j) {
            if (a[i] == a[j]) a[j] = '\000';
        }
    }

    // e = a & b
    for (char i: a) {
        for (char j: b) {
            if (i == j && i != '\000') {
                e[cnt_e++] = i;
            }
        }
    }

    // e |= c
    for (char i: c) {
        if (i != '\000') {
            bool found = false;
            for (int j = 0; j < cnt_e; ++j) {
                if (e[j] == i) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                e[cnt_e++] = i;
            }
        }
    }

    // e |= d
    for (char i: d) {
        if (i != '\000') {
            bool found = false;
            for (int j = 0; j < cnt_e; ++j) {
                if (e[j] == i) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                e[cnt_e++] = i;
            }
        }
    }
    auto stop = chrono::high_resolution_clock::now();

    // print
    if (loc) cout << "E: ";
    for (int i = 0; i < cnt_e; ++i) {
        cout << e[i] << " ";
    }
    cout << "in " << chrono::duration_cast<chrono::nanoseconds>(stop - start).count() << " nanoseconds";

    return 0;
}
