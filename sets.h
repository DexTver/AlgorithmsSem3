#ifndef SETS_H
#define SETS_H

#include <iostream>
#include <cstring>

#define U 10

// Класс Set на основе массива
class SetArray {
private:
    static int cnt;       // Счётчик множеств
    int n;                // Мощность множества
    char S;               // Тег для различения объектов-множеств
    char *A;              // Указатель на память для множества

public:
    SetArray();                         // Конструктор по умолчанию
    explicit SetArray(const char *);    // Конструктор с передачей множества в виде строки
    SetArray(const SetArray &);         // Конструктор копии
    ~SetArray();                        // Деструктор

    SetArray operator|(const SetArray &) const; // Операция объединения
    SetArray operator&(const SetArray &) const; // Операция пересечения
    SetArray operator~() const;                 // Операция дополнения
    SetArray &operator=(const SetArray &);      // Оператор присваивания

    void Show() const;    // Функция вывода множества на экран
    int power() const;    // Функция получения мощности множества
};

int SetArray::cnt = 0;

SetArray::SetArray() : n(0), S('A' + cnt++), A(new char[U + 1]) {
    A[0] = '\0'; // Пустое множество
}

SetArray::SetArray(const char *str) : n(0), S('A' + cnt++), A(new char[U + 1]) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (strchr("0123456789", str[i]) && !strchr(A, str[i])) {
            A[n++] = str[i]; // Добавляем цифру, если она ещё не добавлена
        }
    }
    A[n] = '\0'; // Завершающий ноль
}

SetArray::SetArray(const SetArray &other) : n(other.n), S('A' + cnt++), A(new char[U + 1]) {
    std::copy(other.A, other.A + other.n, A); // Копируем элементы из другого множества
    A[n] = '\0'; // Завершающий ноль
}

SetArray::~SetArray() {
    delete[] A; // Освобождаем память
}

SetArray SetArray::operator|(const SetArray &other) const {
    SetArray result(*this); // Копируем текущее множество
    for (int i = 0; i < other.n; ++i) {
        if (!strchr(result.A, other.A[i])) {
            result.A[result.n++] = other.A[i]; // Добавляем отсутствующие элементы
        }
    }
    result.A[result.n] = '\0'; // Завершающий ноль
    return result;
}

SetArray SetArray::operator&(const SetArray &other) const {
    SetArray result;
    for (int i = 0; i < n; ++i) {
        if (strchr(other.A, A[i])) {
            result.A[result.n++] = A[i]; // Добавляем общие элементы
        }
    }
    result.A[result.n] = '\0'; // Завершающий ноль
    return result;
}

SetArray SetArray::operator~() const {
    SetArray result;
    for (char c = '0'; c <= '9'; ++c) {
        if (!strchr(A, c)) {
            result.A[result.n++] = c; // Добавляем элементы, отсутствующие в текущем множестве
        }
    }
    result.A[result.n] = '\0'; // Завершающий ноль
    return result;
}

SetArray &SetArray::operator=(const SetArray &other) {
    if (this != &other) {
        delete[] A; // Освобождаем старую память
        A = new char[U + 1];
        n = other.n;
        std::copy(other.A, other.A + other.n, A); // Копируем элементы из другого множества
        A[n] = '\0'; // Завершающий ноль
        S = 'A' + cnt++; // Назначаем новый тег
    }
    return *this;
}

void SetArray::Show() const {
    std::cout << '\n' << S << " = [" << A << "]";
}

int SetArray::power() const {
    return n;
}


// Узел списка
struct ListNode {
    char data;           // Элемент множества (цифра)
    ListNode *next;      // Указатель на следующий элемент

    explicit ListNode(char d) : data(d), next(nullptr) {}
};

// Класс Set на основе списка
class SetList {
private:
    static int cnt;      // Счётчик множеств
    int n;               // Мощность множества
    char S;              // Тег для различения объектов-множеств
    ListNode *head;      // Указатель на голову списка

public:
    SetList();                // Конструктор по умолчанию
    explicit SetList(const char *);     // Конструктор с передачей множества в виде строки
    SetList(const SetList &);  // Конструктор копии
    ~SetList();               // Деструктор

    SetList operator|(const SetList &) const;  // Операция объединения
    SetList operator&(const SetList &) const;  // Операция пересечения
    SetList operator~() const;                // Операция дополнения
    SetList &operator=(const SetList &);       // Оператор присваивания

    void Show() const;    // Функция вывода множества на экран
    int power() const;    // Функция получения мощности множества

private:
    void insert(char);    // Вставка элемента в список
    bool contains(char) const;  // Проверка наличия элемента в списке
    void clear();         // Очистка списка
};

int SetList::cnt = 0;

SetList::SetList() : n(0), S('A' + cnt++), head(nullptr) {}

