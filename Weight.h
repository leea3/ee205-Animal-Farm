///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Arthur Lee <leea3@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>

class Weight {
public:
    //units enum
    typedef float t_weight;
    enum UnitOfWeight {
        POUND, KILO, SLUG
    };

    static const Weight::t_weight UNKNOWN_WEIGHT;

    //conversion constants
    static const Weight::t_weight KILOS_IN_A_POUND;
    static const Weight::t_weight SLUGS_IN_A_POUND;

    //labels
    static const std::string POUND_LABEL;
    static const std::string KILO_LABEL;
    static const std::string SLUG_LABEL;

private:
    bool  bIsKnown = false;
    bool  bHasMax = false;
    enum  UnitOfWeight unitOfWeight = POUND;
    Weight::t_weight weight = UNKNOWN_WEIGHT;
    Weight::t_weight maxWeight = UNKNOWN_WEIGHT;

public: //constructors
    Weight();
    Weight(Weight::t_weight newWeight);
    Weight(UnitOfWeight newUnitOfWeight) noexcept;
    Weight(Weight::t_weight newWeight, UnitOfWeight newUnitOfWeight);
    Weight(Weight::t_weight newWeight, Weight::t_weight newMaxWeight);
    Weight(UnitOfWeight newUnitOfWeight, Weight::t_weight newMaxWeight);
    Weight(Weight::t_weight newWeight, UnitOfWeight newUnitOfWeight, Weight::t_weight newMaxWeight);

public: //static methods
    static Weight::t_weight fromKilogramToPound(const Weight::t_weight kilogram) noexcept;
    static Weight::t_weight fromPoundToKilogram(Weight::t_weight pound) noexcept;
    static Weight::t_weight fromSlugToPound(Weight::t_weight slug) noexcept;
    static Weight::t_weight fromPoundToSlug(Weight::t_weight pound) noexcept;

    static Weight::t_weight convertWeight(Weight::t_weight fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept;

public: //getters and setters
    void setWeight(Weight::t_weight newWeight);
    void setWeight(Weight::t_weight newWeight, UnitOfWeight weightUnit );
    void setMaxWeight(Weight::t_weight maxWeight);

    Weight::t_weight getWeight() const;
    Weight::t_weight getWeight( UnitOfWeight weightUnit ) const;
    Weight::t_weight getMaxWeight() const noexcept;
    bool  getWeightKnown() const noexcept;
    bool  getHasMax()      const noexcept;
    UnitOfWeight getUnitOfWeight() const noexcept;

    void dump();


public: //validation
    static bool validateWeight(const Weight::t_weight newWeight) noexcept;
    bool validate() const;

public:
    bool operator==( const Weight& rhs_Weight ) const;
    bool operator<(const Weight &rhs_Weight) const;
    Weight & operator+= (Weight::t_weight rhs_addToWeight );

};
inline std::ostream& operator<<( std::ostream& lhs_stream
        ,const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << Weight::POUND_LABEL ;
        case Weight::KILO: return lhs_stream << Weight::KILO_LABEL ;
        case Weight::SLUG: return lhs_stream << Weight::SLUG_LABEL ;
        default:
            throw std::out_of_range( "The unit can’t be mapped to a string" );
    }
}