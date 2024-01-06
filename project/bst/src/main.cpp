#include "BST.h"

int main() {
    BST<int> bst;

    bst.insertNode(5);
    bst.insertNode(3);
    bst.insertNode(7);
    bst.insertNode(1);
    bst.insertNode(4);


    std::cout << "Search for 3: " << (bst.searchNode(3) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 6: " << (bst.searchNode(6) ? "Found" : "Not Found") << std::endl;

}