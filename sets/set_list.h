#pragma once

#include "consts.h"

struct list_node {
    char data;          // Элемент множества
    list_node *next;    // Указатель на следующий элемент

    explicit list_node(char d) : data(d), next(nullptr) {}
};

class set_list {
private:
    int n;              // Мощность множества
    list_node *head;    // Указатель на голову списка

public:
    set_list();                         // Конструктор по умолчанию
    explicit set_list(const char *);    // Конструктор с передачей множества в виде строки
    set_list(const set_list &);         // Конструктор копии
    ~set_list();                        // Деструктор

    set_list operator|(const set_list &) const; // Операция объединения
    set_list operator&(const set_list &) const; // Операция пересечения
    set_list operator~() const;                 // Операция дополнения
    set_list &operator=(const set_list &);      // Оператор присваивания

    void show() const;  // Функция вывода множества на экран
    int power() const;  // Функция получения мощности множества

private:
    void insert(char);          // Вставка элемента в список
    bool contains(char) const;  // Проверка наличия элемента в списке
    void clear();               // Очистка списка
};
