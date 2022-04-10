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

#include <stdio.h>
#include <string.h>
#include <stdexcept>
#include <assert.h>
#include <iostream>
#include "updateCats.h"
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
        return;
    }
}

void deleteAllCats( ) {

    Cat* currentCat = catDatabaseHeadPointer;
    assert( validateDatabase() == 0 );

    while( currentCat != nullptr ){
        delete currentCat;
        currentCat = currentCat -> next;
    }
    catDatabaseHeadPointer = nullptr;
    cout << PROGRAM_NAME << ": database has been wiped" << endl;

}

/*
void deleteCat( const int index ) {

    if( isIndexValid(index) == 0 ) { //checks if inputted index is occupied by a cat
        for ( int i = index ; i < MAX_CATS - 1; i++ ) {
            strcpy( catabase[i].name ,  catabase[i+1].name );
            catabase[i].gender        = catabase[i+1].gender;
            catabase[i].breed         = catabase[i+1].breed;
            catabase[i].fixed         = catabase[i+1].fixed;
            catabase[i].weight        = catabase[i+1].weight;
            catabase[i].collarColor1  = catabase[i+1].collarColor1;
            catabase[i].collarColor2  = catabase[i+1].collarColor2;
            catabase[i].license       = catabase[i+1].license;
        }
        numberOfCats--;
    }
    else fprintf( stderr, "%s: Error, cannor delete cat at index [%d]\n", __FILE__, index);
}

*/