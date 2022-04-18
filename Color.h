///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Color.h
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include<ostream>

enum class Color {
    BLACK = 0
    ,WHITE = 1
    ,RED = 2
    ,BLUE = 3
    ,GREEN = 4
    ,PINK = 5 };

/// Output Color as a formatted string
inline std::ostream& operator<<( std::ostream& lhs_stream, const Color& rhs_Color );