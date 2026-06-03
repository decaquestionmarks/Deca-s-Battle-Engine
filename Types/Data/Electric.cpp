#include "Type.hpp"

class Electric : public Type {
    public:
    Electric(){
        Type();
        name = "Electric";
        TypeChart["Electric"] = 0.5;
        TypeChart["Flying"] = 0.5;
        TypeChart["Steel"] = 0.5;
        TypeChart["Ground"] = 2;
        ConditionImmunities.insert("Paralysis");
    }
    ~Electric();
};