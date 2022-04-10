///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file deleteCats.h
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "catDatabase.h"
#include "Cat.h"


//deletes a node from the linked list
extern void deleteCat( Cat* targetCat );

//deallocates memory and sets head pointer to null
extern void deleteAllCats( );
