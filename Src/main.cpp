#include <iostream>
#include "card.hpp"
#include "linked_list.tpp"

int main(void) {
    Card card(Card::CLUB, Card::TWO);

    std::cout << card << std::endl;

    LinkedList<int> list;
    std::cout << "got here" << std::endl;
    list.add(1);
    list.add(2);
    list.add(3);
    list.print();

    int* thing = list.get(2);
    *thing = 12;
    list.print();
    return 0;
}