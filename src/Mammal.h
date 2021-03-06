///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Mammal.h
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   23_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include "Animal.h"
#include "Color.h"
#include "Weight.h"
#include "Gender.h"


class Mammal : public Animal {
public:
    static const std::string MAMMAL_NAME;

protected:
    Color color;

public: //constructors
    Mammal( const Weight::t_weight newMaxWeight,
            const std::string &newSpecies );

    Mammal( const Color newColor,
            const Gender newGender,
            const Weight::t_weight newWeight,
            const Weight::t_weight newMaxWeight,
            const std::string&newSpecies );

public: //getters
    Color getColor() const noexcept;

public: //setters
    void setColor(Color color) noexcept;

public: //methods
    void dump() const noexcept override;


};

