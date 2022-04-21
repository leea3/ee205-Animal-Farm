///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file config.h
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include<iomanip>
#include<iostream>

#define ERROR (1)
#define NOERROR (0)
#define MAX_NAME1 "12345678901234567890123456789012345678901234567890"
#define ILLEGAL_NAME "123456789012345678901234567890123456789012345678901"
#define PROGRAM_NAME "Animal Farm 2"

/// Format the heading for dumping members of a class to the console
///
/// Print =====================
#define PRINT_HEADING_FOR_DUMP                                                \
    /* Print =========================================================== */   \
    std::cout << std::setw(80) << std::setfill( '=' ) << "" << std::endl


/// Format a line for dumping the members of a class to the console.
/// Setup the fields for printing (space pad, left justify, etc.)
#define FORMAT_LINE_FOR_DUMP( className, member )         \
    std::cout << std::setfill( ' ' )  /* Space pad    */  \
              << std::left            /* Left justify */  \
              << std::boolalpha  /* Print `true` or `false` for `bool`s */ \
              << std::setw( 8) << (className)             \
              << std::setw(20) << (member)                \
              << std::setw(52)  /* (data) */