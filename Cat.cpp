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
    memset( name , '-' , 10 );
    gender     = UNKNOWN_GENDER;
    breed      = UNKNOWN_BREED;
    isCatFixed = false;
    weight     = 0.0;
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
