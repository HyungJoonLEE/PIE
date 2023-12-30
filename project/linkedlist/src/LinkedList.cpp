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
void LinkedList<T>::insert(LinkedList<T> **head, T val) {
    auto *newElem = new LinkedList<T>(val);
    newElem->next = *head;
    *head = newElem;
}


template<typename T>
bool LinkedList<T>::insertInFront(LinkedList<T> **head, T val) {
    auto *newNode = new LinkedList<T>(val);

    if (!newNode) return false;
    else {
        newNode->data = val;
        newNode->next = *head;
        *head = newNode;
        return true;
    }
}


/***
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
void LinkedList<T>::deleteList(LinkedList<T> **head) {
    LinkedList<T> *delNode = *head;
    while (delNode) {
        LinkedList<T> *next = delNode->next;
        delete delNode; // Use delete instead of free
        delNode = next;
    }
    *head = nullptr;
}









