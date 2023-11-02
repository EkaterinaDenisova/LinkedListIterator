#pragma once
//author: �������� ���������

#include <iostream>
#include <vector>
#include "AbsIterator.h"
// ����� ���� ������
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    // ����������� � ����������
    Node(const T& data1)  {
        this->data = data1;
        next = nullptr;
    }
};

// ����� ������������ ������
template <typename T>
class LinkedList {
private:
    // ��������� �� ������ ������
    Node<T>* head;

public:
    // ����������� ��� ����������
    LinkedList() {
        head = nullptr;
    }

    // ����������
    // ��������� ��� ���� � ������
    ~LinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // ���������� ���� � ����� ������
    void addNode(const T& data);
    // �������� ���� �� ��������
    void removeNode(T& data);
    // ����� ���� �� ��������
    // true ���� ���� ������, ����� false
    bool searchNode(T& data);
    // ����� ������ � �������
    void printList();


    // ����� ��������� ��� Linked List
    template<typename T>
    class LinkedListIterator : public AbsIterator<T> {
    private:
        Node<T>* current;  // ������� ����

    public:
        // ����������� � ����������
        LinkedListIterator(Node<T>*x) {
            current = x;
        }

        // �������� ���������
        bool operator==(const AbsIterator<T>& o) const override {
            return current == dynamic_cast<const LinkedListIterator<T>&>(o).current;
        }

        bool operator!=(const AbsIterator<T>& o) const override {
            return !(current == dynamic_cast<const LinkedListIterator<T>&>(o).current);
        }

        // �������� ������� � ������
        T& operator*() const override {
            //���������� ������ �������� ����
            return current->data;
        }

        // �������� �������� �� ��������� ����
        LinkedListIterator& operator++() override {
            //���� ������� �� ����� nullptr
            if (current != nullptr) {
                //��������� � ���������� ����
                current = current->next;
            }
            //���������� ������ �� ������� ������
            return *this;
        }


    };


    LinkedListIterator<T> begin() const {
        return LinkedListIterator<T>(head);
    }

    LinkedListIterator<T> end() const {
        return LinkedListIterator<T>(nullptr);
    }

};


    // ���������� ���� � ������
    template<typename T>
    void LinkedList<T>::addNode(const T& data) {
        Node<T>* newNode = new Node<T>(data);

        // ���� ������ ������, �� ������ ������ �������
        if (head == nullptr) {
            head = newNode;
        }
        // ������� ��������� ���� ������ � ��������� ����� ���� ����� ����
        else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // �������� ���� �� ��������
    template<typename T>
    void LinkedList<T>::removeNode(T& data) {
        // ���� ������ �� ������
        if (head != nullptr) {

            // ���� ����� ������� ���� �� ������
            if (head->data == data) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
                
            }
            // ���� ��������� ���� �� � ������
            // ���� ���� �� ��������
            else {
                Node<T>* current = head;
                while (current->next != nullptr) {
                    // ���� ������ ���� ������
                    // ������� ��� � ������ ���������
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

    // ����� ����
    // true, ���� ���� ����
    // ����� false
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

    // ����� ������ � �������
    template<typename T>
    void LinkedList<T>::printList() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

