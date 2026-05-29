#include "Type.hpp"

class Fire : public Type {
    public:
    Fire(){
        Type();
        name = "Fire";
        TypeChart["Grass"] = 0.5;
        TypeChart["Ice"] = 0.5;
        TypeChart["Bug"] = 0.5;
        TypeChart["Fire"] = 0.5;
        TypeChart["Steel"] = 0.5;
        TypeChart["Fairy"] = 0.5;
        TypeChart["Water"] = 2;
        TypeChart["Rock"] = 2;
        TypeChart["Ground"] = 2;
        ConditionImmunities.insert("Burn");
    }
    ~Fire();
};