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

const std::string Animal::KINGDOM_NAME = "Animalia";

Animal::Animal(const float newMaxWeight, const std::string &newClassification, const std::string &newSpecies) : weight( Weight::POUND , newMaxWeight ) {
    if( validateClassification( newClassification ) == false )
        throw std::invalid_argument( PROGRAM_NAME ": Animal constructor failed as classification is invalid.");
    if( validateSpecies( newSpecies ) == false )
        throw std::invalid_argument( PROGRAM_NAME ": Animal constructor failed as species is invalid.");

    classification = newClassification;
    species = newSpecies;
    validate();

}

Animal::Animal(const Gender newGender, const float newWeight, const float newMaxWeight,
               const std::string &newClassification, const std::string &newSpecies) {

}

std::string Animal::getKingdom() const noexcept {
    return KINGDOM_NAME;
}

std::string Animal::getClassification() const noexcept {
    assert( validateClassification( classification ) );
    return classification;
}

std::string Animal::getSpecies() const noexcept {
    assert( validateClassification( species ) );
    return species;
}

Gender Animal::getGender() const noexcept {
    return gender;
}

Weight Animal::getWeight() const noexcept {
    return weight.Weight::getWeight();
}

void Animal::setWeight(const float newWeight) {

    assert( Weight::validateWeight( newWeight ) );
    weight.Weight::setWeight( newWeight );

}

void Animal::setGender(const Gender newGender) {
    if( gender != Gender::UNKNOWN_GENDER )
        throw std::logic_error( PROGRAM_NAME ": setGender failed as you cannot change an Animal's gender.");

    gender = newGender;
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
    weight.Weight::validate();
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





