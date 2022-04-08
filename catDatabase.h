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
#include <stdbool.h>
#include "config.h"
#include "Cat.h"

#define MAX_CATS (1024)
#define CATNAME_CHARLIMIT (50)

extern Cat* catDatabaseHeadPointer;

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

struct cat_database{
    char name[CATNAME_CHARLIMIT];
    enum Gender gender;
    enum Breed breed;
    bool fixed;
    Weight weight;
    enum Color collarColor1;
    enum Color collarColor2;
    unsigned long long license;
};

//externs struct so that other files can access it
extern struct cat_database catabase[MAX_CATS];

//Note: Current number of cats in database held as a global variable
extern NumCats numberOfCats;

/* Zeroes out the database based on MAX_CATS
 *
 * zeros out the five arrays and number of cats in database
 */
extern void initializeDatabase( );
