#include "card.hpp"

/* Helper function to convert a suit_t enum value into a string. */
constexpr const char* Card::suitToString(suit_t suit) {
    /* Constexpr lookup table for converting enum values to strings. */
    constexpr const char* suits[Card::NUM_SUITS] {
        [Card::CLUB] = "CLUB",
        [Card::DIAMOND] = "DIAMOND",
        [Card::HEART] = "HEART",
        [Card::SPADE] = "SPADE"
    };
    return suits[suit];
}

/* Helper function to convert a value_t enum value into a string. */
constexpr const char* Card::valueToString(value_t value) {
    constexpr const char* values[Card::NUM_VALUES] {
        [Card::TWO] = "TWO",
        [Card::THREE] = "THREE",
        [Card::FOUR] = "FOUR",
        [Card::FIVE] = "FIVE",
        [Card::SIX] = "SIX",
        [Card::SEVEN] = "SEVEN",
        [Card::EIGHT] = "EIGHT",
        [Card::NINE] = "NINE",
        [Card::TEN] = "TEN",
        [Card::JACK] = "JACK",
        [Card::QUEEN] = "QUEEN",
        [Card::KING] = "KING",
        [Card::ACE] = "ACE"
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
    os << Card::suitToString(card.suit) << " of " << Card::valueToString(card.value) << "S";
    return os;
}