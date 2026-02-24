//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #2 Flip Cards-a Upload Link
// Used to test the card and deck classes.
//
#include <iostream>
#include "card.hpp"
#include "deck.hpp"

int main(void)
// Main method of the game - Used to run and test the card and deck classes
{
    Deck deck;

    std::cout << deck;

    deck.shuffle();

    std::cout << deck;
    return 0;
} // end main