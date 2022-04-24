#include "Node.h"

///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.h
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Node.h"
#include "List.h"

class SinglyLinkedList : public List {
public: //constructors
    SinglyLinkedList();

public: //methods
    void push_front(Node* newNode);
    Node* pop_front() noexcept override;
    void insert_after( Node* currentNode , Node* newNode );
    void dump() const noexcept override;
    bool validate() const noexcept override;


};


