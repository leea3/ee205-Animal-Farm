///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file List.cpp
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "List.h"

bool List::empty() const noexcept {
    if( head == nullptr )
        return true;
    else
        return false;
}

unsigned int List::size() const noexcept {
    return count;
}

bool List::isIn(Node *aNode) const {
    Node *currentNode = head;

    while ( currentNode != nullptr ) {
        if ( currentNode == aNode )
            return true;
        currentNode = currentNode->next;
    }
    return false;
}

bool List::isSorted() const noexcept {}
Node* List::get_first() const noexcept {}
void List::deleteAllNodes() noexcept {}
Node* List::pop_front() noexcept {}
void List::dump() const noexcept {}
bool List::validate() const noexcept {}
Node* List::get_next(const Node *currentNode) {}

