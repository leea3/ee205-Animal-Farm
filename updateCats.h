///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file updateCats.h
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "catDatabase.h"

/* Updates the cat's name at specified index
 *
 * if name is invalid or the index is invalid, returns 1
 * else, name is changed and returns 0
 *
 * @param index of the cat to be given a new name
 * @param new name of the cat
 */
extern int updateCatName( const int index , const char newCatName[] );

/* Fixes the cat at specified index
 *
 * If the index is invalid, returns 1
 * else, cat is fixed and returns 0
 *
 * @param index of the cat to be fixed
 */
extern int fixCat( const int index );

/* Updates the cat's weight at specified index
 *
 * if the weight is invalid or the cat's weight is invalid, returns 1
 * else, cat's weight is updated and returns 0
 *
 * @param index of the cat
 * @param new weight
 */
extern int updateCatWeight( const int index , const Weight newCatWeight );

/* Checks if the entered index is valid
 *
 * index entered must not be negative or exceed number of cats in database
 *
 * if valid, returns 0
 * else, returns 1
 *
 * @param index of the cat
 */

/* Updates the cat's collar color1 at given index
 *
 * @param index of the cat
 * @param new collar color
 */
extern int updateCatCollar1( const int index , const enum Color newCollarColor1 );

/* Updates the cat's collar color2 at given index
 *
 * @param index of the cat
 * @param new collar color
 */
extern int updateCatCollar2( const int index , const enum Color newCollarColor2 );

/* Updates the cat's license at given index
 *
 * @param index of the cat
 * @param license number (unsigned long long)
 */
extern int updateCatLicense( const int index , const unsigned long long updatedLicense );

/* Checks if theres a cat in the index
 *
 * @param index of the cat
 */
extern int isIndexValid( const int index );
