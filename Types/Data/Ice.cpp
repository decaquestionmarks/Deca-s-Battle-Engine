#include "Type.hpp"

class Ice : public Type {
    public:
    Ice(){
        Type();
        name = "Ice";
        TypeChart["Ice"] = 0.5;
        TypeChart["Fire"] = 2;
        TypeChart["Fighting"] = 2;
        TypeChart["Rock"] = 2;
        TypeChart["Steel"] = 2;
        ConditionImmunities.insert("Freeze");
        ConditionImmunities.insert("Hail");
    }
    ~Ice();
};