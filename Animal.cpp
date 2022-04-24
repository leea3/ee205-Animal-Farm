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
#include<iostream>
#include<string>
#include "Animal.h"
#include "config.h"
#include "Node.h"
#include "Gender.h"

const std::string Animal::KINGDOM_NAME = "Animalia";

Animal::Animal( const float newMaxWeight ,
                const std::string &newClassification ,
                const std::string &newSpecies ) : weight( Weight::POUND , newMaxWeight ) {
    if( validateClassification( newClassification ) == false )
        throw std::invalid_argument( PROGRAM_NAME ": Animal constructor failed as classification is invalid.");
    if( validateSpecies( newSpecies ) == false )
        throw std::invalid_argument( PROGRAM_NAME ": Animal constructor failed as species is invalid.");

    classification = newClassification;
    species = newSpecies;
    validate();

}

Animal::Animal( const Gender newGender ,
                const float newWeight ,
                const float newMaxWeight ,
                const std::string &newClassification ,
                const std::string &newSpecies ) :
                weight( newWeight , newMaxWeight ) {

    if( validateClassification( newClassification ) == false )
        throw std::invalid_argument( PROGRAM_NAME ": Animal constructor failed as classification is invalid.");
    if( validateSpecies( newSpecies ) == false )
        throw std::invalid_argument( PROGRAM_NAME ": Animal constructor failed as species is invalid.");

    setGender( newGender );
    classification = newClassification;
    species = newSpecies;
    validate();

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

std::ostream& operator<<( std::ostream& lhs_stream, const Weight& rhs_weight ){
    std::stringstream stringBuffer;
    if( rhs_weight == Weight::UNKNOWN_WEIGHT )
        return lhs_stream << "Unknown Weight";
    stringBuffer << rhs_weight.Weight::getWeight()
                 << " out of "
                 << rhs_weight.Weight::getMaxWeight()
                 << " "
                 << rhs_weight.Weight::getUnitOfWeight();
    return lhs_stream << stringBuffer.str();
}

void Animal::dump() const noexcept {
    Node::dump();
    FORMAT_LINE_FOR_DUMP( "Animal", "this" ) << this << std::endl;
    FORMAT_LINE_FOR_DUMP( "Animal" , "Kingdom" ) << KINGDOM_NAME << std::endl;
    FORMAT_LINE_FOR_DUMP( "Animal" , "Classification" ) << classification << std::endl;
    FORMAT_LINE_FOR_DUMP( "Animal" , "Species" ) << species << std::endl;
    FORMAT_LINE_FOR_DUMP( "Animal" , "Gender" ) << gender << std::endl;
    FORMAT_LINE_FOR_DUMP( "Animal" , "Weight" ) << weight << std::endl;
}


bool Animal::validate() const noexcept {
    assert( Node::validate() );
    assert( validateClassification( getClassification() ) );
    assert( validateSpecies( getSpecies() ) );
    weight.Weight::validate();
    return true;
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






