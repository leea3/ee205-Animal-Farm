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

#define CATNAME_CHARLIMIT (50)

class Cat {
public: //enums and typedefs
    typedef float Weight;
    typedef int   NumCats;

    enum Gender { UNKNOWN_GENDER = 0
        ,MALE = 1
        ,FEMALE = 2 };

    enum Breed { UNKNOWN_BREED = 0
        ,MAINE_COON = 1
        ,MANX = 2
        ,SHORTHAIR = 3
        ,PERSIAN = 4
        ,SPHYNX = 5 };

    /*
    enum Color { BLACK = 0
        ,WHITE = 1
        ,RED = 2
        ,BLUE = 3
        ,GREEN = 4
        ,PINK = 5 };
    */

protected: //Protected member variables
    char          name[CATNAME_CHARLIMIT] ;
    enum   Gender gender ;
    enum   Breed  breed ;
    //enum Color  color;
    bool          isCatFixed;
    Weight        weight;

public: //public member variables
    Cat* next;

};

