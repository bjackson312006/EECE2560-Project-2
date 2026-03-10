//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #2 Flip Cards-b Upload Link
// Source file for the deck class.
//
#include "deck.hpp"
#include <algorithm>
#include <iostream>
#include <random>

/* Helper: returns new score after flipping the given card. */
static int scoreAfterFlip(int currentScore, const Card& card)
{
    const int heartBonus = (card.getSuit() == Card::HEART) ? 1 : 0;
    switch (card.getValue())
    {
        case Card::ACE:
            return currentScore + 10 + heartBonus;
        case Card::KING:
        case Card::QUEEN:
        case Card::JACK:
            return currentScore + 5 + heartBonus;
        case Card::TEN:
        case Card::NINE:
        case Card::EIGHT:
            return currentScore + 0 + heartBonus;
        case Card::SEVEN:
            return currentScore / 2 + heartBonus;
        case Card::SIX:
        case Card::FIVE:
        case Card::FOUR:
        case Card::THREE:
        case Card::TWO:
            return 0 + heartBonus;
        default:
            return currentScore;
    }
}

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

LinkedList<Card>::Node* Deck::deal(void)
/* Returns the top card node and removes it from the deck.
 * returns - pointer to the former top node, or nullptr if deck is empty.
 */
{
    LinkedList<Card>::Node* node = this->list.removeFront();
    if (node != nullptr)
    {
        this->size--;
    }
    return node;
} // end Deck::deal

void Deck::replace(LinkedList<Card>::Node* node)
/* Places the given card node on the bottom of the deck.
 * parameters - node: the card node to place on the bottom.
 * assumptions - node is not null and not part of this deck.
 */
{
    if (node == nullptr)
    {
        return;
    }
    this->list.addBack(node);
    this->size++;
} // end Deck::replace

bool Deck::isEmpty(void) const
/* Returns true if the deck has no cards. */
{
    return this->list.head == nullptr;
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

void playFlip(void)
/* Plays the Flip game: init deck, shuffle, draw 24 into hand, print, then
 * run the game (flip cards or end) and print results.
 */
{
    /* (1) Initialize a deck with 52 cards in order. */
    Deck deck;

    /* (2) Shuffle the deck and print all cards after shuffle. */
    deck.shuffle();
    std::cout << "Deck after shuffle:" << std::endl;
    std::cout << deck;

    /* (3) Draw and remove the top 24 cards; insert into the back of the hand. */
    Deck hand;
    for (int i = 0; i < 24; i++)
    {
        LinkedList<Card>::Node* node = deck.deal();
        if (node != nullptr)
        {
            hand.replace(node);
        }
    }

    /* (4) Print all cards in the hand and all remaining cards in the deck. */
    std::cout << "Current hand deck (24 cards):" << std::endl;
    std::cout << hand;
    std::cout << "Remaining deck:" << std::endl;
    std::cout << deck;

    /* (5) Start the game and print results. Print each flipped card. */
    std::cout << "--- Game start ---" << std::endl;
    int score = 0;
    char choice = ' ';

    while (choice != 'e' && choice != 'E')
    {
        if (hand.isEmpty())
        {
            std::cout << "No more cards in hand. Game over." << std::endl;
            break;
        }

        std::cout << "Flip next card (f) or End game (e)? ";
        std::cin >> choice;

        if (choice == 'f' || choice == 'F')
        {
            LinkedList<Card>::Node* node = hand.deal();
            if (node != nullptr)
            {
                std::cout << "Flipped: " << node->data << std::endl;
                score = scoreAfterFlip(score, node->data);
                std::cout << "Score: " << score << std::endl;
                delete node;
            }
        }
    }

    std::cout << "Final score: " << score << std::endl;
    std::cout << "--- Game end ---" << std::endl;
} // end playFlip
