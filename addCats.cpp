///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include "addCats.h"
#include "config.h"
#include "catDatabase.h"

void addCat( Cat* newCat ){

    assert( validateDatabase() == NOERROR ); //check if database is healthy
    newCat -> Cat::validateCat(); //check if the cat entry is valid
    newCat -> next = catDatabaseHeadPointer;
    catDatabaseHeadPointer = newCat;
    numberOfCats++;

    assert( validateDatabase() == NOERROR );

}