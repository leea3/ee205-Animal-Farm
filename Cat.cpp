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
#include "Cat.h"
#include <string.h>
#include <iostream>
#include <iomanip>
#include <assert.h>

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
    isCatFixed = false;
    weight     = 0.0;
}

//@todo Implement getters
bool Cat::printCat() const noexcept {
    assert( validateCat() ) ;
    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Cat", "name" ) << getName() << endl ;
    FORMAT_LINE( "Cat", "gender" ) << genderName( getGender() ) << endl ;
    FORMAT_LINE( "Cat", "breed" ) << breedName( getBreed() ) << endl ;
    FORMAT_LINE( "Cat", "isFixed" ) << isCatFixed() << endl ;
    FORMAT_LINE( "Cat", "weight" ) << getWeight() << endl ;
    return true ;
}

bool validateCat() {

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