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

const std::string MAMMAL_NAME = "Mammalian";

Mammal::Mammal( const float newMaxWeight,
                const std::string &newSpecies)
        : Animal(newMaxWeight, MAMMAL_NAME, newSpecies) {}

Mammal::Mammal( const Color newColor,
                const Gender newGender,
                const float newWeight,
                const float newMaxWeight,
                const std::string &newSpecies )
                : Animal( newGender, newWeight, newMaxWeight, MAMMAL_NAME, newSpecies ) {}
