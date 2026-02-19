#include <iostream>
#include "card.hpp"
#include "deck.hpp"

int main(void) {
    Deck deck;

    std::cout << deck;

    deck.shuffle();

    std::cout << deck;
    return 0;
}