#include "Type.hpp"

class Dark : public Type {
    public:
    Dark(){
        Type();
        name = "Dark";
        TypeChart["Psychic"] = 0;
        TypeChart["Ghost"] = 0.5;
        TypeChart["Dark"] = 0.5;
        TypeChart["Fighting"] = 2;
        TypeChart["Bug"] = 2;
        TypeChart["Fairy"] = 2;
        ConditionImmunities.insert("PranksterBoosted");
    }
    ~Dark();
};