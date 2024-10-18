#include <iostream>
#include "set_bool_array.h"

set_bool_array::set_bool_array() : n(0) {
    for (bool & i : bitArray) {
        i = false;
    }
}

set_bool_array::set_bool_array(const char *str) : n(0) {
    for (bool & i : bitArray) {
        i = false;
    }
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            int index = str[i] - '0';
            if (!bitArray[index]) {
                bitArray[index] = true;
                n++;
            }
        }
    }
}

set_bool_array::set_bool_array(const set_bool_array &other) : n(other.n) {
    for (int i = 0; i < U; ++i) {
        bitArray[i] = other.bitArray[i];
    }
}

set_bool_array::~set_bool_array() {}

set_bool_array set_bool_array::operator|(const set_bool_array &other) const {
    set_bool_array result;
    for (int i = 0; i < U; ++i) {
        result.bitArray[i] = this->bitArray[i] || other.bitArray[i];
        if (result.bitArray[i]) {
            result.n++;
        }
    }
    return result;
}

set_bool_array set_bool_array::operator&(const set_bool_array &other) const {
    set_bool_array result;
    for (int i = 0; i < U; ++i) {
        result.bitArray[i] = this->bitArray[i] && other.bitArray[i];
        if (result.bitArray[i]) {
            result.n++;
        }
    }
    return result;
}

set_bool_array set_bool_array::operator~() const {
    set_bool_array result;
    for (int i = 0; i < U; ++i) {
        result.bitArray[i] = !this->bitArray[i];
        if (result.bitArray[i]) {
            result.n++;
        }
    }
    return result;
}

set_bool_array &set_bool_array::operator=(const set_bool_array &other) {
    if (this != &other) {
        for (int i = 0; i < U; ++i) {
            this->bitArray[i] = other.bitArray[i];
        }
        this->n = other.n;
    }
    return *this;
}

void set_bool_array::show() const {
    std::cout << "[";
    bool first = true;
    for (int i = 0; i < U; ++i) {
        if (bitArray[i]) {
            if (!first) {
                std::cout << ", ";
            }
            std::cout << i;
            first = false;
        }
    }
    std::cout << "]";
}

int set_bool_array::power() const {
    return n;
}
