#include "LinkedList.h"
#include "LinkedList.cpp"
#include <ctime>


typedef struct cards{
    char* shape;
    int num;
} card;

const char* shapes[] = {"Heart", "Diamond", "Clover", "Spade"};

card generateRandomCard() {
    card newCard;
    newCard.shape = (char*)shapes[std::rand() % 4]; // Randomly select a shape
    newCard.num = std::rand() % 13 + 1; // Randomly select a number between 1 and 13
    return newCard;
}

int main() {
    std::srand(std::time(nullptr));
    LinkedList<card>* head = nullptr; // Creates a head node with default card

    for (int i = 0; i < 10; i++) {
        card randomCard = generateRandomCard();

        // TODO: This is for original LinkedList
        head->insert(&head, randomCard);
        head->insertInFront(&head, randomCard);

        // TODO: This is for stack using LinkedList
        head->push(&head, randomCard);
    }

    for (auto it = head->begin(); it != head->end(); ++it) {
        card c = *it;
        std::cout << "Card: " << c.shape << " " << c.num << std::endl;
    }

//    for (auto c : *head) {
//        std::cout << "Card: " << c.shape << " " << c.num << std::endl;
//    }

    head->deleteList(&head);
}
