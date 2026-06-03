#include "Type.hpp"

class Bug: public Type{
    public:
    Bug(){
        Type();
        name = "Bug";
        TypeChart["Grass"] = 0.5;
        TypeChart["Fighting"] = 0.5;
        TypeChart["Ground"] = 0.5;
        TypeChart["Fire"] = 2;
        TypeChart["Flying"] = 2;
        TypeChart["Rock"] = 2;
    }
    ~Bug();
};