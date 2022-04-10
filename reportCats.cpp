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
#include <assert.h>
#include "reportCats.h"
#include "Cat.h"
#include "catDatabase.h"
#include "config.h"

using namespace std;

void printAllCats(){
    Cat* currentCat = catDatabaseHeadPointer;
    assert( validateDatabase() == NOERROR ); //check if database is healthy
    while( currentCat != nullptr ){
        currentCat -> Cat::printCat();
        currentCat = currentCat -> next;
    }
}

Cat* findCatByName( const char* findName ) {

}

/*

void printCat( const int index ) {
    if( (index < 0) | (index >= numberOfCats) ){
        fprintf( stderr, "%s: Error, Bad Cat [%d]\n", __FILE__, index);
    }
    else {
        printf("cat index = [%d]", index);
        printf(" name=[%s]"           , catabase[index].name);
        printf(" gender=[%s]"         , genderToString( catabase[index].gender) );
        printf(" breed=[%s]"          , breedToString( catabase[index].breed ) );
        printf(" isFixed=[%d]"        , catabase[index].fixed );
        printf(" weight=[%f]"         , catabase[index].weight );
        printf(" color1  = [%s]"      , colorToString( catabase[index].collarColor1 ) );
        printf(" color2 = [%s]"       , colorToString( catabase[index].collarColor2 ) );
        printf(" license = [%llu]\n"  , catabase[index].license );
    }
}

void printAllCats( ) {
    for( int i = 0 ; i < numberOfCats ; i++ ) printCat(i);
}

int findCat( const char findName[] ){
    for( int i = 0 ; i < numberOfCats ; i++ ) {
        if( strcmp( findName , catabase[i].name ) == 0) return i;
    }
    fprintf( stderr, "%s: Error, cannot find \"%s\" in database, exiting program...\n" , __FILE__, findName);
    exit( EXIT_FAILURE );
}
 */

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

 /*
const char* colorToString ( const enum Color convertColor ) {
    switch( convertColor ){
        case BLACK: return "BLACK";
        case WHITE: return "WHITE";
        case BLUE:  return "BLUE";
        case RED:   return "RED";
        case GREEN: return "GREEN";
        case PINK:  return "PINK";
        default:    fprintf(stderr, "%s: Error, Invalid Collar Color", __FILE__);
            break;
    }
    return 0;
}
*/