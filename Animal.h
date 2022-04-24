///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Animal.h
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   22_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include<string>
#include"Weight.h"
#include"Gender.h"
#include"Node.h"

#pragma once

class Animal : public Node {
public:
    static const std::string KINGDOM_NAME;
private:
    std::string species;
    std::string classification;
    Gender gender = Gender::UNKNOWN_GENDER;
    Weight weight = Weight::UNKNOWN_WEIGHT;

public: //constructors
    Animal( const float newMaxWeight ,
            const std::string &newClassification ,
            const std::string &newSpecies);
    Animal( const Gender newGender ,
            const float newWeight ,
            const float newMaxWeight ,
            const std::string &newClassification ,
            const std::string &newSpecies);

public: //getters
    std::string getKingdom() const noexcept;
    std::string getClassification() const noexcept;
    std::string getSpecies() const noexcept;
    Gender getGender() const noexcept;
    Weight getWeight() const noexcept;

public: //setters
    void setWeight( const float newWeight );

protected: //setters
    void setGender( const Gender newGender );

public: // methods
    virtual std::string speak() const noexcept = 0;
    void dump() const noexcept override;

    bool validate() const noexcept override;
    static bool validateClassification( const std::string &checkClassification) noexcept;
    static bool validateSpecies( const std::string &checkSpecies ) noexcept;



};
