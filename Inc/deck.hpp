//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #2 Flip Cards-a Upload Link
// Header for the deck class (basically just wrapping around a linked list of
// card objects).
//
#pragma once

#include "linked_list.tpp"
#include "card.hpp"

class Deck
{
    public:
        Deck(void);
        // Constructor.

        ~Deck(void);
        // Destructor.

        void shuffle(void);
        // Shuffles the order of the deck.

        friend std::ostream& operator<<(std::ostream& os, const Deck& deck);
        // Overloaded << to allow for printing.
    public:
        LinkedList<Card>::Node*& front; // Reference to the first card in the
                                        // deck (aliases list.head).

    private:
        static constexpr int DECK_MAX_SIZE = 52; // Max size of a deck.
        LinkedList<Card> list; // Linked list for the cards.
        int size = 0; // Size of deck.
};