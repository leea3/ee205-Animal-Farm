///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file reportCats.h
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "catDatabase.h"

/* Prints database contents at a specified index
 *
 * if index is invalid, outputs an error and moves on with the program
 *
 * @param index of the cat
 */
extern void printCat( const int index );

// Prints the contents of the entire database
extern void printAllCats( );

/* Returns the cat's index if a name is fed through
 *
 * if cat cannot be found, terminates program
 *
 * @param name of the cat in quotes (i.e. "Chili")
 */
extern int findCat( const char findName[] );

/* maps gender enum to string
 *
 * @param gender of the cat
 */
extern const char* genderToString ( const enum Gender convertGender );

/* maps breed enum to string
 *
 * @param breed of the cat
 */
extern const char* breedToString ( const enum Breed convertBreed );

/* maps color enum to string
 *
 * @param color of the cat's collar
 */
extern const char* colorToString ( const enum Color convertColor );
