///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include <cassert>
#include <cstring>
#include "reportCats.h"
#include "Cat.h"
#include "catDatabase.h"
#include "config.h"

using namespace std;

void printAllCats(){
    Cat* currentCat = catDatabaseHeadPointer;

    validateDatabase(); //check if database is healthy
    while( currentCat != nullptr ){
        currentCat -> Cat::printCat();
        currentCat = currentCat -> next;
    }
}

Cat* findCatByName( const char* findName ) {
    Cat* currentCat = catDatabaseHeadPointer;
    validateDatabase();

    while( currentCat != nullptr ){
        if( strcmp( findName, currentCat -> getName() ) == 0)
            return currentCat;
        currentCat = currentCat -> next;
    }
    //if cat can't be found
    throw std::invalid_argument(PROGRAM_NAME ":  cannot find cat as it does not exist in the database");
}

const char* genderToString ( const enum Cat::Gender convertGender ) {
    switch (convertGender) {
        case Cat::UNKNOWN_GENDER: return "UNKNOWN GENDER";
        case Cat::MALE:           return "MALE";
        case Cat::FEMALE:         return "FEMALE";
        default:                  throw invalid_argument(PROGRAM_NAME ": Invalid Gender");
    }
}

const char* breedToString ( const enum Cat::Breed convertBreed ) {
    switch( convertBreed ){
        case Cat::UNKNOWN_BREED: return "UNKNOWN BREED";
        case Cat::MAINE_COON:    return "MAINE COON";
        case Cat::MANX:          return "MANX";
        case Cat::SHORTHAIR:     return "SHORTHAIR";
        case Cat::PERSIAN:       return "PERSIAN";
        case Cat::SPHYNX:        return "SPHYNX";
        default:                 throw invalid_argument( PROGRAM_NAME ": Invalid Breed" );
    }
}