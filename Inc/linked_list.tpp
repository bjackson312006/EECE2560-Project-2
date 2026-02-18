#include <iostream>

template <typename T> class LinkedList {
    public:
        LinkedList(void); // Constructor.
        ~LinkedList(void); // Destructor.

        void add(T data);   // Creates a new node of type T, and fills it with `data`. This node becomes the new head of the list.
        T* get(int index);  // Returns a pointer to the data stored in the node at `index`. You have direct access to this pointer and can use/modify the value as you wish. You don't have access to the entire node though, and can't free it.
        void destroy(void); // Deallocates the entire LinkedList.
        void print(void);   // Prints the linked list.
    private:
        /* Link list node struct. */
        struct Node {
            T data = 0; // The data stored in the node.
            struct Node* next = nullptr; // The next node in the list. Is nullptr by default.
        };

        Node* head = nullptr;      // Head of the linked list. Is nullptr by default
};

/* IMPLEMENTATION */
/* Constructor. */
template <typename T> LinkedList<T>::LinkedList(void) {
    return;
}

/* Destructor. Lists should be completely freed when they go out of scope. */
template <typename T> LinkedList<T>::~LinkedList(void) {
    this->destroy();
}

/* Creates a new node with datatype T, and sets it as the new head. */
template <typename T> void LinkedList<T>::add(T data) {
    Node* node = new Node;   // Create the new node.
    node->data = data;       // File node with the data.
    node->next = this->head; // Set node->next to the current head.
    this->head = node;       // Set the current head to the new node.
    std::cout << "Added node with value " << data << std::endl;
}

/* Deallocates the entire LinkedList. */
template <typename T> void LinkedList<T>::destroy(void) {
    Node* current = this->head;
    Node* next = nullptr;
    while(current != nullptr) {
        std::cout << "Deleting node with value " << current->data << std::endl;
        next = current->next;
        delete current;
        current = next;
    }
}

/* Gets a poitner to the data stored at a node. */
template <typename T> T* LinkedList<T>::get(int index) {
    Node* current = this->head;
    for(int i = 0; i <= index; i++) {
        if(current == nullptr) {
            std::cout << "ERROR: Index does not exist in list." << std::endl;
            return nullptr;
        }
        current = current->next;
    }
    return current;
}

/* Prints the linked list. */
template <typename T> void LinkedList<T>::print(void) {
    std::cout << "Printing linked list:" << std::endl;
    Node* current = this->head;
    while(current != nullptr) {
        std::cout << current->data << ",";
        current = current->next;
    }
    std::cout << std::endl;
}