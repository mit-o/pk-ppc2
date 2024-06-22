// SinglyLinkedList.h
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>

struct Node
{
    int value;
    Node *next;

    Node(int val) : value(val), next(nullptr) {}
};

class SinglyLinkedList
{
public:
    Node *head;

    SinglyLinkedList() : head(nullptr) {}

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void print()
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    bool search(int val)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->value == val)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void remove_front()
    {
        if (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void remove_back()
    {
        if (head == nullptr)
        {
            return;
        }
        else if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }

    void remove(int val)
    {
        Node *current = head;
        Node *previous = nullptr;
        while (current != nullptr)
        {
            if (current->value == val)
            {
                if (previous == nullptr)
                {
                    head = current->next;
                }
                else
                {
                    previous->next = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    }
};

#endif // SINGLY_LINKED_LIST_H
