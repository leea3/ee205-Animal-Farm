///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file List.h
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include"Node.h"

class List {
protected:
    Node* head;
    unsigned int count = 0;

public: //methods
    //returns whether the linked list is empty or not
    bool empty() const noexcept;
    //returns number of nodes in linked list
    unsigned int size() const noexcept;
    bool isIn( Node *aNode) const;
    bool isSorted() const noexcept;
    Node* get_first() const noexcept;
    void deleteAllNodes() noexcept;
    virtual Node* pop_front() noexcept = 0;
    virtual void dump() const noexcept = 0;
    virtual bool validate() const noexcept = 0;
    static Node* get_next( const Node *currentNode);

};