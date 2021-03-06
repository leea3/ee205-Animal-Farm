///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Node.cpp
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Node.h"
#include "config.h"
#include "List.h"
#include<iostream>

void Node::dump() const noexcept {
    PRINT_HEADING_FOR_DUMP;
    FORMAT_LINE_FOR_DUMP( "Node", "this" ) << this << std::endl;
    FORMAT_LINE_FOR_DUMP( "Node" , "next" ) << next << std::endl;
}


bool Node::validate() const noexcept {
    return true;
}

bool Node::operator>(const Node &rightSide) {
    return (this > &rightSide);
}


bool Node::compareByAddress(const Node *node1, const Node *node2) {
    if( node1 > node2 )
        return true;
    else
        return false;
}