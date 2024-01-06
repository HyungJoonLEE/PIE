#ifndef PIE_BST_NODE_H
#define PIE_BST_NODE_H


template <typename T>
class BSTNode {
public:
    BSTNode(T value);

    T data;
    BSTNode *left, *right;
    int count;
};

#endif //PIE_BST_NODE_H

template<typename T>
BSTNode<T>::BSTNode(T value) : data(value), left(nullptr), right(nullptr) {
    T *data = new T;
}