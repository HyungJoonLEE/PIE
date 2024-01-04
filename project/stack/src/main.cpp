#include "Stack.h"
#include "Stack.cpp"
#include <ctime>
#include <string>

struct card {
    std::string shape;
    int num;
};

const std::string shapes[] = {"Heart", "Diamond", "Clover", "Spade"};

card generateRandomCard() {
    card newCard;
    newCard.shape = shapes[std::rand() % 4]; // Now using std::string
    newCard.num = std::rand() % 13 + 1;
    return newCard;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Initialize random seed

    Stack<card> cardStack;
    for (int i = 0; i < 15; i++) {
        card randomCard = generateRandomCard();
        cardStack.push(randomCard);
    }

    for (const auto& c : cardStack.getStack()) {
        std::cout << "Card: " << c.shape << " " << c.num << std::endl;
    }

    return 0;
}
