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

#include<string>

/*
#define CATNAME_CHARLIMIT (50)

class Cat {
public: //enums and typedefs
    typedef float Weight;
    typedef int   NumCats;

    enum Gender { UNKNOWN_GENDER = 0
        ,MALE                    = 1
        ,FEMALE                  = 2 };

    enum Breed { UNKNOWN_BREED = 0
        ,MAINE_COON            = 1
        ,MANX                  = 2
        ,SHORTHAIR             = 3
        ,PERSIAN               = 4
        ,SPHYNX                = 5 };

protected: //Protected member variables
    std::string   name ;
    enum   Gender gender ;
    enum   Breed  breed ;
    bool          isFixed;
    Weight        weight;

public: //public member variables
    Cat* next;

public: //public constructors & destructors

    Cat();

    Cat(const std::string newName,
        const Gender      newGender,
        const Breed       newBreed,
        const Weight      newWeight);

    //destructor that sets default values to a cat
    ~Cat();

public: //getters and setters
    void setName   ( const std::string  name   );
    void setGender ( const Gender       gender );
    void setBreed  ( const Breed        breed  );
    void fixCat    (                           );
    void setWeight ( const Weight       weight );

    std::string       getName()    const;
    Gender            getGender()  const;
    Breed             getBreed()   const;
    bool              getFixed()   const;
    Weight            getWeight()  const;

public: //public methods
    bool printCat()    const noexcept; //prints a cat's name and its characteristics
    bool validateCat() const noexcept; //series of validation checks on name, weight

public: //validation methods
    static bool validateName  ( const std::string newName   );
    static bool validateGender( const Gender      newGender );
    static bool validateBreed ( const Breed       newBreed  );
    static bool validateWeight( const Weight      newWeight );
};
*/