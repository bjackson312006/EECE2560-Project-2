#include <iostream>
#include "card.hpp"
#include "deck.hpp"

//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #2 Flip Cards-a Upload Link
// Used to test the card and deck classes.
//

int main(void) {
    Deck deck;

    std::cout << deck;

    deck.shuffle();

    std::cout << deck;
    return 0;
}