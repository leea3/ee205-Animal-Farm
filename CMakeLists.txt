cmake_minimum_required(VERSION 3.22)
project(ee205_animal_farm)

set(CMAKE_CXX_STANDARD 14)

add_executable(ee205_animal_farm main.cpp
        config.h Cat.cpp Cat.h
        Gender.h Weight.cpp Weight.h Color.h Node.cpp Node.h List.cpp List.h SinglyLinkedList.cpp SinglyLinkedList.h Animal.cpp Animal.h Mammal.cpp Mammal.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -DDEBUG")