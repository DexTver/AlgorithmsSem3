#include <iostream>

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
            t[cnt++] = x;
        }
    } while (x != '\n');
}

int main() {
    char a[11]{}, b[11]{}, c[11]{}, d[11]{}, e[11]{};
    int cnt = 0;
    bool fl;

    // scan
    if (loc) printf("A: ");
    scan_set(a);
    if (loc) printf("B: ");
    scan_set(b);
    if (loc) printf("C: ");
    scan_set(c);
    if (loc) printf("D: ");
    scan_set(d);

    // e = a & b
    for (auto x: a) {
        for (auto y: b) {
            if (x == y && x != '\000') {
                e[cnt++] = x;
                break;
            }
        }
    }

    // e |= c
    for (auto x: c) {
        fl = false;
        for (auto y: e) {
            if (x == y) {
                fl = true;
                break;
            }
        }
        if (!fl) {
            e[cnt++] = x;
        }
    }

    // e |= d
    for (auto x: d) {
        fl = false;
        for (auto y: e) {
            if (x == y) {
                fl = true;
                break;
            }
        }
        if (!fl) {
            e[cnt++] = x;
        }
    }

    // sort
    for (int i = 0; i < 11; ++i) {
        for (int j = i; j < 11; ++j) {
            if (e[i] > e[j]) {
                std::swap(e[i], e[j]);
            }
        }
    }

    // print
    if (loc) printf("E: ");
    for (auto x: e) {
        if (x != '\000') printf("%c ", x);
    }

    return 0;
}
