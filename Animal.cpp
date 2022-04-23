///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Animal.cpp
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   22_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include<algorithm>
#include<cassert>
#include "Animal.h"
#include "config.h"
#include "Node.h"

const std::string KINGDOM_NAME = "Animalia";

Animal::Animal(const float newMaxWeight, const std::string &newClassification, const std::string &newSpecies) {

}

Animal::Animal(const Gender newGender, const float newWeight, const float newMaxWeight,
               const std::string &newClassification, const std::string &newSpecies) {

}

std::string Animal::getKingdom() const noexcept {
    return std::string();
}

std::string Animal::getClassification() const noexcept {
    return std::string();
}

std::string Animal::getSpecies() const noexcept {
    return std::string();
}

Gender Animal::getGender() const noexcept {
    return Gender::UNKNOWN_GENDER;
}

Weight Animal::getWeight() const noexcept {
    return weight.Weight::getWeight();
}

void Animal::setWeight(const float newWeight) {

    assert( Weight::validateWeight( newWeight ) );
    weight.Weight::setWeight( newWeight );

}

void Animal::setGender(const Gender newGender) {

}

std::string Animal::speak() const noexcept {
    return std::string();
}


void Animal::dump() const noexcept {
    PRINT_HEADING_FOR_DUMP;
    FORMAT_LINE_FOR_DUMP( "Animal", "this" );
    FORMAT_LINE_FOR_DUMP( "Animal" , "Kingdom" );
    FORMAT_LINE_FOR_DUMP( "Animal" , "Classification" );
    FORMAT_LINE_FOR_DUMP( "Animal" , "Species" );
    FORMAT_LINE_FOR_DUMP( "Animal" , "Gender" );
    FORMAT_LINE_FOR_DUMP( "Animal" , "Weight" );
}


bool Animal::validate() const noexcept {
    //@todo add more validation
    assert( validateClassification( getClassification() ) );
    assert( validateSpecies( getSpecies() ) );
}

bool Animal::validateClassification(const std::string &checkClassification) noexcept {
    if ( checkClassification.empty() == true )
        return false;
    //check if there's any digits
    if ( std::any_of(checkClassification.begin(), checkClassification.end(), ::isdigit ) == true )
        return false;
    return true;
}

bool Animal::validateSpecies(const std::string &checkSpecies) noexcept {
    if ( checkSpecies.empty() == true )
        return false;
    //check if there's any digits
    if ( std::any_of(checkSpecies.begin(), checkSpecies.end(), ::isdigit ) == true )
        return false;
    return true;
}





