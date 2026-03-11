//
// Brian Mack, Juan Ipina, Blake Jackson, james Su
// Project #2 Flip Cards-b Upload Link
// Template class for LinkedList implementation
//
#pragma once

#include <iostream>
#include <vector>

/* Note: This isn't separated between a header and source file due to */
/* template use. */
template <typename T> class LinkedList
{
    public:
        LinkedList(void);
        // Constructor.

        ~LinkedList(void);
        // Destructor.

        void add(T data);
        // Creates a new node of type T, and fills it with `data`. This node
        // becomes the new head of the list.

        void appendNodeToBackOfList(typename LinkedList<T>::Node* node);
        // Appends the given node to the end of the list
        // assumptions - node is not part of another list

        typename LinkedList<T>::Node* detachFrontNodeFromList(void);
        // Removes and returns the first node in the list
        // returns - nullptr if the list is empty

        T* get(int index);
        // Returns a pointer to the data stored in the node at `index`. You
        // have direct access to this pointer and can use/modify the value as
        // you wish. You don't have access to the entire node though, and
        // can't free it.

        void destroy(void);
        // Deallocates the entire LinkedList.

        std::vector<T> toVector(void);
        // Returns a copy of the linked list as a vector.
        
        template <typename U> friend std::ostream& operator<<(
            std::ostream& os,
            const LinkedList<U>& list);
        // Overloaded << to allow for printing.

        /* Link list node struct. */
        struct Node
        {
            T data; // The data stored in the node.
            struct Node* next = nullptr; // The next node in the list. Is
                                         // nullptr by default.
        };
        Node* head = nullptr; // Head of the linked list. Is nullptr by default
        Node* tail = nullptr;
        // Used for tracking in appendNodeToBackOfList
};

/* IMPLEMENTATION */
template <typename T> LinkedList<T>::LinkedList(void)
/* Constructor. */
{
    return;
}

template <typename T> LinkedList<T>::~LinkedList(void)
/* Destructor. Lists should be completely freed when they go out of scope. */
{
    this->destroy();
}

template <typename T> void LinkedList<T>::add(T data)
/* Creates a new node with datatype T, and sets it as the new head.
 * parameters - data: value to store in the new node.
 */
{
    Node* node = new Node{data, this->head};

    // Create the new node with data and next pointer.
    node->data = data;
    node->next = this->head;
    this->head = node; // Set the current head to the new node.

    if (this->tail == nullptr)
    {
        this->tail = node;
    }
}

template <typename T>
void LinkedList<T>::appendNodeToBackOfList(
    typename LinkedList<T>::Node* node)
/* Appends the given node to the end of the list
 * parameters - node- the node to append
 * assumptions - cannot be a part of another list
 */
{
    if (node == nullptr)
    {
        return;
    }

    node->next = nullptr;

    if (this->tail == nullptr)
    {
        this->head = this->tail = node;
        return;
    }

    this->tail->next = node;
    this->tail = node;
} // end LinkedList::appendNodeToBackOfList

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::detachFrontNodeFromList(void)
/* Removes and returns the first node in the list
 * returns - pointer to the former head node
 * returns - nullptr if the list is empty
 */
{
    if (this->head == nullptr)
    {
        return nullptr;
    }

    Node* removed = this->head;
    this->head = this->head->next;

    if (this->head == nullptr)
    {
        this->tail = nullptr;
    }

    return removed;
} // end LinkedList::detachFrontNodeFromList

template <typename T> void LinkedList<T>::destroy(void)
/* Deallocates the entire LinkedList. */
{
    Node* current = this->head;
    Node* next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }

    this->head = nullptr; // Set head to nullptr to avoid dangling pointer
    this->tail = nullptr;
} // end LinkedList::destroy

template <typename T> T* LinkedList<T>::get(int index)
/* Gets a poitner to the data stored at a node.
 * parameters - index: zero-based index into the list.
 * assumptions - index >= 0.
 */
{
    Node* current = this->head;

    for (int i = 0; i < index; i++)
    {

        if (current == nullptr)
        {
            std::cout << "ERROR: Index does not exist in list." << std::endl;
            return nullptr;
        }

        current = current->next;
    }

    if (current == nullptr)
    {
        std::cout << "ERROR: Index does not exist in list." << std::endl;
        return nullptr;
    }

    return &current->data;
} // end LinkedList::get

template <typename T> std::ostream& operator<<(
    std::ostream& os,
    const LinkedList<T>& list)
/* Overloaded << to allow for printing the linked list.
 * parameters - os: output stream, list: list to print.
 * assumptions - os is valid.
 */
{
    os << "Printing linked list:" << std::endl;
    typename LinkedList<T>::Node* current = list.head;
    bool first = true;

    while (current != nullptr)
    {
        if (!first)
        {
            os << ",";
        }

        os << current->data;
        first = false;
        current = current->next;
    }

    os << std::endl;
    return os;
} // end operator<<

template <typename T> std::vector<T> LinkedList<T>::toVector(void)
/* Converts a linked list to a vector. */
{
    std::vector<T> v;
    Node* current = this->head;

    while (current != nullptr)
    {
        v.push_back(current->data);
        current = current->next;
    }

    return v;
} // end LinkedList::toVector
