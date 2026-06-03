#include "Type.hpp"

class Steel: public Type {
    public:
    Steel(){
        Type();
        name = "Steel";
        TypeChart["Normal"] = 0.5;
        TypeChart["Grass"] = 0.5;
        TypeChart["Ice"] = 0.5;
        TypeChart["Flying"] = 0.5;
        TypeChart["Psychic"] = 0.5;
        TypeChart["Bug"] = 0.5;
        TypeChart["Rock"] = 0.5;
        TypeChart["Dragon"] = 0.5;
        TypeChart["Fairy"] = 0.5;
        TypeChart["Steel"] = 0.5;
        TypeChart["Fire"] = 2;
        TypeChart["Fighting"] = 2;
        TypeChart["Ground"] = 2;
        TypeChart["Poison"] = 0;
        ConditionImmunities.insert("Poison");
        ConditionImmunities.insert("Toxic");
        ConditionImmunities.insert("Sandstorm");
    }
    ~Steel();
};