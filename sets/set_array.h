#pragma once

#include "consts.h"

class set_array {
private:
    int n;      // Мощность множества
    char *A;    // Указатель на память для множества

public:
    set_array();                        // Конструктор по умолчанию
    explicit set_array(const char *);   // Конструктор с передачей множества в виде строки
    set_array(const set_array &);       // Конструктор копии
    ~set_array();                       // Деструктор

    set_array operator|(const set_array &) const;   // Операция объединения
    set_array operator&(const set_array &) const;   // Операция пересечения
    set_array operator~() const;                    // Операция дополнения
    set_array &operator=(const set_array &);        // Оператор присваивания

    void show() const;  // Функция вывода множества на экран
    int power() const;  // Функция получения мощности множества
};
