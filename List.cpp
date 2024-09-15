#include <iostream>

#ifdef LOCAL
    bool loc = true;
#else
    bool loc = false;
#endif

struct ListNode {
    char data = '\000';
    ListNode *next = nullptr;
};

struct List {
    ListNode *first{};
    ListNode *last{};
    int len = 0;

    void add(ListNode *x) {
        if (this->len == 0) {
            this->first = x;
            this->last = x;
        } else {
            this->last->next = x;
            this->last = x;
        }
        ++len;
    }
};

void scan_set(List *t) {
    char x;
    ListNode *new_node = nullptr;
    do {
        x = (char) getc(stdin);
        if ('0' <= x && x <= '9') {
            new_node = (ListNode *) malloc(sizeof(ListNode));
            new_node->data = x;
            t->add(new_node);
        }
    } while (x != '\n');
}

int main() {
    List a, b, c, d, e;
    ListNode *new_node = nullptr;
    bool fl;

    // scan
    if (loc) printf("A: ");
    scan_set(&a);
    if (loc) printf("B: ");
    scan_set(&b);
    if (loc) printf("C: ");
    scan_set(&c);
    if (loc) printf("D: ");
    scan_set(&d);

    // e = a & b
    for (auto x = a.first; x != nullptr; x = x->next) {
        for (auto y = b.first; y != nullptr; y = y->next) {
            if (x->data == y->data) {
                new_node = (ListNode *) malloc(sizeof(ListNode));
                new_node->data = x->data;
                e.add(new_node);
            }
        }
    }

    // e |= c
    for (auto x = c.first; x != nullptr; x = x->next) {
        fl = false;
        for (auto y = e.first; y != nullptr; y = y->next) {
            if (x->data == y->data) {
                fl = true;
                break;
            }
        }
        if (!fl) {
            new_node = (ListNode *) malloc(sizeof(ListNode));
            new_node->data = x->data;
            e.add(new_node);
        }
    }

    // e |= d
    for (auto x = d.first; x != nullptr; x = x->next) {
        fl = false;
        for (auto y = e.first; y != nullptr; y = y->next) {
            if (x->data == y->data) {
                fl = true;
                break;
            }
        }
        if (!fl) {
            new_node = (ListNode *) malloc(sizeof(ListNode));
            new_node->data = x->data;
            e.add(new_node);
        }
    }

    // sort
    for (auto x = e.first; x != nullptr; x = x->next) {
        for (auto y = x->next; y != nullptr; y = y->next) {
            if (x->data > y->data) {
                std::swap(x->data, y->data);
            }
        }
    }

    // print
    if (loc) printf("E: ");
    for (auto x = e.first; x != nullptr; x = x->next) {
        printf("%c ", x->data);
    }

    return 0;
}
