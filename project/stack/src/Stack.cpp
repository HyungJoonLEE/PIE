#include "Stack.h"

template<typename T>
Stack<T>::Stack() {
    stackVector.reserve(20);
}


template<typename T>
void Stack<T>::push(const T& data) {
    stackVector.push_back(data);
}


template<typename T>
void Stack<T>::pop() {
    if (!stackVector.empty()) {
        stackVector.pop_back();
    }
}


template<typename T>
const T& Stack<T>::top() {
    if (!stackVector.empty()) {
        return stackVector.back();
    }
    throw std::runtime_error("Stack is empty");
}



template<typename T>
bool Stack<T>::isEmpty() {
    if (stackVector.empty())
        return true;
    else
        return false;
}
