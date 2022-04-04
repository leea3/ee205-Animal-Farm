///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file updateCats.cpp
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "updateCats.h"
#include "addCats.h"
#include "config.h"

int updateCatName( const int  index
        ,const char newCatName[] ) {

    if( isValidName( newCatName ) == ERROR ) return ERROR;

    if( isIndexValid( index ) == ERROR ) return ERROR;


    strcpy(catabase[index].name, newCatName);
    printf("cat at index [%d] has a new name: [%s]\n", index, catabase[index].name);
    return NOERROR;

}

int fixCat( const int index ) {

    if( isIndexValid( index ) == ERROR ) return ERROR;

    catabase[index].fixed = true;    //You can't unfix a cat
    printf("[%s] at index [%d] has been fixed\n", catabase[index].name , index);
    return NOERROR;

}

int updateCatWeight( const int    index
        ,const Weight newCatWeight ) {

    if( isValidWeight( newCatWeight ) == ERROR ) return ERROR;
    else if( isIndexValid( index ) == ERROR ) return ERROR;

    else {
        catabase[index].weight = newCatWeight;
        printf("[%s] at index [%d] has a new weight of %f\n", catabase[index].name, index, catabase[index].weight);
        return NOERROR;
    }

}

int updateCatCollar1( const int  index
        ,const enum Color newCollarColor1 ) {

    if( isIndexValid( index ) == ERROR ) return ERROR;
    catabase[index].collarColor1 = newCollarColor1;
    return NOERROR;

}

int updateCatCollar2( const int  index
        ,const enum Color newCollarColor2 ) {

    if( isIndexValid( index ) == ERROR ) return ERROR;
    catabase[index].collarColor2 = newCollarColor2;
    return NOERROR;

}

int updateCatLicense( const int                index
        ,const unsigned long long updatedLicense ) {

    if( isIndexValid( index ) == ERROR ) return ERROR;
    catabase[index].license = updatedLicense;
    return NOERROR;

}

int isIndexValid( const int index ) {
    if( (index < 0) || (index > numberOfCats - 1) ){
        fprintf( stderr, "%s: Error, entered Index [%d] does not exist\n", __FILE__, index);
        return ERROR;
    }
    else return NOERROR;
}
