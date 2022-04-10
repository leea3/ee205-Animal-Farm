///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file addCats.h
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Cat.h"

/** Function that adds cats to database
 *
 * @param name of the cat to added
 * @param gender of the cat
 * @param breed of the cat
 * @param is the cat fixed
 * @param weight of the cat
 */

extern void addCat( Cat* newCat );
