#include "Type.hpp"

class Grass : public Type {
    public:
    Grass(){
        Type();
        name = "Grass";
        TypeChart["Grass"] = 0.5;
        TypeChart["Water"] = 0.5;
        TypeChart["Electric"] = 0.5;
        TypeChart["Ground"] = 0.5;
        TypeChart["Poison"] = 2;
        TypeChart["Bug"] = 2;
        TypeChart["Flying"] = 2;
        TypeChart["Fire"] = 2;
        TypeChart["Ice"] = 2;
        ConditionImmunities.insert("Powder");
    }
    ~Grass();
};