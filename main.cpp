///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <iostream>
#include "addCats.h"
#include "Cat.h"
#include "catDatabase.h"
#include "reportCats.h"
#include "updateCats.h"
#include "deleteCats.h"
#include "config.h"

using namespace std;

int main() {
    cout << "Starting " << PROGRAM_NAME << endl ;

    cout << numberOfCats << endl;
    addCat( new Cat("Loki", Cat::MALE, Cat::PERSIAN, 1.0 )) ;
    cout << numberOfCats << endl;
    printAllCats();
    /*
    addCat( "Milo", MALE, MANX, true, 7.0, BLACK, RED, 102 ) ;
    addCat( "Bella", FEMALE, MAINE_COON, true, 18.2, BLACK, BLUE, 103 ) ;
    addCat( "Kali", FEMALE, SHORTHAIR, false, 9.2, BLACK, GREEN, 104 ) ;
    addCat( "Trin", FEMALE, MANX, true, 12.2, BLACK, PINK, 105 ) ;
    addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLACK, 106 ) ;

#ifdef DEBUG
    // Test for empty name
    assert( addCat( "", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, BLACK, WHITE, 101 ) == BAD_CAT ) ;
    // Test for max name
    assert( addCat( MAX_NAME1, UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, RED, 107 ) != BAD_CAT ) ;
    // Test for name too long
    assert( addCat( ILLEGAL_NAME, UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLUE, 108 ) == BAD_CAT ) ;
    // Test for duplicate cat name
    assert( addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 0, WHITE, GREEN, 109 ) == BAD_CAT ) ;
    // Test for weight <= 0
    assert( addCat( "Neo", UNKNOWN_GENDER, SHORTHAIR, false, 0, WHITE, PINK, 110 ) == BAD_CAT ) ;
    // Test for printCat( -1 ) ;
    printCat( -1 ) ;
    // Test for out of bounds
    printCat( 2000 ) ;
    // Test finding a cat...
    assert( findCat( "Bella" ) == 2 ) ;
    // Test not finding a cat
    //assert( findCat( "Bella's not here" ) == BAD_CAT ) ;
    // Test addCat details
    size_t testCat = addCat( "Oscar", UNKNOWN_GENDER, SHORTHAIR, false, 1.1, RED, BLACK, 111 ) ;
    printCat( testCat );
    assert( testCat != ERROR );
    assert( testCat < MAX_CATS );
    // Test setting a large name
    assert( updateCatName( testCat, MAX_NAME2 ) == NOERROR ) ;
    printCat( testCat ) ;
    // Test setting an out-of-bounds name
    assert( updateCatName( testCat, ILLEGAL_NAME ) == ERROR ) ;
    printCat( testCat ) ;
    // Test setting an illegal cat weight
    assert( updateCatWeight( testCat, -1 ) == ERROR ) ;
#endif

    printAllCats() ;
    int kali = findCat( "Kali" ) ;
    assert( updateCatName( kali, "Chili" ) == ERROR ) ; // duplicate cat name should fail
    printCat( kali ) ;
    assert( updateCatName( kali, "Capulet" ) == NOERROR ) ;
    assert( updateCatWeight( kali, 9.9 ) == NOERROR ) ;
    assert( fixCat( kali ) == NOERROR ) ;
    assert( updateCatCollar1( kali, GREEN ) == NOERROR ) ;
    assert( updateCatCollar2( kali, GREEN ) == NOERROR ) ;
    assert( updateCatLicense( kali, 201 ) == NOERROR ) ;
    printCat( kali ) ;
    printAllCats() ;
    deleteAllCats() ;
    printAllCats() ;
     */
    cout << "Done with " << PROGRAM_NAME << endl ;
    return( 0 ) ;
}

