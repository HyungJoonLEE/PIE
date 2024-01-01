#include "Stack.h"

template<typename T>
Stack<T>::Stack() {
    stackVector.reserve(20); // Changed to '.' operator
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
const std::vector<T>& Stack<T>::getStack() const {
    return stackVector;
}
