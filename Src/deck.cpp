#include "deck.hpp"

/* Constructor. Initializes the linked list. */
Deck::Deck(void) {
    /* Fill the deck. */
    for(int suit = Card::SPADE; suit < Card::NUM_SUITS; suit++) {
        for(int value = Card::KING; value < Card::NUM_VALUES; value++) {
            this->list.add(Card((Card::suit_t)suit, (Card::value_t)value));
            this->size++;
        }
    }

    /* The deck should be at its max size on startup. If it isn't something went wrong during initialization. */
    if(this->size != this->DECK_MAX_SIZE) {
        std::cout << "WARNING: Deck initialization may have failed, since current deck size is less than DECK_MAX_SIZE." << std::endl;
    }
}

/* Destructor. Frees the linked list. */
Deck::~Deck(void) {
    this->list.destroy();
    this->size = 0;
}

/* Prints out the entire list of cards. */
void Deck::print(void) {
    this->list.print();
}