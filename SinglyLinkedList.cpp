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

Node* SinglyLinkedList::pop_front() noexcept {
    //@todo add validation
    if( head == nullptr )
        return nullptr; //list is empty

    Node *tempNode = head;
    head = head->next;
    count--;

    //delete tempNode;

    //@todo add validation

    return head;
}

void SinglyLinkedList::dump() const noexcept {
    FORMAT_LINE_FOR_DUMP("List", "Head");
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