///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include<cstring>
#include"Gender.h"
#include"Color.h"
#include "Mammal.h"


#define CATNAME_CHARLIMIT (50)

class Cat : public Mammal{
public: //enums and typedefs
    static const std::string SPECIES_NAME;
    static const float MAX_WEIGHT;

    enum Breed { UNKNOWN_BREED = 0
        ,MAINE_COON            = 1
        ,MANX                  = 2
        ,SHORTHAIR             = 3
        ,PERSIAN               = 4
        ,SPHYNX                = 5 };

protected: //Protected member variables
    std::string   name ;
    bool          isCatFixed;

public: //public constructors & destructors

    Cat( const std::string &newName );

    Cat(const std::string newName,
        const Color       newColor,
        const bool        newIsFixed,
        const Gender      newGender,
        const float       newWeight );


public: //getters and setters
    void setName   ( const std::string  newName   );
    void setBreed  ( const Breed        breed  );
    void fixCat    (                           );

    std::string       getName()    const noexcept;
    Breed             getBreed()   const;
    bool              getFixed()   const noexcept;

public: //public methods
    std::string speak() const noexcept override;
    void dump()    const noexcept override; //prints a cat's name and its characteristics
    bool validate() const noexcept override; //series of validation checks on name, weight

public: //validation methods
    static bool validateName  ( const std::string &newName   );
    static bool validateBreed ( const Breed       newBreed  );
};
