#pragma once

#include <iostream>

class Card {

    public:
        /* Enum to store the different possible suit options. */
        typedef enum {
            SPADE,
            HEART,
            DIAMOND,
            CLUB,

            NUM_SUITS // Total number of suit options.
        } suit_t;
        static constexpr const char* suitToString(suit_t suit); // Converts a suit_t enum value to a string.

        /* Enum to store the different possible card values. */
        typedef enum {
            KING,
            QUEEN,
            JACK,
            TEN,
            NINE,
            EIGHT,
            SEVEN,
            SIX,
            FIVE,
            FOUR,
            THREE,
            TWO,
            ACE,

            NUM_VALUES // Total number of value options.
        } value_t;
        static constexpr const char* valueToString(value_t value); // Converts a value_t enum value to a string.

        /* Constructor. */
        Card(suit_t suit, value_t value);

        /* API */
        void setValue(value_t value); // Sets the card's value.
        void setSuit(suit_t suit);    // Sets the card's suit.
        value_t getValue(void) const; // Returns the card's value.
        suit_t getSuit(void) const;   // Returns the card's suit.
        
        /* Overloaded << to allow for printing. */
        friend std::ostream& operator<<(std::ostream& os, const Card& card);

    private:
        suit_t suit;   // The card's suit.
        value_t value; // The card's value.

};