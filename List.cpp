#include <iostream>
#include <chrono>

#ifdef LOCAL
    bool loc = true;
#else
    bool loc = false;
#endif

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
    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node *lastNode = *head;
        while (lastNode->next != nullptr) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
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

int main() {
    Node *headA = nullptr;
    Node *headB = nullptr;
    Node *headC = nullptr;
    Node *headD = nullptr;
    Node *headE = nullptr;

    // scan
    if (loc) printf("A: ");
    scanSet(&headA);
    if (loc) printf("B: ");
    scanSet(&headB);
    if (loc) printf("C: ");
    scanSet(&headC);
    if (loc) printf("D: ");
    scanSet(&headD);

    auto start = std::chrono::high_resolution_clock::now();
    bitwiseAnd(headA, headB, &headE);
    bitwiseOr(headC, headE, &headE);
    bitwiseOr(headD, headE, &headE);
    auto stop = std::chrono::high_resolution_clock::now();

    // print
    if (loc) printf("E: ");
    Node *current = headE;
    while (current != nullptr) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("in %lli nanoseconds", std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());

    return 0;
}
