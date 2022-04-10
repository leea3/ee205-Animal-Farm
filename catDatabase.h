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

#define CATNAME_CHARLIMIT (50)

//linked list head pointer
extern Cat* catDatabaseHeadPointer;

//checks each cat entry and makes sure it's valid. If not, animalFarm program is terminated
extern bool validateDatabase();

//Note: Current number of cats in database held as a global variable
extern Cat::NumCats numberOfCats;