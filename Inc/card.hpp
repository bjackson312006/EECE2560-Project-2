//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #2 Flip Cards-a Upload Link
// Header for the card class (to model different playing cards).
//
#pragma once

#include <iostream>

/*
*   Note: Used enums for the suit and values (rather than storing them as
*         strings) to enforce the possible options (i.e., it's harder to
*         accidentally create a card that doesn't exist). Doing this is kind
*         of gross when you need to print out suits or values, but the lookup
*         tables should be able to convert the enum types to strings fairly
*         quickly. Also, it's probably (?) slightly more space efficient to
*         store them as enums since they're just integers.
*/
class Card
{

    public:
        typedef enum
        /* Enum to store the different possible suit options. */
        {
            SPADE,
            HEART,
            DIAMOND,
            CLUB,

            NUM_SUITS // Total number of suit options.
        } suit_t;
        static constexpr const char* suitToString(suit_t suit);
        // Converts a suit_t enum value to a string.

        typedef enum
        /* Enum to store the different possible card values. */
        {
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
        static constexpr const char* valueToString(value_t value);
        // Converts a value_t enum value to a string.

        Card(suit_t suit, value_t value);
        // Constructor.

        void setValue(value_t value);
        // Sets the card's value.

        void setSuit(suit_t suit);
        // Sets the card's suit.

        value_t getValue(void) const;
        // Returns the card's value.

        suit_t getSuit(void) const;
        // Returns the card's suit.
        
        friend std::ostream& operator<<(std::ostream& os, const Card& card);
        // Overloaded << to allow for printing.

    private:
        suit_t suit;   // The card's suit.
        value_t value; // The card's value.

};