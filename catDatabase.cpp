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

#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "catDatabase.h"

//linked list head pointer
Cat* catDatabaseHeadPointer = nullptr;

//stored number of cats in database as global variables
NumCats numberOfCats;

bool validateDatabase(){
    Cat* checkCat = catDatabaseHeadPointer;
    while( checkCat != nullptr ){
        assert( checkCat -> Cat::validateCat() == NOERROR );
        checkCat = checkCat -> next;
    }
    return NOERROR;
}

/*

//allocate memory to struct
struct cat_database catabase[MAX_CATS];

//initializes database based off MAX_CATS
void initializeDatabase( ) {
    numberOfCats= 0;

    for( int i = 0 ; i < MAX_CATS ; i++ ) {
        memset(catabase[i].name , '-' , 10 );
        catabase[i].gender                  = UNKNOWN_GENDER;
        catabase[i].breed                   = UNKNOWN_BREED;
        catabase[i].fixed                   = false;
        catabase[i].weight                  = 0.0;
        catabase[numberOfCats].collarColor1 = BLACK;
        catabase[numberOfCats].collarColor2 = WHITE;
        catabase[numberOfCats].license      = 000;
    }
}

*/
