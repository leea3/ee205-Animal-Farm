///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "addCats.h"
#include "config.h"

int addCat(  const char                addName[]
        ,const enum                Gender addGender
        ,const enum                Breed addBreed
        ,const bool                addFixed
        ,const Weight              addWeight
        ,const enum                Color addCollar1
        ,const enum                Color addCollar2
        ,const unsigned long long  addLicense ){

    //validation checks
    if( isFull( ) == ERROR )                  return BAD_CAT;
    if( isValidName( addName ) == ERROR )     return BAD_CAT;
    if( isValidWeight( addWeight ) == ERROR ) return BAD_CAT;

    //add cat info to database
    strcpy(catabase[numberOfCats].name , addName);
    catabase[numberOfCats].gender       = addGender;
    catabase[numberOfCats].breed        = addBreed;
    catabase[numberOfCats].fixed        = addFixed;
    catabase[numberOfCats].weight       = addWeight;
    catabase[numberOfCats].collarColor1 = addCollar1;
    catabase[numberOfCats].collarColor2 = addCollar2;
    catabase[numberOfCats].license      = addLicense;

    numberOfCats++;

    return (numberOfCats - 1);

}

int isFull( ) {
    if( numberOfCats >= MAX_CATS ){

        fprintf( stderr, "%s: Error, cannot enter more cats (CAT LIMIT = [%d]) \n", __FILE__, MAX_CATS);
        return ERROR;

    }

    else return NOERROR;
}

int isValidName( const char checkName[] ) {
    //check if cat's name is not blank
    if( strlen( checkName ) == 0 ) {

        fprintf( stderr, "%s: Error, entered name is empty\n", __FILE__ );
        return ERROR;

    }

    //checks if cat's name is shorter than max limit
    if( strlen( checkName ) > CATNAME_CHARLIMIT ) {

        fprintf( stderr, "%s: Error, entered name is longer than %d characters\n", __FILE__, CATNAME_CHARLIMIT);
        return ERROR;

    }

    //checks for duplicate cat names
    for( int i = 0 ; i < numberOfCats ; i++ ) {

        if( strcmp( checkName , catabase[i].name ) == 0 ) {

            fprintf( stderr, "%s: Error, entered name [%s] is a duplicate of cat's name in index [%d] \n", __FILE__, checkName , i);
            return ERROR;

        }
    }

    return NOERROR;

}

int isValidWeight( const Weight checkWeight ) {

    if( checkWeight <= 0.0 ){

        fprintf( stderr, "%s: Error, Entered invalid weight of %f\n", __FILE__ , checkWeight);
        return ERROR;

    }
    return NOERROR;
}

