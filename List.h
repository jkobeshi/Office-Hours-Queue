#ifndef LIST_H
#define LIST_H
/* List.h
 *
 * doubly-linked, double-ended list with Iterator interface
 * Project UID c1f28c309e55405daf00c565d57ff9ad
 * EECS 280 Project 4
 */

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL


template <typename T>
class List {
    //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:

    //Defaul Constructor
    List();

    //Big Three
    List(const List& other);

    ~List();

    List& operator=(const List& rhs);

    //EFFECTS:  returns true if the list is empty
    bool empty() const;

    //EFFECTS: returns the number of elements in this List
    //HINT:    Traversing a list is really slow.  Instead, keep track of the size
    //         with a private member variable.  That's how std::list does it.
    int size() const;

    //REQUIRES: list is not empty
    //EFFECTS: Returns the first element in the list by reference
    T& front();

    //REQUIRES: list is not empty
    //EFFECTS: Returns the last element in the list by reference
    T& back();

    //EFFECTS:  inserts datum into the front of the list
    void push_front(const T& datum);

    //EFFECTS:  inserts datum into the back of the list
    void push_back(const T& datum);

    //REQUIRES: list is not empty
    //MODIFIES: may invalidate list iterators
    //EFFECTS:  removes the item at the front of the list
    void pop_front();

    //REQUIRES: list is not empty
    //MODIFIES: may invalidate list iterators
    //EFFECTS:  removes the item at the back of the list
    void pop_back();

    //MODIFIES: may invalidate list iterators
    //EFFECTS:  removes all items from the list
    void clear();

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Lists

private:
    //a private type
    struct Node {
        Node* next;
        Node* prev;
        T datum;
    };

    //REQUIRES: list is empty
    //EFFECTS:  copies all nodes from other to this
    void copy_all(const List<T>& other);

    int elts_size;
    Node* first;   // points to first Node in list, or nullptr if list is empty
    Node* last;    // points to last Node in list, or nullptr if list is empty

public:
    ////////////////////////////////////////
    class Iterator {
        //OVERVIEW: Iterator interface to List

        // You should add in a default constructor, destructor, copy constructor,
        // and overloaded assignment operator, if appropriate. If these operations
        // will work correctly without defining these, you can omit them. A user
        // of the class must be able to create, copy, assign, and destroy Iterators.

        // Your iterator should implement the following public operators: *,
        // ++ (prefix), default constructor, == and !=.
    public:
        Iterator();

        // This operator will be used to test your code. Do not modify it.
        // Requires that the current element is dereferenceable.
        Iterator& operator--() {
            assert(node_ptr);
            node_ptr = node_ptr->prev;
            return *this;
        }

        T& operator*() const;

        Iterator& operator++();

        bool operator==(Iterator rhs) const;
        bool operator!=(Iterator rhs) const;

    private:
        Node* node_ptr; //current Iterator position is a List node
        // add any additional necessary member variables here

        // add any friend declarations here
        friend class List;
        // construct an Iterator at a specific position
        Iterator(Node* p);

    };//List::Iterator
    ////////////////////////////////////////

    // return an Iterator pointing to the first element
    Iterator begin() const {
        return Iterator(first);
    }

    // return an Iterator pointing to "past the end"
    Iterator end() const;

    //REQUIRES: i is a valid, dereferenceable iterator associated with this list
    //MODIFIES: may invalidate other list iterators
    //EFFECTS: Removes a single element from the list container
    void erase(Iterator i);

