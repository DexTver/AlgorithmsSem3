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
    Node *current = *head;
    while (current != nullptr) {
        if (current->data == data) {
            return; // Node already exists
        }
        current = current->next;
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
    Node *currentA = headA;
    while (currentA != nullptr) {
        Node *currentB = headB;
        bool found = false;
        while (currentB != nullptr) {
            if (currentA->data == currentB->data) {
                found = true;
                break;
            }
            currentB = currentB->next;
        }
        if (found) {
            insertNode(result, currentA->data);
        }
        currentA = currentA->next;
    }
}

void bitwiseOr(Node *headA, Node *headB, Node **result) {
    Node *currentA = headA;
    while (currentA != nullptr) {
        insertNode(result, currentA->data);
        currentA = currentA->next;
    }
    Node *currentB = headB;
    while (currentB != nullptr) {
        bool found = false;
        Node *currentResult = *result;
        while (currentResult != nullptr) {
            if (currentB->data == currentResult->data) {
                found = true;
                break;
            }
            currentResult = currentResult->next;
        }
        if (!found) {
            insertNode(result, currentB->data);
        }
        currentB = currentB->next;
    }
}

void deleteList(Node **head) {
    Node *current = *head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
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
    // e = c | e
    bitwiseOr(headC, headE, &headE);
    // e = d | e
    bitwiseOr(headD, headE, &headE);
    auto stop = chrono::high_resolution_clock::now();

    // print
    if (loc) cout << "E: ";
    Node *current = headE;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
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
