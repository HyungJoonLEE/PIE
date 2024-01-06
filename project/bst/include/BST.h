#ifndef PIE_BST_H
#define PIE_BST_H

#include "BST_Node.h"
#include <iostream>


template <typename T>
class BST {
public:
    BST() : root(nullptr) {}
    void insertNode(T data);
    bool searchNode(T data);
    void deleteNode(T& data);
    void preOrder(BSTNode<T>* node);
    void inOrder(BSTNode<T>* node);
    void postOrder(BSTNode<T>* node);
    BST& getRoot() {
        return root;
    }

private:
    BSTNode<T> *root;
};




template<typename T>
void BST<T>::insertNode(T data) {
    if (root == nullptr) {
        root = new BSTNode<T>(data);
    } else {
        BSTNode<T>* current = root;
        while (true) {
            if (data < current->data) {
                if (current->left == nullptr) {
                    current->left = new BSTNode<T>(data);
                    current->count++;
                    break;
                }
                current = current->left;
            }
            else if (data > current->data) {
                if (current->right == nullptr) {
                    current->right = new BSTNode<T>(data);
                    current->count++;
                    break;
                }
                current = current->right;
            }
            else {
                // data already exists in the BST
                current->count++;
                break;
            }
        }
    }
}


template<typename T>
bool BST<T>::searchNode(T data) {
    BSTNode<T>* current = root;
    while (current != nullptr) {
        if (data == current->data) {
            return true;
        }
        else if (data < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return false;
}


template<typename T>
void BST<T>::deleteNode(T& data) {
    BSTNode<T> current = root;
    while (current) {
        if (data < current->data) {
            current = current->left;
        }
        else if (data > current->data) {
            current = current->right;
        }
        else { // Found the node to be deleted
            if (!current->left) {
                BSTNode<T> *temp = current;
                current = current->right;
                delete temp;
            }
            else if (!current->right) {
                BSTNode<T> *temp = current;
                current = current->left;
                delete temp;
            }
            else {
                // Node with two children
                BSTNode<T> *successor = current->right;
                while (successor->left) {
                    successor = successor->left;
                }
                current->data = successor->data;
                deleteNodeRec(successor, (*successor)->data);
            }
            return; // Node deleted
        }
    }
}

template<typename T>
void BST<T>::preOrder(BSTNode<T>* node) {
    if (node == nullptr) return;
    std::cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}


template<typename T>
void BST<T>::inOrder(BSTNode<T>* node) {
    if (node == nullptr) return;
    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}


template<typename T>
void BST<T>::postOrder(BSTNode<T>* node) {
    if (node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->data << " ";
}


#endif //PIE_BST_H
