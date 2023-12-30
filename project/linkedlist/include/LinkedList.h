//
// Created by Hyung Joon Lee on 2023-12-29.
//
#ifndef PIE_LINKEDLIST_H
#define PIE_LINKEDLIST_H

#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
class LinkedList {
public:
    LinkedList() : next(nullptr), data(T()) {}
    LinkedList(const T &value) : next(NULL), data(value) {}
    LinkedList(const LinkedList &cp) : next(NULL), data(cp.data) {
        if (!cp.next)
            next = new LinkedList<T>(*cp.next);
    }


    // LinkedList
    const LinkedList* getNext();
    const T& getValue();
    void setNext(LinkedList *elem);
    void setValue(const T &value);
    bool insertToLast(LinkedList<T> **head, T val);     // TODO: Need to understand this
    bool insertToFront(LinkedList<T> **head, T val);    // TODO: Need to understand this
    bool insertToIndex(LinkedList<T> **head, T val, int index);
    bool deleteElement(LinkedList<T> **head, LinkedList<T> *delNode);
    void clear(LinkedList<T> **head);


    // Stack Function using LinkedList
    void push(LinkedList<T> **head, T val);


    LinkedList& operator=(const LinkedList &rhs) {
        if (this != &rhs) {
            delete next;  // Free existing resources

            data = rhs.data;
            next = (rhs.next ? new LinkedList<T>(*rhs.next) : nullptr);
        }
        return *this;
    }

    class Iterator {
    public:
        Iterator(LinkedList<T>* node) : currentNode(node) {}

        // Dereference operator
        T& operator*() const {
            return currentNode->data;
        }

        // Pre-increment operator
        Iterator& operator++() {
            currentNode = currentNode->next;
            return *this;
        }

        // Equality comparison
        bool operator!=(const Iterator& other) const {
            return currentNode != other.currentNode;
        }
    private:
        LinkedList<T>* currentNode;
    };

    // Methods to get iterators
    Iterator begin() { return Iterator(this); }
    Iterator end() { return Iterator(nullptr); }

private:
    LinkedList  *next;
    T            data;
};



#endif //PIE_LINKEDLIST_H
