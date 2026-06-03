#include "Type.hpp"

class Poison: public Type {
    public:
    Poison(){
        Type();
        name = "Poison";
        TypeChart["Grass"] = 0.5;
        TypeChart["Fighting"] = 0.5;
        TypeChart["Poison"] = 0.5;
        TypeChart["Bug"] = 0.5;
        TypeChart["Fairy"] = 0.5;
        TypeChart["Ground"] = 2;
        TypeChart["Psychic"] = 2;
        ConditionImmunities.insert("Poison");
        ConditionImmunities.insert("Toxic");
    }
    ~Poison();
};