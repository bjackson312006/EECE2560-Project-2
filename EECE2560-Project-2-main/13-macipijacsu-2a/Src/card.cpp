//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #2 Flip Cards-a Upload Link
// Source file for the card class.
//
#include "card.hpp"

constexpr const char* Card::suitToString(suit_t suit)
/* Helper function to convert a suit_t enum value into a string.
 * parameters - suit: suit to convert to a string.
 * assumptions - suit is a valid Card::suit_t value.
 */
{

    /* Constexpr lookup table for converting enum values to strings. */
    constexpr const char* suits[Card::NUM_SUITS] =
    {
        "SPADE",    // Card::SPADE
        "HEART",    // Card::HEART
        "DIAMOND",  // Card::DIAMOND
        "CLUB"      // Card::CLUB
    };
    return suits[suit];
} // end Card::suitToString

constexpr const char* Card::valueToString(value_t value)
/* Helper function to convert a value_t enum value into a string.
 * parameters - value: value to convert to a string.
 * assumptions - value is a valid Card::value_t value.
 */
{

    constexpr const char* values[Card::NUM_VALUES] =
    {
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
} // end Card::valueToString

Card::Card(suit_t suit, value_t value)
/* Sets up the Card object w/ the configured suit/value options.
 * parameters - suit: card suit, value: card value.
 * assumptions - suit/value are valid enum values.
 */
{
    this->suit = suit;
    this->value = value;
}

void Card::setValue(value_t value)
/* Sets the card's value.
 * parameters - value: new card value.
 * assumptions - value is a valid Card::value_t value.
 */
{
    this->value = value;
}

void Card::setSuit(suit_t suit)
/* Sets the card's suit.
 * parameters - suit: new card suit.
 * assumptions - suit is a valid Card::suit_t value.
 */
{
    this->suit = suit;
}

Card::value_t Card::getValue(void) const
/* Gets the card's value. */
{
    return this->value;
}

Card::suit_t Card::getSuit(void) const
/* Gets the card's suit. */
{
    return this->suit;
}

std::ostream& operator<<(std::ostream& os, const Card& card)
/* Overloaded << to allow for printing.
 * parameters - os: output stream, card: card to print.
 * assumptions - os is valid.
 */
{
    os << Card::valueToString(card.value) << " of "
       << Card::suitToString(card.suit) << "S";
    return os;
}