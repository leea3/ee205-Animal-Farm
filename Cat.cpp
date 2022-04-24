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
#include <cassert>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "config.h"
#include "Cat.h"
#include "reportCats.h"

const std::string Cat::SPECIES_NAME = "Felis Catus";
const float       Cat::MAX_WEIGHT   = 40.0;

Cat::Cat( const std::string &newName )
: Mammal::Mammal( Cat::MAX_WEIGHT , Cat::SPECIES_NAME ) {
    if( validateName( newName ) == false )
        throw std::invalid_argument( PROGRAM_NAME ": Cat constructor failed as newName is invalid.");
    setName( newName );
    isCatFixed = false;
    Cat::validate();
}

Cat::Cat( const std::string newName,
     const Color       newColor,
     const bool        newIsFixed,
     const Gender      newGender,
     const float       newWeight )
     : Mammal( newColor , newGender , newWeight , Cat::MAX_WEIGHT , Cat::SPECIES_NAME ){
    if( validateName( newName ) == false )
        throw std::invalid_argument( PROGRAM_NAME ": Cat constructor failed as newName is invalid.");
    setName( newName );
    isCatFixed = newIsFixed;
    Cat::validate();
}

std::string Cat::getName() const noexcept{
    validate();
    return name;
}

bool Cat::getFixed() const noexcept {
    validate();
    return isCatFixed;
}

std::string Cat::getBreed() const noexcept {
    validate();
    return breedToString( breed );
}

void Cat::setName ( const std::string newName ){
    if ( validateName( newName ) == false )
        throw std::invalid_argument( PROGRAM_NAME ": setName failed as name is invalid.");
    name = newName;
}

void Cat::fixCat() {
    if( isCatFixed == true )
        throw std::logic_error(PROGRAM_NAME ": fixCat() failed as cat is already fixed (can't unfix a cat).");
    isCatFixed = true;
}

std::string Cat::speak() const noexcept{
    return "Meow~";
}

void Cat::dump() const noexcept {
    Mammal::dump();
    FORMAT_LINE_FOR_DUMP( "Cat" , "Name" ) << name << std::endl;
}

bool Cat::validate() const noexcept {
    assert( validateName( name ) );
    return true;
}

bool Cat::validateName(const std::string &newName) {
    if ( newName.empty() == true )
        return false;
    return true;
}

std::string Cat::breedToString ( Cat::Breed convertBreed ) {
    switch( convertBreed ){
        case Cat::UNKNOWN_BREED: return "UNKNOWN BREED";
        case Cat::MAINE_COON:    return "MAINE COON";
        case Cat::MANX:          return "MANX";
        case Cat::SHORTHAIR:     return "SHORTHAIR";
        case Cat::PERSIAN:       return "PERSIAN";
        case Cat::SPHYNX:        return "SPHYNX";
        default:                 throw  std::invalid_argument( PROGRAM_NAME ": Invalid Breed" );
    }
}

/*
#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

using namespace std;

Cat::Cat() {
    //memset( name , 0 , CATNAME_CHARLIMIT );
    gender     = UNKNOWN_GENDER;
    breed      = UNKNOWN_BREED;
    isFixed    = false;
    weight     = 0.0;
    next       = nullptr;
}

Cat::Cat(const std::string newName,
         const Cat::Gender newGender,
         const Cat::Breed  newBreed,
         const Cat::Weight newWeight) : Cat() {

            //set default values to new cats
            setName  ( newName   );
            setGender( newGender );
            setBreed ( newBreed  );
            setWeight( newWeight );


    }

Cat::~Cat(){
    //memset( name , 0 , CATNAME_CHARLIMIT );
    gender     = UNKNOWN_GENDER;
    breed      = UNKNOWN_BREED;
    isFixed    = false;
    weight     = 0.0;
    next       = nullptr;
}

bool Cat::printCat() const noexcept {
    assert( validateCat() == NOERROR ) ;
    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Cat", "name" )    << getName()                     << endl ;
    FORMAT_LINE( "Cat", "gender" )  << genderToString( getGender() ) << endl ;
    FORMAT_LINE( "Cat", "breed" )   << breedToString( getBreed() )   << endl ;
    FORMAT_LINE( "Cat", "isFixed" ) << getFixed()                    << endl ;
    FORMAT_LINE( "Cat", "weight" )  << getWeight()                   << endl ;
    return true ;
}

bool Cat::validateCat() const noexcept {
    try {
        validateName  ( name   );
        validateBreed ( breed  );
        validateGender( gender );
        validateWeight( weight );
    }
    catch(const exception& e){
        cout << e.what() << endl;
        return ERROR;
    }
    return NOERROR;
}

bool Cat::validateName( const char* newName ) {
    if ( newName == nullptr )
        throw invalid_argument( PROGRAM_NAME ": New cat name cannot be null." );
    if ( strlen( newName )  == 0 )
        throw length_error( PROGRAM_NAME ": New cat name cannot be empty.");
    if ( strlen( newName )  >  CATNAME_CHARLIMIT )
        throw length_error( PROGRAM_NAME ": New cat name cannot exceed CATNAME_CHARLIMIT characters");

    return NOERROR;
}

bool Cat::validateGender(const Gender newGender) {
    if ( newGender == UNKNOWN_GENDER )
        throw logic_error( PROGRAM_NAME ": Cat's gender must be known.");
    return NOERROR;
}

bool Cat::validateBreed( const Breed newBreed ) {
    if ( newBreed == UNKNOWN_BREED )
        throw logic_error( PROGRAM_NAME ": Cat's breed must be known");
    return NOERROR;
}

bool Cat::validateWeight( const Weight newWeight ) {
    if( newWeight <= 0.0 )
        throw std::logic_error( PROGRAM_NAME ": Cat must have a valid weight greater than 0.");
    return NOERROR;
}

void Cat::setName(const std::string newName) {
    validateName( newName );
    name = newName;
}

void Cat::setGender(const Gender newGender) {
    if( gender != UNKNOWN_GENDER )
        throw logic_error( PROGRAM_NAME ": You can't change an existing, known gender" ) ;

    validateGender( newGender );
    Cat::gender = newGender;
}

void Cat::setBreed(const Breed newBreed) {
    if( breed != UNKNOWN_BREED )
        throw logic_error( PROGRAM_NAME ": You can't change an existing, known breed" ) ;

    validateBreed( newBreed );
    Cat::breed = newBreed;
}

void Cat::fixCat() {
    Cat::isFixed = true;
}

void Cat::setWeight(const Weight newWeight) {
    validateWeight( newWeight );
    Cat::weight = newWeight;
}

std::string Cat::getName() const {
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
*/