    //REQUIRES: i is a valid iterator associated with this list
    //EFFECTS: inserts datum before the element at the specified position.
    void insert(Iterator i, const T& datum);

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.

template <typename T>
List<T>::List()
    : elts_size(0), first(nullptr), last(nullptr) {}

template <typename T>
List<T>::List(const List& other)
    : elts_size(0), first(nullptr), last(nullptr) {
    copy_all(other);
}

template <typename T>
List<T>::~List() {
    clear();
}

template <typename T>
List<T> & List<T>::operator=(const List& rhs) {
    if (this != &rhs) {
        clear();
        copy_all(rhs);
    }
    return *this;
}

//EFFECTS:  returns true if the list is empty
template<typename T>
bool List<T>::empty() const {
    return elts_size == 0 && first == nullptr && last == nullptr;
}

//EFFECTS: returns the number of elements in this List
//HINT:    Traversing a list is really slow.  Instead, keep track of the size
//         with a private member variable.  That's how std::list does it.
template<typename T>
int List<T>::size() const {
    return elts_size;
}

//REQUIRES: list is not empty
//EFFECTS: Returns the first element in the list by reference
template<typename T>
T& List<T>::front() {
    assert(!empty());
    return first->datum;
}

//REQUIRES: list is not empty
//EFFECTS: Returns the last element in the list by reference
template<typename T>
T& List<T>::back() {
    assert(!empty());
    return last->datum;
}

//EFFECTS:  inserts datum into the front of the list
template<typename T>
void List<T>::push_front(const T& datum) {
    Node* new_node = new Node;
    new_node->datum = datum;
    new_node->prev = nullptr;
    if (empty()) {
        new_node->next = nullptr;
        first = last = new_node;
    }
    else {
        new_node->next = first;
        first->prev = new_node;
        first = new_node;
    }
    elts_size++;
}

//EFFECTS:  inserts datum into the back of the list
template<typename T>
void List<T>::push_back(const T& datum) {
    Node* new_node = new Node;
    new_node->datum = datum;
    new_node->next = nullptr;
    if (empty()) {
        new_node->prev = nullptr;
        first = last = new_node;
    }
    else {
        new_node->prev = last;
        last->next = new_node;
        last = new_node;
    }
    elts_size++;
}

//REQUIRES: list is not empty
//MODIFIES: may invalidate list iterators
//EFFECTS:  removes the item at the front of the list
template<typename T>
void List<T>::pop_front() {
    assert(!empty());
    if (size() == 1) {
        Node* temp = first;
        first = last = nullptr;
        delete temp;
        elts_size--;
    }
    else if (size() > 1) {
        Node* temp = first;
        first = first->next;
        first->prev = nullptr;
        delete temp;
        elts_size--;
    }
}

//REQUIRES: list is not empty
//MODIFIES: may invalidate list iterators
//EFFECTS:  removes the item at the back of the list
template<typename T>
void List<T>::pop_back() {
    assert(!empty());
    if (size() == 1) {
        Node* temp = first;
        first = last = nullptr;
        delete temp;
        elts_size--;
    }
    else {
        Node* temp = last;
        last = last->prev;
        last->next = nullptr;
        delete temp;
        elts_size--;
    }
}

//MODIFIES: may invalidate list iterators
//EFFECTS:  removes all items from the list
template<typename T>
void List<T>::clear() {
    while (elts_size != 0) {
        pop_front();
    }
}

//REQUIRES: list is empty
//EFFECTS:  copies all nodes from other to this
template<typename T>
void List<T>::copy_all(const List<T>& other) {
    assert(empty());
    for (Node* n_ptr = other.first; n_ptr != nullptr; n_ptr = n_ptr->next) {
        push_back(n_ptr->datum);
    }
}

///////////////////////////////ITERATOR//////////////////////////
template <typename T>
List<T>::Iterator::Iterator()
    : node_ptr(nullptr) {}

template <typename T>
List<T>::Iterator::Iterator(Node* p)
    : node_ptr(p) {}

template <typename T>
T& List<T>::Iterator::operator*() const {
    assert(node_ptr);
    return node_ptr->datum;
}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++() {
    assert(node_ptr);
    node_ptr = node_ptr->next;
    return *this;
}

template <typename T>
bool List<T>::Iterator::operator==(Iterator rhs) const {
    return node_ptr == rhs.node_ptr;
}

template <typename T>
bool List<T>::Iterator::operator!=(Iterator rhs) const {
    return node_ptr != rhs.node_ptr;
}

// return an Iterator pointing to "past the end"
template <typename T>
typename List<T>::Iterator List<T>::end() const {
    return Iterator();
}

//REQUIRES: i is a valid, dereferenceable iterator associated with this list
//MODIFIES: may invalidate other list iterators
//EFFECTS: Removes a single element from the list container
template<typename T>
void List<T>::erase(Iterator i) {
    assert(i.node_ptr);
    if (i == begin()) {
        pop_front();
    }
    else if (i == Iterator(last)) {
        pop_back();
    }
    else if (size() > 2) {
        Node* temp = i.node_ptr;
        i.node_ptr->next->prev = i.node_ptr->prev;
        i.node_ptr->prev->next = i.node_ptr->next;
        i.node_ptr = i.node_ptr->next;
        elts_size--;
        delete temp;
    }
}

//REQUIRES: i is a valid iterator associated with this list
//EFFECTS: inserts datum before the element at the specified position.
template<typename T>
void List<T>::insert(Iterator i, const T& datum) {
    if (i == begin()) {
        push_front(datum);
    }
    else if (i == end()) {
        push_back(datum);
    }
    else if (size() > 2) {
        Node* new_node = new Node;
        new_node->datum = datum;
        new_node->prev = i.node_ptr->prev;
        new_node->next = i.node_ptr;
        i.node_ptr->prev->next = new_node;
        i.node_ptr->prev = new_node;
        elts_size++; 
    }
}
#endif // Do not remove this. Write all your code above this line.
