#include <iostream>

#ifdef LOCAL
    bool loc = true;
#else
    bool loc = false;
#endif

// Define the Node structure
struct Node {
    char data;
    Node* next;
};

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the end of the list
void insertNode(Node** head, char data) {
    Node* newNode = createNode(data);
    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to scan a set of characters and store them in a linked list
void scanSet(Node** head) {
    char x;
    do {
        x = (char) getc(stdin);
        if ('0' <= x && x <= '9') {
            insertNode(head, x);
        }
    } while (x != '\n');
}

// Function to perform the bitwise AND operation on two linked lists
void bitwiseAnd(Node* headA, Node* headB, Node** result) {
    Node* currentA = headA;
    while (currentA != nullptr) {
        Node* currentB = headB;
        while (currentB != nullptr) {
            if (currentA->data == currentB->data) {
                insertNode(result, currentA->data);
                break;
            }
            currentB = currentB->next;
        }
        currentA = currentA->next;
    }
}

// Function to perform the bitwise OR operation on two linked lists
void bitwiseOr(Node* headA, Node* headB, Node** result) {
    Node* currentA = headA;
    while (currentA != nullptr) {
        bool found = false;
        Node* currentResult = *result;
        while (currentResult != nullptr) {
            if (currentA->data == currentResult->data) {
                found = true;
                break;
            }
            currentResult = currentResult->next;
        }
        if (!found) {
            insertNode(result, currentA->data);
        }
        currentA = currentA->next;
    }
    Node* currentB = headB;
    while (currentB != nullptr) {
        bool found = false;
        Node* currentResult = *result;
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

// Function to sort the linked list
void sortList(Node** head) {
    Node* current = *head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        while (nextNode != nullptr) {
            if (current->data > nextNode->data) {
                char temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }
            nextNode = nextNode->next;
        }
        current = current->next;
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        printf("%c ", current->data);
        current = current->next;
    }
}

int main() {
    Node* headA = nullptr;
    Node* headB = nullptr;
    Node* headC = nullptr;
    Node* headD = nullptr;
    Node* headE = nullptr;

    // Scan sets
    if (loc) printf("A: ");
    scanSet(&headA);
    if (loc) printf("B: ");
    scanSet(&headB);
    if (loc) printf("C: ");
    scanSet(&headC);
    if (loc) printf("D: ");
    scanSet(&headD);

    // Perform bitwise AND and OR operations
    bitwiseAnd(headA, headB, &headE);
    bitwiseOr(headC, headE, &headE);
    bitwiseOr(headD, headE, &headE);

    // Sort the result list
    sortList(&headE);

    // Print the result list
    if (loc) printf("E: ");
    printList(headE);

    return 0;
}