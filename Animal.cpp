///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Animal.cpp
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   22_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Animal.h"

Animal::Animal(const float newMaxWeight, const std::string &newClassification, const std::string &newSpecies) {

}

Animal::Animal(const Gender newGender, const float newWeight, const float newMaxWeight,
               const std::string &newClassification, const std::string &newSpecies) {

}

std::string Animal::getKingdom() const noexcept {
    return std::string();
}

std::string Animal::getClassification() const noexcept {
    return std::string();
}

std::string Animal::getSpecies() const noexcept {
    return std::string();
}

Gender Animal::getGender() const noexcept {
    return Gender::UNKNOWN_GENDER;
}

Weight &Animal::getWeight() const noexcept {
    return (Weight &) Weight::UNKNOWN_WEIGHT;
}

void Animal::setWeight(const float newWeight) {

}

void Animal::setGender(const Gender newGender) {

}

std::string Animal::speak() const noexcept {
    return std::string();
}

/*
void Animal::dump() const noexcept {

}

bool Animal::validate() const noexcept {
    return false;
}
 */

bool Animal::validateClassification(const std::string &checkClassification) noexcept {
    return false;
}

bool Animal::validateSpecies(const std::string &checkSpecies) noexcept {
    return false;
}