SetList::SetList(const char *str) : n(0), S('A' + cnt++), head(nullptr) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (strchr("0123456789", str[i]) && !contains(str[i])) {
            insert(str[i]);  // Вставляем уникальные элементы в список
        }
    }
}

SetList::SetList(const SetList &other) : n(other.n), S('A' + cnt++), head(nullptr) {
    ListNode *current = other.head;
    while (current != nullptr) {
        insert(current->data);  // Копируем элементы из другого списка
        current = current->next;
    }
}

SetList::~SetList() {
    clear();  // Удаляем все элементы списка и освобождаем память
}

SetList SetList::operator|(const SetList &other) const {
    SetList result(*this);  // Копируем текущее множество
    ListNode *current = other.head;
    while (current != nullptr) {
        if (!result.contains(current->data)) {
            result.insert(current->data);  // Добавляем отсутствующие элементы
        }
        current = current->next;
    }
    return result;
}

SetList SetList::operator&(const SetList &other) const {
    SetList result;
    ListNode *current = head;
    while (current != nullptr) {
        if (other.contains(current->data)) {
            result.insert(current->data);  // Добавляем общие элементы
        }
        current = current->next;
    }
    return result;
}

SetList SetList::operator~() const {
    SetList result;
    for (char c = '0'; c <= '9'; ++c) {
        if (!contains(c)) {
            result.insert(c);  // Добавляем элементы, которых нет в текущем множестве
        }
    }
    return result;
}

SetList &SetList::operator=(const SetList &other) {
    if (this != &other) {
        clear();  // Очищаем текущее множество
        ListNode *current = other.head;
        while (current != nullptr) {
            insert(current->data);  // Копируем элементы из другого списка
            current = current->next;
        }
        n = other.n;
        S = 'A' + cnt++;  // Назначаем новый тег
    }
    return *this;
}

void SetList::Show() const {
    std::cout << '\n' << S << " = [";
    ListNode *current = head;
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << ", ";
        }
        current = current->next;
    }
    std::cout << "]";
}

int SetList::power() const {
    return n;
}

void SetList::insert(char value) {
    ListNode *newNode = new ListNode(value);
    newNode->next = head;
    head = newNode;
    n++;  // Увеличиваем мощность множества
}

bool SetList::contains(char value) const {
    ListNode *current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void SetList::clear() {
    while (head != nullptr) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
    n = 0;  // Обнуляем мощность множества
}


// Класс Set на основе массива битов
class SetBoolArray {
private:
    static int cnt;             // Счётчик множеств
    int n;                      // Мощность множества (количество элементов)
    char S;                     // Тег для различения объектов-множеств
    bool bitArray[U];           // Булевый массив для представления множества

public:
    SetBoolArray();                // Конструктор по умолчанию
    explicit SetBoolArray(const char *);     // Конструктор с передачей множества в виде строки
    SetBoolArray(const SetBoolArray &);      // Конструктор копии
    ~SetBoolArray();                       // Деструктор

    SetBoolArray operator|(const SetBoolArray &) const;  // Операция объединения
    SetBoolArray operator&(const SetBoolArray &) const;  // Операция пересечения
    SetBoolArray operator~() const;                    // Операция дополнения
    SetBoolArray &operator=(const SetBoolArray &);       // Оператор присваивания

    void Show() const;    // Функция вывода множества на экран
    [[nodiscard]] int power() const;    // Функция получения мощности множества
};

int SetBoolArray::cnt = 0;

SetBoolArray::SetBoolArray() : n(0), S('A' + cnt++) {
    for (int i = 0; i < U; ++i) {
        bitArray[i] = false;  // Инициализируем массив, как пустое множество
    }
}

SetBoolArray::SetBoolArray(const char *str) : n(0), S('A' + cnt++) {
    for (int i = 0; i < U; ++i) {
        bitArray[i] = false;  // Инициализируем массив, как пустое множество
    }
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            int index = str[i] - '0';  // Определяем индекс для цифры
            if (!bitArray[index]) {    // Проверяем, не добавлена ли цифра
                bitArray[index] = true; // Устанавливаем элемент в true
                n++;  // Увеличиваем мощность множества
            }
        }
    }
}

SetBoolArray::SetBoolArray(const SetBoolArray &other) : n(other.n), S('A' + cnt++) {
    for (int i = 0; i < U; ++i) {
        bitArray[i] = other.bitArray[i];  // Копируем массив
    }
}

SetBoolArray::~SetBoolArray() {}

SetBoolArray SetBoolArray::operator|(const SetBoolArray &other) const {
    SetBoolArray result;
    for (int i = 0; i < U; ++i) {
        result.bitArray[i] = this->bitArray[i] || other.bitArray[i];  // Объединение множеств
        if (result.bitArray[i]) {
            result.n++;  // Увеличиваем мощность результата
        }
    }
    return result;
}

