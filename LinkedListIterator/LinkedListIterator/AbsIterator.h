#pragma once
//author: Денисова Екатерина

template <typename T>
// абстрактный класс итератора
class AbsIterator
{
    // оператор перехода на следующий элемент
    virtual void  operator++() const {};
    // оператор получения данных их элемента
    virtual T& operator*() const = 0;
    // операторы сравнения
    virtual bool operator==(const AbsIterator& o) const = 0;
    virtual bool operator!=(const AbsIterator& o) const = 0;

};

