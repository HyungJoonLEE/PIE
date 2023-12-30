//
// Created by Hyung Joon Lee on 2023-12-29.
//
#include "LinkedList.h"


template<typename T>
const LinkedList<T> *LinkedList<T>::getNext() {
    return next;
}


template<typename T>
const T &LinkedList<T>::getValue() {
    return data;
}


template<typename T>
void LinkedList<T>::setNext(LinkedList *node) {
    next = node;
}


template<typename T>
void LinkedList<T>::setValue(const T &value) {
    data = value;
}


template<typename T>
bool LinkedList<T>::insertToLast(LinkedList<T> **head, T val) {
    auto *newNode = new LinkedList<T>(val);

    if (!newNode) return false;
    if (*head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return true;
    }
    else {
        LinkedList<T> *temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        return true;
    }
}


template<typename T>
bool LinkedList<T>::insertToFront(LinkedList<T> **head, T val) {
    auto *newNode = new LinkedList<T>(val);

    if (!newNode) return false;
    else {
        newNode->data = val;
        newNode->next = *head;
        *head = newNode;
        return true;
    }
}


template<typename T>
bool LinkedList<T>::insertToIndex(LinkedList<T> **head, T val, int index) {
    auto *newNode = new LinkedList<T>(val);
    LinkedList<T> *current = *head;

    if (!newNode) return false;

    if (index <= 0) return false;
    if (index == 1) {
        *head = newNode;
        newNode->next = current;
        return true;
    }

    for (int i = 1; i < index; ++i) {
        if (current->next == nullptr) {
            // If index is greater than
            // the number of nodes in the list
            delete newNode;
            return false;
        }
        current = current->next;
    }

    current->next = newNode;
    newNode->next = current->next;
    return true;
}


/**
 * @breif Stack 'push' using Linked List
 */
template<typename T>
void LinkedList<T>::push(LinkedList<T> **head, T val) {
    auto *newNode = new LinkedList<T>(val);
    if (!(*head)) {
        *head = newNode;
    } else {
        LinkedList<T> *temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


template<typename T>
void LinkedList<T>::clear(LinkedList<T> **head) {
    LinkedList<T> *delNode = *head;
    while (delNode) {
        LinkedList<T> *after = delNode->next;
        delete delNode; // Use delete instead of free
        delNode = after;
    }
    *head = nullptr;
}