SetBoolArray SetBoolArray::operator&(const SetBoolArray &other) const {
    SetBoolArray result;
    for (int i = 0; i < U; ++i) {
        result.bitArray[i] = this->bitArray[i] && other.bitArray[i];  // Пересечение множеств
        if (result.bitArray[i]) {
            result.n++;  // Увеличиваем мощность результата
        }
    }
    return result;
}

SetBoolArray SetBoolArray::operator~() const {
    SetBoolArray result;
    for (int i = 0; i < U; ++i) {
        result.bitArray[i] = !this->bitArray[i];  // Инвертируем множество
        if (result.bitArray[i]) {
            result.n++;  // Увеличиваем мощность результата
        }
    }
    return result;
}

SetBoolArray &SetBoolArray::operator=(const SetBoolArray &other) {
    if (this != &other) {
        for (int i = 0; i < U; ++i) {
            this->bitArray[i] = other.bitArray[i];  // Копируем массив
        }
        this->n = other.n;
        this->S = 'A' + cnt++;  // Назначаем новый тег
    }
    return *this;
}

void SetBoolArray::Show() const {
    std::cout << '\n' << S << " = [";
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

int SetBoolArray::power() const {
    return n;
}


// Класс Set на основе машинного слова
class SetMachineWord {
private:
    static int cnt;           // Счётчик множеств
    int n;                    // Мощность множества
    char S;                   // Тег для различения объектов-множеств
    unsigned short bitMask;   // Машинное слово (ushort) для представления множества

public:
    SetMachineWord();                // Конструктор по умолчанию
    explicit SetMachineWord(const char *);     // Конструктор с передачей множества в виде строки
    SetMachineWord(const SetMachineWord &);  // Конструктор копии
    ~SetMachineWord();               // Деструктор

    SetMachineWord operator|(const SetMachineWord &) const;  // Операция объединения
    SetMachineWord operator&(const SetMachineWord &) const;  // Операция пересечения
    SetMachineWord operator~() const;                       // Операция дополнения
    SetMachineWord &operator=(const SetMachineWord &);       // Оператор присваивания

    void Show() const;    // Функция вывода множества на экран
    int power() const;    // Функция получения мощности множества
};

int SetMachineWord::cnt = 0;

SetMachineWord::SetMachineWord() : n(0), S('A' + cnt++), bitMask(0) {}

SetMachineWord::SetMachineWord(const char *str) : n(0), S('A' + cnt++), bitMask(0) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            int bitPos = str[i] - '0';  // Определяем позицию бита для цифры
            if (!(bitMask & (1 << bitPos))) {  // Проверяем, не установлен ли бит
                bitMask |= (1 << bitPos);  // Устанавливаем бит для цифры
                n++;  // Увеличиваем мощность множества
            }
        }
    }
}

SetMachineWord::SetMachineWord(const SetMachineWord &other) : n(other.n), S('A' + cnt++), bitMask(other.bitMask) {}

SetMachineWord::~SetMachineWord() {}

// Функция для подсчёта установленных битов (единиц) в числе
int countSetBits(unsigned short bitMask) {
    int count = 0;
    while (bitMask) {
        count += bitMask & 1;  // Если последний бит 1, добавляем к счётчику
        bitMask >>= 1;         // Сдвигаем биты вправо
    }
    return count;
}

SetMachineWord SetMachineWord::operator|(const SetMachineWord &other) const {
    SetMachineWord result;
    result.bitMask = this->bitMask | other.bitMask;  // Объединяем машинные слова
    result.n = countSetBits(result.bitMask);         // Подсчитываем количество установленных битов
    return result;
}

SetMachineWord SetMachineWord::operator&(const SetMachineWord &other) const {
    SetMachineWord result;
    result.bitMask = this->bitMask & other.bitMask;  // Пересекаем машинные слова
    result.n = countSetBits(result.bitMask);         // Подсчитываем количество установленных битов
    return result;
}

SetMachineWord SetMachineWord::operator~() const {
    SetMachineWord result;
    result.bitMask = ~this->bitMask & ((1 << U) - 1);  // Инвертируем машинное слово и ограничиваем его 10 битами
    result.n = countSetBits(result.bitMask);           // Подсчитываем количество установленных битов
    return result;
}

SetMachineWord &SetMachineWord::operator=(const SetMachineWord &other) {
    if (this != &other) {
        this->bitMask = other.bitMask;  // Копируем машинное слово
        this->n = other.n;
        this->S = 'A' + cnt++;  // Назначаем новый тег
    }
    return *this;
}

void SetMachineWord::Show() const {
    std::cout << '\n' << S << " = [";
    bool first = true;
    for (int i = 0; i < U; ++i) {
        if (bitMask & (1 << i)) {
            if (!first) {
                std::cout << ", ";
            }
            std::cout << i;  // Выводим цифры, для которых биты установлены
            first = false;
        }
    }
    std::cout << "]";
}

int SetMachineWord::power() const {
    return n;
}

#endif // SETS_H