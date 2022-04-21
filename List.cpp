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

}

Node* List::pop_front() noexcept {
    //@todo add validation
    if( head == nullptr )
        return nullptr; //list is empty

    Node *tempNode = head;
    head = head->next;
    count--;

    delete tempNode;

    //@todo add validation

    return head;
}
void List::dump() const noexcept {
    FORMAT_LINE_FOR_DUMP("List", "Head");
    for (Node *currentNode = head; currentNode != nullptr; currentNode = currentNode->next) {
        currentNode->dump();
    }
}

bool List::validate() const noexcept {

}

Node* List::get_next(const Node *currentNode) {
    if( currentNode == nullptr )
        throw std::invalid_argument( PROGRAM_NAME "currentNode is null");
    else
        return currentNode->next;
}

