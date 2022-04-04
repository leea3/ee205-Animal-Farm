cmake_minimum_required(VERSION 3.22)
project(ee205_animal_farm)

set(CMAKE_CXX_STANDARD 14)

add_executable(ee205_animal_farm main.cpp addCats.cpp addCats.h catDatabase.cpp catDatabase.h config.h deleteCats.cpp deleteCats.h reportCats.cpp reportCats.h updateCats.cpp updateCats.h)
