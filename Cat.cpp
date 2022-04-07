///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <assert.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "config.h"
#include "Cat.h"
#include "reportCats.h"

#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

using namespace std;

Cat::Cat() {

}

Cat::Cat(const char* newName,
         const Cat::Gender newGender,
         const Cat::Breed newBreed,
         const float newWeight) : Cat() {

            //set default values to new cats
            setName( newName );
            setGender( newGender );
            setBreed( newBreed );
            setWeight( newWeight );


    }

Cat::~Cat(){
    memset( name , 0 , 10 );
    gender     = UNKNOWN_GENDER;
    breed      = UNKNOWN_BREED;
    isFixed    = false;
    weight     = 0.0;
}

bool Cat::printCat() const noexcept {
    assert( validateCat() ) ;
    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Cat", "name" )    << getName()                     << endl ;
    FORMAT_LINE( "Cat", "gender" )  << genderToString( getGender() ) << endl ;
    FORMAT_LINE( "Cat", "breed" )   << breedToString( getBreed() )   << endl ;
    FORMAT_LINE( "Cat", "isFixed" ) << getFixed()                  << endl ;
    FORMAT_LINE( "Cat", "weight" )  << getWeight()                   << endl ;
    return true ;
}

bool Cat::validateCat() const noexcept {
    try {
        validateName(name);
    }
    catch(const exception& e){
        cout << e.what() << endl;
    }
    return NOERROR;
}

bool Cat::validateName( const char* newName ) const {
    if ( newName            == nullptr )
        throw invalid_argument( PROGRAM_NAME ": New cat name cannot be null." );
    if ( strlen( newName )  == 0 )
        throw invalid_argument( PROGRAM_NAME ": New cat name cannot be empty.");
    if ( strlen( newName )  >  CATNAME_CHARLIMIT )
        throw invalid_argument( PROGRAM_NAME ": New cat name cannot exceed CATNAME_CHARLIMIT characters");

    return NOERROR;
}

bool Cat::validateGender(const Gender newGender) const noexcept {

}

bool Cat::validateBreed( const Breed newBreed ) const noexcept {

}

bool Cat::validateWeight( const Weight newWeight ) const noexcept {

}

    //@todo Add Validation
void Cat::setName(const char* newName) {
    strcpy(Cat::name, newName);
}

void Cat::setGender(const Gender newGender) {
    Cat::gender = newGender;
}

void Cat::setBreed(const Breed newBreed) {
    Cat::breed = newBreed;
}
    //@todo Add Validation
void Cat::setWeight(float newWeight) {
    Cat::weight = newWeight;
}

const char* Cat::getName() const {
    return Cat::name;
}

Cat::Gender Cat::getGender() const {
    return Cat::gender;
}

Cat::Breed Cat::getBreed() const {
    return Cat::breed;
}

bool Cat::getFixed() const {
    return Cat::isFixed;
}

Cat::Weight Cat::getWeight() const {
    return Cat::weight;
}
