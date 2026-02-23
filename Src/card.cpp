#include "card.hpp"

//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #2 Flip Cards-a Upload Link
// Source file for the card class.
//

/* Helper function to convert a suit_t enum value into a string. */
constexpr const char* Card::suitToString(suit_t suit) {
    /* Constexpr lookup table for converting enum values to strings. */
    constexpr const char* suits[Card::NUM_SUITS] {
        "SPADE",    // Card::SPADE
        "HEART",    // Card::HEART
        "DIAMOND",  // Card::DIAMOND
        "CLUB"      // Card::CLUB
    };
    return suits[suit];
}

/* Helper function to convert a value_t enum value into a string. */
constexpr const char* Card::valueToString(value_t value) {
    constexpr const char* values[Card::NUM_VALUES] {
        "KING",   // Card::KING
        "QUEEN",  // Card::QUEEN
        "JACK",   // Card::JACK
        "TEN",    // Card::TEN
        "NINE",   // Card::NINE
        "EIGHT",  // Card::EIGHT
        "SEVEN",  // Card::SEVEN
        "SIX",    // Card::SIX
        "FIVE",   // Card::FIVE
        "FOUR",   // Card::FOUR
        "THREE",  // Card::THREE
        "TWO",    // Card::TWO
        "ACE"     // Card::ACE
    };
    return values[value];
}

/* Sets up the Card object w/ the configured suit/value options. */
Card::Card(suit_t suit, value_t value) {
    this->suit = suit;
    this->value = value;
}

/* Sets the card's value. */
void Card::setValue(value_t value) {
    this->value = value;
}

/* Sets the card's suit. */
void Card::setSuit(suit_t suit) {
    this->suit = suit;
}

/* Gets the card's value. */
Card::value_t Card::getValue(void) const {
    return this->value;
}

/* Gets the card's suit. */
Card::suit_t Card::getSuit(void) const {
    return this->suit;
}

/* Overloaded << to allow for printing. */
std::ostream& operator<<(std::ostream& os, const Card& card) {
    os << Card::valueToString(card.value) << " of " << Card::suitToString(card.suit) << "S";
    return os;
}