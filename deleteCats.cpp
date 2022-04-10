///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include <cassert>
#include <iostream>
#include "deleteCats.h"

using namespace std;

void deleteCat( Cat* targetCat ){
    Cat* currentCat = catDatabaseHeadPointer;
    Cat* prevCat = nullptr;
    assert( validateDatabase() == NOERROR );
    //If the targetCat is the first node
    if( targetCat == catDatabaseHeadPointer ){
        catDatabaseHeadPointer = catDatabaseHeadPointer -> next;
        delete targetCat;
        numberOfCats--;
        assert( validateDatabase() == NOERROR );
        return;
    }
    else {
        //general case
        while (currentCat != nullptr && currentCat != targetCat) {
            prevCat = currentCat;
            currentCat = currentCat->next;
        }
        if( currentCat == nullptr )
            throw std::invalid_argument(PROGRAM_NAME ": entered cat does not exist");

        prevCat->next = currentCat->next;
        delete targetCat; //deallocate memory
        numberOfCats--;
        assert( validateDatabase() == NOERROR );
        return;
    }
}

void deleteAllCats( ) {

    Cat* currentCat = catDatabaseHeadPointer;
    assert( validateDatabase() == NOERROR );

    while( currentCat != nullptr ){
        delete currentCat;
        currentCat = currentCat -> next;
    }
    catDatabaseHeadPointer = nullptr;
    numberOfCats = 0;
    assert( validateDatabase() == NOERROR );
    cout << PROGRAM_NAME << ": database has been wiped" << endl;


}