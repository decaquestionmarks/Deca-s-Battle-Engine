#include "Type.hpp"

class Rock: public Type {
    public:
    Rock(){
        Type();
        name = "Rock";
        TypeChart["Fire"] = 0.5;
        TypeChart["Flying"] = 0.5;
        TypeChart["Normal"] = 0.5;
        TypeChart["Poison"] = 0.5;
        TypeChart["Fighting"] = 2;
        TypeChart["Ground"] = 2;
        TypeChart["Steel"] = 2;
        TypeChart["Water"] = 2;
        TypeChart["Grass"] = 2;
        ConditionImmunities.insert("Sandstorm");
    }
    ~Rock();
};