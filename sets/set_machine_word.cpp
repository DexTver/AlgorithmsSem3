#include <iostream>
#include "set_machine_word.h"

set_machine_word::set_machine_word() : n(0), bitMask(0) {}

set_machine_word::set_machine_word(const char *str) : n(0), bitMask(0) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            int bitPos = str[i] - '0';
            if (!(bitMask & (1 << bitPos))) {
                bitMask |= (1 << bitPos);
                n++;
            }
        }
    }
}

set_machine_word::set_machine_word(const set_machine_word &other) : n(other.n), bitMask(other.bitMask) {}

set_machine_word::~set_machine_word() {}

int countSetBits(unsigned short bitMask) {
    int count = 0;
    while (bitMask) {
        count += bitMask & 1;
        bitMask >>= 1;
    }
    return count;
}

set_machine_word set_machine_word::operator|(const set_machine_word &other) const {
    set_machine_word result;
    result.bitMask = this->bitMask | other.bitMask;
    result.n = countSetBits(result.bitMask);
    return result;
}

set_machine_word set_machine_word::operator&(const set_machine_word &other) const {
    set_machine_word result;
    result.bitMask = this->bitMask & other.bitMask;
    result.n = countSetBits(result.bitMask);
    return result;
}

set_machine_word set_machine_word::operator~() const {
    set_machine_word result;
    result.bitMask = ~this->bitMask & ((1 << U) - 1);
    result.n = countSetBits(result.bitMask);
    return result;
}

set_machine_word &set_machine_word::operator=(const set_machine_word &other) {
    if (this != &other) {
        this->bitMask = other.bitMask;
        this->n = other.n;
    }
    return *this;
}

void set_machine_word::show() const {
    std::cout << "[";
    bool first = true;
    for (int i = 0; i < U; ++i) {
        if (bitMask & (1 << i)) {
            if (!first) {
                std::cout << ", ";
            }
            std::cout << i;
            first = false;
        }
    }
    std::cout << "]";
}

int set_machine_word::power() const {
    return n;
}
