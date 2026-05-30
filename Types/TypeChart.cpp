#pragma once
#include <vector>
#include "Type.hpp"
#include "Data/All.hpp"

class TypeChart{
    public:
    static double onEffectiveness(const Type t1, const std::vector<Type> types){
        double effectiveness = 1.0;
        for (const Type& t2 : types) {
            effectiveness *= t2.onEffectiveness(t1);
        }
        return effectiveness;
    }
    static bool onCondition(const Condition c, const std::vector<Type> types){
        for (const Type& t : types) {
            if (!t.onCondition(c)) return false; //if any type is immune, return false
        }
        return true; //if no types are immune, return true
    }
    static Type getType(std::string name){
        if (name == "Fire") return Fire();
        else if (name == "Water") return Water();
        else if (name == "Grass") return Grass();
        // add more types here
        else return Type(); // default to base type if not found
    }
};