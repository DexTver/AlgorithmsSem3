#include <iostream>
#include <chrono>

#ifdef LOCAL
    bool loc = true;
#else
    bool loc = false;
#endif

using namespace std;

struct Node {
    char data;
    Node *next;
};

Node *createNode(char data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Node **head, char data) {
    for (Node *cur = *head; cur != nullptr; cur = cur->next) {
        if (cur->data == data) {
            return; // Node already exists
        }
    }
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void scanSet(Node **head) {
    char x;
    do {
        x = (char) getc(stdin);
        if ('0' <= x && x <= '9') {
            insertNode(head, x);
        }
    } while (x != '\n');
}

void bitwiseAnd(Node *headA, Node *headB, Node **result) {
    for (Node *curA = headA; curA != nullptr; curA = curA->next) {
        bool found = false;
        for (Node *curB = headB; curB != nullptr; curB = curB->next) {
            if (curA->data == curB->data) {
                found = true;
                break;
            }
        }
        if (found) {
            insertNode(result, curA->data);
        }
    }
}

void bitwiseOr(Node *headA, Node **result) {
    for (Node *cur = headA; cur != nullptr; cur = cur->next) {
        insertNode(result, cur->data);
    }
}

void deleteList(Node **head) {
    Node *cur = *head;
    while (cur != nullptr) {
        Node *next = cur->next;
        delete cur;
        cur = next;
    }
    *head = nullptr;
}

int main() {
    Node *headA = nullptr, *headB = nullptr, *headC = nullptr, *headD = nullptr, *headE = nullptr;

    // scan
    if (loc) cout << "A: ";
    scanSet(&headA);
    if (loc) cout << "B: ";
    scanSet(&headB);
    if (loc) cout << "C: ";
    scanSet(&headC);
    if (loc) cout << "D: ";
    scanSet(&headD);

    auto start = chrono::high_resolution_clock::now();
    // e = a & b
    bitwiseAnd(headA, headB, &headE);
    // e |= c
    bitwiseOr(headC, &headE);
    // e |= d
    bitwiseOr(headD, &headE);
    auto stop = chrono::high_resolution_clock::now();

    // print
    if (loc) cout << "E: ";
    Node *cur = headE;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "in " << chrono::duration_cast<chrono::nanoseconds>(stop - start).count() << " nanoseconds";

    // deleting lists
    deleteList(&headA);
    deleteList(&headB);
    deleteList(&headC);
    deleteList(&headD);
    deleteList(&headE);

    return 0;
}
