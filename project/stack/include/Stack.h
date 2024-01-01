#ifndef PIE_STACK_H
#define PIE_STACK_H

#include <vector>
#include <iostream>

template <typename T>
class Stack {
public:
    Stack();
    void push(const T& data);
    void pop();
    const std::vector<T>& getStack() const;

private:
    std::vector<T> stackVector;
};

#endif //PIE_STACK_H
