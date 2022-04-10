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
#include <cstring>
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

#ifdef DEBUG
    cout << "starting debug, meow." << endl;

    //confirming if a cat created with Cat() is zeroed out
    Cat testCat = Cat();
    assert(testCat.getName() != nullptr );
    assert(strcmp(testCat.getName(), "") == 0);
    assert(testCat.getGender() == Cat::UNKNOWN_GENDER);
    assert(testCat.getBreed() == Cat::UNKNOWN_BREED);
    assert(testCat.getFixed() == false);
    assert(testCat.getWeight() == 0);
    assert(!testCat.getFixed());
    assert(testCat.validateCat() == ERROR); // default cat is invalid

    //test name with nullptr
    try {
        testCat.setName(nullptr);
        assert(false); // We should never get here
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    //test name with nothing
    try {
        testCat.setName("");
        assert(false); // We should never get here
    } catch (exception const &e) {
        cout << e.what() << endl;
    }

    testCat.setName("A");       // A 1 character name is valid
    testCat.setName(MAX_NAME1); // A MAX_NAME1 name is valid (50 characters)

    //test name w/ 51 characters
    try {
        testCat.setName(ILLEGAL_NAME);
        assert(false); // We should never get here
    } catch (exception const &e) {
        cout << e.what() << endl;
    }

    testCat.setGender(Cat::FEMALE); //set gender from a default cat

    //test gender change on an existing cat
    try {
        testCat.setGender(Cat::MALE);
        assert(false); // We should never get here
    } catch (exception const &e) {
        cout << e.what() << endl;
    }

    testCat.setBreed(Cat::MAINE_COON); //set breed from a default cat

    //test breed change on an existing cat
    try {
        testCat.setBreed(Cat::MANX);
        assert(false); // We should never get here
    } catch (exception const &e) {
        cout << e.what() << endl;
    }

    testCat.fixCat(); //fix default cat
    assert(testCat.getFixed());

    // Test for Weight <= 0
    try {
        testCat.setWeight(0);
        assert(false); // We should never get here
    } catch (exception const &e) {
        cout << e.what() << endl;
    }

    testCat.setWeight(1.0 / 1024); //test fraction weight
    assert(testCat.getWeight() == 1.0 / 1024); //test if the weight is set to previous line's weight

    assert(testCat.validateCat() == NOERROR);
    testCat.printCat() ;
#endif

    cout << numberOfCats << endl;
    addCat( new Cat("Loki", Cat::MALE, Cat::PERSIAN, 1.0 )) ;
    addCat( new Cat( "Milo", Cat::MALE, Cat::MANX , 1.1 )) ;
    addCat( new Cat( "Bella", Cat::FEMALE, Cat::MAINE_COON, 1.2 )) ;
    addCat( new Cat( "Kali", Cat::FEMALE, Cat::SHORTHAIR, 1.3 )) ;
    addCat( new Cat( "Trin", Cat::FEMALE, Cat::MANX, 1.4 )) ;
    addCat( new Cat( "Chili", Cat::MALE, Cat::SHORTHAIR, 1.5 )) ;

#ifdef DEBUG

    // Test finding a cat...
    Cat* bella = findCatByName("Bella");
    bella -> printCat();
    // Test not finding a cat
    try{
        findCatByName("Bella's not here");
    } catch (exception const &e){
        cout << e.what() << endl;
    }

    // Test deleting a cat...
    deleteCat(bella);
    try {
        deleteCat(bella); // Verify that Bella's not there
    } catch (exception const &e) {
        cout << e.what() << endl;
    }
    bella = nullptr;

    cout << "done with debug, meow." << endl;
#endif
    printAllCats();
    deleteAllCats();
    printAllCats();

    cout << "Done with " << PROGRAM_NAME << endl ;
    return( 0 ) ;
}

