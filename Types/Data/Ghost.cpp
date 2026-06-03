#include "Type.hpp"

class Ghost: public Type {
    public:
    Ghost(){
        Type();
        name = "Ghost";
        TypeChart["Normal"] = 0;
        TypeChart["Fighting"] = 0;
        TypeChart["Poison"] = 0.5;
        TypeChart["Bug"] = 0.5;
        TypeChart["Dark"] = 2;
        TypeChart["Ghost"] = 2;
        ConditionImmunities.insert("Trapped");
    }
    ~Ghost();
};