//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #2 Flip Cards-a Upload Link
// Source file for the deck class.
//
#include "deck.hpp"
#include <algorithm>
#include <random>

Deck::Deck(void) : front(list.head)
/* Constructor. Initializes the linked list. */
{
    /* Fill the deck. */

    for (int suit = Card::SPADE; suit < Card::NUM_SUITS; suit++)
    {

        for (int value = Card::KING; value < Card::NUM_VALUES; value++)
        {
            this->list.add(Card((Card::suit_t)suit, (Card::value_t)value));
            this->size++;
        }
    }

    /* The deck should be at its max size on startup. If it isn't something */
    /* went wrong during initialization. */

    if (this->size != this->DECK_MAX_SIZE)
    {
        std::cout << "WARNING: Deck initialization may have failed, since "
                     "current deck size is less than DECK_MAX_SIZE."
                  << std::endl;
    }
} // end Deck::Deck

Deck::~Deck(void)
/* Destructor. Frees the linked list. */
{
    this->list.destroy();
    this->size = 0;
}

std::ostream& operator<<(std::ostream& os, const Deck& deck)
/* Overloaded << to allow for printing the deck.
 * parameters - os: output stream, deck: deck to print.
 * assumptions - os is valid.
 */
{
    os << deck.list;
    return os;
}

void Deck::shuffle(void)
/* Suffles the order of the deck. */
{
    std::vector<Card> cards = this->list.toVector();

    // Convert linked list into a vector.

    /* Shuffle the vector. */
    std::random_device rd;
    std::mt19937 mt(rd());
    std::shuffle(cards.begin(), cards.end(), mt);

    /* Put vector back into linked list. */
    LinkedList<Card>::Node* current = this->list.head;

    for (int i = 0; i < cards.size(); i++)
    {

        if (current == nullptr)
        {
            std::cout << "ERROR: Size inconsistency between vector and linked "
                         "list while resizing. There might be a bug in "
                         "LinkedList::toVector()."
                      << std::endl;
            return;
        }

        current->data = cards[i];
        current = current->next;
    }
} // end Deck::shuffle