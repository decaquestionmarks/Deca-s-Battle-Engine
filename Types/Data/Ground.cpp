#include "Type.hpp"

class Ground: public Type {
    public:
    Ground(){
        Type();
        name = "Ground";
        TypeChart["Electric"] = 0;
        TypeChart["Poison"] = 0.5;
        TypeChart["Rock"] = 0.5;
        TypeChart["Water"] = 2;
        TypeChart["Grass"] = 2;
        TypeChart["Ice"] = 2;
        ConditionImmunities.insert("Sandstorm");
    }
    ~Ground();
};