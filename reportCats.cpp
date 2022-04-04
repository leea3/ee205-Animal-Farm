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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reportCats.h"

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

const char* genderToString ( const enum Gender convertGender ) {
    switch( convertGender ){
        case UNKNOWN_GENDER: return "UNKNOWN GENDER";
        case MALE:           return "MALE";
        case FEMALE:         return "FEMALE";
        default:             fprintf(stderr, "%s: Error, Invalid Gender", __FILE__);
            break;
    }
    return 0;
}

const char* breedToString ( const enum Breed convertBreed ) {
    switch( convertBreed ){
        case UNKNOWN_BREED: return "UNKNOWN BREED";
        case MAINE_COON:    return "MAINE COON";
        case MANX:          return "MANX";
        case SHORTHAIR:     return "SHORTHAIR";
        case PERSIAN:       return "PERSIAN";
        case SPHYNX:        return "SPHYNX";
        default:            fprintf(stderr, "%s: Error, Invalid Breed", __FILE__);
            break;
    }
    return 0;
}
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
