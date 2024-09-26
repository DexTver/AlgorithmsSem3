#include <iostream>
#include <chrono>

#ifdef LOCAL
    bool loc = true;
#else
    bool loc = false;
#endif

void scan_set(char t[11]) {
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
    char a[11]{}, b[11]{}, c[11]{}, d[11]{}, e[11]{};
    int cnt_e = 0;

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
    for (char i: a) {
        for (char j: b) {
            if (i == j && i != '\000') {
                bool found = false;
                for (int k = 0; k < cnt_e; ++k) {
                    if (e[k] == i) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    e[cnt_e++] = i;
                }
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
    auto stop = std::chrono::high_resolution_clock::now();

    // print
    if (loc) printf("E: ");
    for (int i = 0; i < cnt_e; ++i) {
        printf("%c ", e[i]);
    }
    printf("in %lli nanoseconds", std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());

    return 0;
}
