// DoublyLinkedList.h
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

struct DNode
{
    int value;
    DNode *next;
    DNode *prev;

    DNode(int val) : value(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
public:
    DNode *head;
    DNode *tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(int val)
    {
        DNode *newNode = new DNode(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        DNode *newNode = new DNode(val);
        if (tail == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void print()
    {
        DNode *current = head;
        while (current != nullptr)
        {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    bool search(int val)
    {
        DNode *current = head;
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
            DNode *temp = head;
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
            delete temp;
        }
    }

    void remove_back()
    {
        if (tail != nullptr)
        {
            DNode *temp = tail;
            tail = tail->prev;
            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
            else
            {
                head = nullptr;
            }
            delete temp;
        }
    }

    void remove(int val)
    {
        DNode *current = head;
        while (current != nullptr)
        {
            if (current->value == val)
            {
                if (current->prev != nullptr)
                {
                    current->prev->next = current->next;
                }
                else
                {
                    head = current->next;
                }
                if (current->next != nullptr)
                {
                    current->next->prev = current->prev;
                }
                else
                {
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }
};

#endif // DOUBLY_LINKED_LIST_H
