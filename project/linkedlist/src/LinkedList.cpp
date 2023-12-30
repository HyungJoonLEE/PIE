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
    if (newNode == nullptr) return false;
    else {
        newNode->data = val;
        newNode->next = *head;
        *head = newNode;
        return true;
    }
}


template<typename T>
bool LinkedList<T>::insertToIndex(LinkedList<T> **head, T val, int index) {
    LinkedList<T> *current = *head;
    if (*head == nullptr) return false;
    if (index <= 0) return false;

    auto *newNode = new LinkedList<T>(val);
    if (!newNode) return false;
    if (index == 1) {
        *head = newNode;
        newNode->next = current;
        return true;
    }
    else {
        for (int i = 1; i < index; ++i) {
            // If index is greater than the number of nodes in the list
            if (current->next == nullptr) {
                delete newNode;
                return false;
            }
            current = current->next;
        }

        current->next = newNode;
        newNode->next = current->next;
        return true;
    }
}


template<typename T>
LinkedList<T>* LinkedList<T>::search(LinkedList<T> **head, const T& value) {
    LinkedList<T> *current = *head;

    while (current != nullptr) {
        if (current->data == value) {
            return current; // Value found, return the node
        }
        current = current->next;
    }

    return nullptr; // Value not found, return nullptr
}


template<typename T>
bool LinkedList<T>::deleteElement(LinkedList<T> **head, LinkedList<T> *delNode) {
    if (*head == nullptr || delNode == nullptr) {
        return false;
    }

    if (*head == delNode) {
        LinkedList<T> *temp = *head;
        *head = (*head)->next;
        delete temp;
        return true;
    }

    LinkedList<T> *current = *head;
    LinkedList<T> *prev = nullptr;
    while (current != nullptr && current != delNode) {
        prev = current;
        current = current->next;
    }

    // Node not found
    if (current == nullptr) {
        return false;
    }

    // Node found
    prev->next = current->next;
    delete current;
    return true;
}


/**
 * @breif 'push()' using Linked List
 * @parameter 'stack' is actually head of LinkedList
 */
template<typename T>
bool LinkedList<T>::push(LinkedList<T> **stack, T val) {
    auto *newNode = new LinkedList<T>(val);
    if (newNode == nullptr) return false;

    if (!(*stack)) {
        *stack = newNode;
        return true;
    }
    else {
        LinkedList<T> *temp = *stack;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        return true;
    }
}


/**
 * @breif 'pop()' using Linked List
 * @parameter 'stack' is actually head of LinkedList
 */
template<typename T>
bool LinkedList<T>::pop(LinkedList<T> **stack) {
    if (*stack == nullptr) return false;

    // stack has only one node (head)
    if ((*stack)->next == nullptr) {
        delete *stack;
        *stack = nullptr;
        return true;
    }

    // stack has multiple nodes
    LinkedList<T> *current = *stack;
    LinkedList<T> *before = nullptr;

    while (current->next != nullptr) {
        before = current;
        current = current->next;
    }

    delete current;
    before->next = nullptr;
    return true;
}


template<typename T>
void LinkedList<T>::clear(LinkedList<T> **head) {
    if (*head == nullptr) return;
    LinkedList<T> *delNode = *head;
    while (delNode) {
        LinkedList<T> *after = delNode->next;
        delete delNode; // Use delete instead of free
        delNode = after;
    }
    *head = nullptr;
}









