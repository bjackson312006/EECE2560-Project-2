//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #2 Flip Cards-b Upload Link
// Header for the deck class (basically just wrapping around a linked list of
// card objects).
//
#pragma once

#include "linked_list.tpp"
#include "card.hpp"

void playFlip(void);
// Global function that plays the Flip game: init deck, shuffle, draw 24 into
// hand, print hand and deck, then run the game and print results.

class Deck
{
    public:
        Deck(void);
        // Constructor.

        ~Deck(void);
        // Destructor.

        void shuffle(void);
        // Shuffles the order of the deck.

        LinkedList<Card>::Node* deal(void);
        // Returns the top card node and removes it from the deck. Caller owns
        // the returned node. Returns nullptr if the deck is empty.

        void replace(LinkedList<Card>::Node* node);
        // Places the given card node on the bottom of the deck.

        bool isEmpty(void) const;
        // Returns true if the deck has no cards.

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
