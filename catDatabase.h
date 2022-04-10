///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "config.h"
#include "Cat.h"

#define MAX_CATS (1024)
#define CATNAME_CHARLIMIT (50)

extern Cat* catDatabaseHeadPointer;

extern bool validateDatabase();

//Note: Current number of cats in database held as a global variable
extern NumCats numberOfCats;

/*
enum Gender { UNKNOWN_GENDER = 0
    ,MALE = 1
    ,FEMALE = 2 };

enum Breed { UNKNOWN_BREED = 0
    ,MAINE_COON = 1
    ,MANX = 2
    ,SHORTHAIR = 3
    ,PERSIAN = 4
    ,SPHYNX = 5 };

enum Color { BLACK = 0
    ,WHITE = 1
    ,RED = 2
    ,BLUE = 3
    ,GREEN = 4
    ,PINK = 5 };

 */
