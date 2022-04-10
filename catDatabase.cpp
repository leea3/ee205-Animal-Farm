///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include "catDatabase.h"

//linked list head pointer
Cat* catDatabaseHeadPointer = nullptr;

//stored number of cats in database as global variables
NumCats numberOfCats;

bool validateDatabase(){
    Cat* checkCat = catDatabaseHeadPointer;
    while( checkCat != nullptr ){
        assert( (checkCat -> Cat::validateCat() == NOERROR) && "There is something wrong with the database\n");
        checkCat = checkCat -> next;
    }
    return NOERROR;
}