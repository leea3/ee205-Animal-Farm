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
#include<stdexcept>
#include"config.h"

enum class Color {
    BLACK = 0
    ,WHITE = 1
    ,GINGER = 2
    ,BLUE = 3
    ,GREY = 4
    ,CREAM = 5
    ,BROWN = 6
    ,CINNAMON = 7
    ,FAWN = 8 };

/// Output Color as a formatted string
inline std::ostream& operator<<( std::ostream& lhs_stream, const Color& rhs_Color ){
    switch( rhs_Color ) {
        case Color::BLACK:
            lhs_stream << "Black";
            break;
        case Color::WHITE:
            lhs_stream << "White";
            break;
        case Color::GINGER:
            lhs_stream << "Ginger";
            break;
        case Color::BLUE:
            lhs_stream << "Blue";
            break;
        case Color::GREY:
            lhs_stream << "Grey";
            break;
        case Color::CREAM:
            lhs_stream << "Cream";
            break;
        case Color::BROWN:
            lhs_stream << "Brown";
            break;
        case Color::CINNAMON:
            lhs_stream << "Cinnamon";
            break;
        case Color::FAWN:
            lhs_stream << "Fawn";
            break;
        default:
/// @throw out_of_range If the enum is not mapped to a string.
            throw std::out_of_range( PROGRAM_NAME ": Color not mapped to a string" );
    }
    return lhs_stream;
}
