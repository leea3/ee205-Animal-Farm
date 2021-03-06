///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Node.h
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

class Node {
    friend class List;
    friend class SinglyLinkedList;
protected:
    Node* next;

public:
    virtual void dump() const noexcept;
    virtual bool validate() const noexcept;
    virtual bool operator> ( const Node &rightSide );

protected:
    static bool compareByAddress( const Node *node1, const Node *node2);

};

