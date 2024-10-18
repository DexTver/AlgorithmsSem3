#pragma once

#include "consts.h"

class set_machine_word {
private:
    int n;                  // Мощность множества
    unsigned short bitMask; // Машинное слово (ushort) для представления множества

public:
    set_machine_word();                         // Конструктор по умолчанию
    explicit set_machine_word(const char *);    // Конструктор с передачей множества в виде строки
    set_machine_word(const set_machine_word &); // Конструктор копии
    ~set_machine_word();                        // Деструктор

    set_machine_word operator|(const set_machine_word &) const; // Операция объединения
    set_machine_word operator&(const set_machine_word &) const; // Операция пересечения
    set_machine_word operator~() const;                         // Операция дополнения
    set_machine_word &operator=(const set_machine_word &);      // Оператор присваивания

    void show() const;    // Функция вывода множества на экран
    int power() const;    // Функция получения мощности множества
};
