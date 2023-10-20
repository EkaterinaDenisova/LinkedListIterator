#pragma once
//author: Денисова Екатерина

#include <iostream>
#include "AbsIterator.h"
// класс узла списка
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    // конструктор с параметром
    Node(T& data1)  {
        data = data;
        next = nullptr;
    }
};

// класс односвязного списка
template <typename T>
class LinkedList {
private:
    // указатель на начало списка
    Node<T>* head;

public:
    // конструктор без параметров
    LinkedList() {
        head = nullptr;
    }

    // деструктор
    // удаляются все узлы в списке
    ~LinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addNode(T& data);
    // Удаление узла по значению
    void removeNode(T& data);
    bool searchNode(T& data);
    void printList() ;


    // класс итератора для Linked List
    template<class T>
    class LinkedListIterator() : public AbsIterator<T> {
    private:
        Node<T>* current;  // Текущий узел

    public:
        // конструктор с параметром
        LinkedListIterator(Node<T>*x) {
            current = x;
        }

        // оператор сравнения
        bool operator==(const LinkedListIterator<T>&o) const override {
            return current == o.current;
        }

        bool operator!=(const LinkedListIterator<T>&o) const override {
            return !(current == o.current);
        }

        // оператор доступа к данным
        T& operator*() const override {
            //возвращает данные текущего узла
            return current->data;
        }

        // оператор перехода на следующий узел
        LinkedListIterator& operator++() override {
            //если текущий не равен nullptr
            if (current != nullptr) {
                //переходим к следующему узлу
                current = current->next;
            }
            //возвращаем ссылку на текущий объект
            return *this;
        }


    };


    LinkedListIterator<T> begin() const {
        return LinkedListIterator(head);
    }

    LinkedListIterator<T> end() const {
        return LinkedListIterator(nullptr);
    }

};


    // добавление узла в список
    template<typename T>
    void LinkedList<T>::addNode(T& data) {
        Node<T>* newNode = new Node<T>(data);

        // если список пустой, то создаём первый элемент
        if (head == nullptr) {
            head = newNode;
        }
        // находим последний узел списка и добавляем новый узел после него
        else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Удаление узла по значению
    template<typename T>
    void LinkedList<T>::removeNode(T& data) {
        // если список не пустой
        if (head != nullptr) {

            // если нужно удалить узел из начала
            if (head->data == data) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
                
            }
            // если удаляемый узел не в начале
            // ищем узел на удаление
            else {
                Node<T>* current = head;
                while (current->next != nullptr) {
                    // если нужный узел найден
                    // удаляем его и меняем указатели
                    if (current->next->data == data) {
                        Node<T>* temp = current->next;
                        current->next = current->next->next;
                        delete temp;
                        return;
                    }
                    current = current->next;
                }
            }
        }
    }

    // поиск узла
    // true, если есть узел
    // иначе false
    template<typename T>
    bool LinkedList<T>::searchNode(T & data) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // вывод списка в консоль
    template<typename T>
    void LinkedList<T>::printList() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

