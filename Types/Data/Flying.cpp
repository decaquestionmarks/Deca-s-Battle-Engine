#include "Type.hpp"

class Flying: public Type {
    public:
    Flying(){
        Type();
        name = "Flying";
        TypeChart["Fighting"] = 0.5;
        TypeChart["Bug"] = 0.5;
        TypeChart["Grass"] = 0.5;
        TypeChart["Electric"] = 2;
        TypeChart["Ice"] = 2;
        TypeChart["Rock"] = 2;
        TypeChart["Ground"] = 0;
        ConditionImmunities.insert("GroundBased");
    }
    ~Flying();
};