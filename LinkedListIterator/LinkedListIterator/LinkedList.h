#pragma once
//author: �������� ���������

#include <iostream>

// ����� ���� ������
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    // ����������� � ����������
    Node(T& data1)  {
        data = data;
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

    // ���������� ���� � ������
    void addNode(T& data) {
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
    void removeNode(T& data) {
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
    bool searchNode(T& data) {
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
    void printList() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

