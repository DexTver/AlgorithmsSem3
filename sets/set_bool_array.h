#pragma once

#include "consts.h"

class set_bool_array {
private:
    int n;              // Мощность множества (количество элементов)
    bool bitArray[U];   // Булевый массив для представления множества

public:
    set_bool_array();                       // Конструктор по умолчанию
    explicit set_bool_array(const char *);  // Конструктор с передачей множества в виде строки
    set_bool_array(const set_bool_array &); // Конструктор копии
    ~set_bool_array();                      // Деструктор

    set_bool_array operator|(const set_bool_array &) const; // Операция объединения
    set_bool_array operator&(const set_bool_array &) const; // Операция пересечения
    set_bool_array operator~() const;                       // Операция дополнения
    set_bool_array &operator=(const set_bool_array &);      // Оператор присваивания

    void show() const;  // Функция вывода множества на экран
    int power() const;  // Функция получения мощности множества
};
