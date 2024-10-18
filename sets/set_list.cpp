#include <iostream>
#include <cstring>
#include "set_list.h"

set_list::set_list() : n(0), head(nullptr) {}

set_list::set_list(const char *str) : n(0), head(nullptr) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (strchr("0123456789", str[i]) && !contains(str[i])) {
            insert(str[i]);
        }
    }
}

set_list::set_list(const set_list &other) : n(other.n), head(nullptr) {
    list_node *current = other.head;
    while (current != nullptr) {
        insert(current->data);
        current = current->next;
    }
}

set_list::~set_list() {
    clear();
}

set_list set_list::operator|(const set_list &other) const {
    set_list result(*this);
    list_node *current = other.head;
    while (current != nullptr) {
        if (!result.contains(current->data)) {
            result.insert(current->data);
        }
        current = current->next;
    }
    return result;
}

set_list set_list::operator&(const set_list &other) const {
    set_list result;
    list_node *current = head;
    while (current != nullptr) {
        if (other.contains(current->data)) {
            result.insert(current->data);
        }
        current = current->next;
    }
    return result;
}

set_list set_list::operator~() const {
    set_list result;
    for (char c = '0'; c <= '9'; ++c) {
        if (!contains(c)) {
            result.insert(c);
        }
    }
    return result;
}

set_list &set_list::operator=(const set_list &other) {
    if (this != &other) {
        clear();
        list_node *current = other.head;
        while (current != nullptr) {
            insert(current->data);
            current = current->next;
        }
        n = other.n;
    }
    return *this;
}

void set_list::show() const {
    std::cout << "[";
    list_node *current = head;
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << ", ";
        }
        current = current->next;
    }
    std::cout << "]";
}

int set_list::power() const {
    return n;
}

void set_list::insert(char value) {
    list_node *newNode = new list_node(value);
    newNode->next = head;
    head = newNode;
    n++;
}

bool set_list::contains(char value) const {
    list_node *current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void set_list::clear() {
    while (head != nullptr) {
        list_node *temp = head;
        head = head->next;
        delete temp;
    }
    n = 0;
}
