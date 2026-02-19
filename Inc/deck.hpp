#pragma once

#include "linked_list.tpp"
#include "card.hpp"

class Deck {
    public:
        Deck(void);  // Constructor.
        ~Deck(void); // Destructor.

        /* Overloaded << to allow for printing. */
        friend std::ostream& operator<<(std::ostream& os, const Deck& deck);
    private:
        static constexpr int DECK_MAX_SIZE = 52; // Max size of a deck.
        LinkedList<Card> list; // Linked list for the cards.
        int size = 0; // Size of deck.

};