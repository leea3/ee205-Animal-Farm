///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Mammal.cpp
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   23_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Mammal.h"
#include "Animal.h"
#include "config.h"

const std::string Mammal::MAMMAL_NAME = "Mammalian";

Mammal::Mammal( const Weight::t_weight newMaxWeight,
                const std::string &newSpecies)
        : Animal(newMaxWeight, MAMMAL_NAME , newSpecies) {}

Mammal::Mammal( const Color newColor,
                const Gender newGender,
                const Weight::t_weight newWeight,
                const Weight::t_weight newMaxWeight,
                const std::string &newSpecies )
                : Animal( newGender, newWeight, newMaxWeight, MAMMAL_NAME, newSpecies ) {
    setColor( newColor );
}

Color Mammal::getColor() const noexcept {
    return color;
}

void Mammal::setColor(Color color) noexcept {
    Mammal::color = color;
}

void Mammal::dump() const noexcept {
    Animal::dump();
    FORMAT_LINE_FOR_DUMP( "Mammal" , "Color" ) << getColor() << std::endl;
}