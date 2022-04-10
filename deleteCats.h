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


/* deletes array elements at specified index
 *
 * everything above deleted element gets shifted down
 *
 * @param array index to be deleted
 */
extern void deleteCat( Cat* targetCat );

extern void deleteAllCats( );
