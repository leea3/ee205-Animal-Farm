///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.cpp
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "SinglyLinkedList.h"
#include "config.h"
#include "List.h"
#include<cassert>

SinglyLinkedList::SinglyLinkedList() = default;

void SinglyLinkedList::push_front(Node *newNode) {

    if( newNode == nullptr )
        throw std::invalid_argument( PROGRAM_NAME ": push_front failed as newNode is null.");
    if( newNode->validate() == false )
        throw std::domain_error( PROGRAM_NAME ": push_front failed as newNode is invalid.");
    if( isIn( newNode ) == true )
        throw std::logic_error( PROGRAM_NAME ": push_front failed as newNode is already in the container.");

    if( head == nullptr ){
        newNode->next = nullptr;
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    count++;
    assert( validate() );

}

void SinglyLinkedList::insert_after(Node *currentNode, Node *newNode) {
    assert( validate() );

    //series of validation checks
    if( List::empty() == true )
        throw std::logic_error(PROGRAM_NAME ": insert_after failed as list is empty.");
    if( currentNode == nullptr )
        throw std::invalid_argument( PROGRAM_NAME ": insert_after failed as currentNode is null.");
    if( newNode == nullptr )
        throw std::invalid_argument( PROGRAM_NAME ": insert_after failed as newNode is null.");
    if( List::isIn(currentNode) == false )
        throw std::logic_error( PROGRAM_NAME ": insert_after failed as currentNode is not in the list");
    if( newNode -> validate() == false )
        throw std::domain_error( PROGRAM_NAME ": insert_after failed as newNode is not valid.");
    if( List::isIn( newNode ) == true )
        throw std::logic_error( PROGRAM_NAME ": insert_after failed as newNode is already in the list.");

    newNode->next = currentNode->next;
    currentNode->next = newNode;

    count++;

    assert( validate() );
}

Node* SinglyLinkedList::pop_front() noexcept {
    assert( validate() );
    if( head == nullptr )
        return nullptr; //list is empty

    //Node *tempNode = head;
    head = head->next;
    count--;

    //delete tempNode;

    assert( validate() );

    return head;
}

void SinglyLinkedList::dump() const noexcept {
    std::cout << "SinglyLinkedList: head = [" << head << "]" << std::endl;
    for (Node *currentNode = head; currentNode != nullptr; currentNode = currentNode->next) {
        currentNode->dump();
    }
}


bool SinglyLinkedList::validate() const noexcept {
    //check for inconsistencies if the linked list is empty/not empty
    if ( head == nullptr && (count != 0  || empty() == false) )
        return false;
    if ( head != nullptr && (count == 0 || empty() == true ) )
        return false;

    //tortoise and hare algorithm to detect infinite loops
    Node* tortoise = head;
    Node* hare = head;
    while (tortoise->next != NULL && hare->next->next != NULL)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (tortoise == hare) //executes if there's a loop
            return false;
    }

    //check if number of nodes in linked list is consistent with count
    unsigned int countNumberOfNodes = 0;
    Node* tempNode = head;
    while( tempNode != nullptr ) {
        countNumberOfNodes++;
        tempNode = tempNode->next;
    }
    if ( count != countNumberOfNodes )
        return false;

    return true;
}
