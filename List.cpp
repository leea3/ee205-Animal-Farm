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
#include "config.h"

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

bool List::isSorted() const noexcept {
}

Node* List::get_first() const noexcept {
    return head;
}

void List::deleteAllNodes() noexcept {
    //@todo add validation
    while( head != nullptr )
        pop_front();
}

bool List::validate() const noexcept {

}

Node* List::get_next(const Node *currentNode) {
    if( currentNode == nullptr )
        throw std::invalid_argument( PROGRAM_NAME "currentNode is null");
    else
        return currentNode->next;
}

