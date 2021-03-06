///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-animal-farm - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <cstring>
#include <iostream>

#include "config.h"
#include "Cat.h"
#include "SinglyLinkedList.h"
#include "List.h"


using namespace std;

int main() {
    cout << "Starting " << PROGRAM_NAME << endl ;

    SinglyLinkedList catDB ;

    catDB.push_front( new Cat( "Loki",  Color::WHITE,  true, Gender::MALE,   1.0 ) ) ;
    catDB.push_front( new Cat( "Milo",  Color::BLACK,  true, Gender::MALE,   1.1 ) ) ;
    catDB.push_front( new Cat( "Bella", Color::GINGER,  true, Gender::FEMALE, 1.2 ) ) ;
    catDB.push_front( new Cat( "Kali",  Color::CINNAMON,   true, Gender::FEMALE, 1.3 ) ) ;
    catDB.push_front( new Cat( "Trin",  Color::FAWN,  true, Gender::FEMALE, 1.4 ) ) ;


    catDB.insert_after(catDB.get_first(), new Cat( "Chili", Color::GREY, true, Gender::MALE,   1.5 ) );


    for( Animal* pAnimal = (Animal*)catDB.get_first() ; pAnimal != nullptr ; pAnimal = (Animal*)List::get_next( (Node*)pAnimal ) ) {
        cout << pAnimal->speak() << endl;
    }

    catDB.validate() ;
    catDB.dump() ;
    catDB.deleteAllNodes() ;
    catDB.dump() ;

    cout << "Done with " << PROGRAM_NAME << endl ;
    return( 0 ) ;
}

