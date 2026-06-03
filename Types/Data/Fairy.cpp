#include "Type.hpp"

class Fairy: public Type {
    public:
    Fairy(){
        Type();
        name = "Fairy";
        TypeChart["Fighting"] = 0.5;
        TypeChart["Bug"] = 0.5;
        TypeChart["Dark"] = 0.5;
        TypeChart["Dragon"] = 0;
        TypeChart["Fire"] = 0.5;
        TypeChart["Poison"] = 2;
        TypeChart["Steel"] = 2;
    }
    ~Fairy();
};