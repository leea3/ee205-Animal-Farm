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

#include <cassert>
#include <iostream>
#include "addCats.h"
#include "Cat.h"
#include "catDatabase.h"
#include "reportCats.h"
#include "deleteCats.h"
#include "config.h"

using namespace std;

int main() {
    cout << "Starting " << PROGRAM_NAME << endl ;

    cout << numberOfCats << endl;
    addCat( new Cat("Loki", Cat::MALE, Cat::PERSIAN, 1.0 )) ;
    addCat( new Cat( "Milo", Cat::MALE, Cat::MANX , 1.1 )) ;
    addCat( new Cat( "Bella", Cat::FEMALE, Cat::MAINE_COON, 1.2 )) ;
    addCat( new Cat( "Kali", Cat::FEMALE, Cat::SHORTHAIR, 1.3 )) ;
    addCat( new Cat( "Trin", Cat::FEMALE, Cat::MANX, 1.4 )) ;
    addCat( new Cat( "Chili", Cat::MALE, Cat::SHORTHAIR, 1.5 )) ;
    //printAllCats();
    Cat* Kali = findCatByName("Kali");
    deleteCat( Kali );
    printAllCats();
    deleteAllCats();
    printAllCats();


    /*
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

