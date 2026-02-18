#include <iostream>
#include "card.hpp"

int main(void) {
    Card card(Card::CLUB, Card::TWO);

    std::cout << card << std::endl;
    return 0;
}