#include "Type.hpp"

class Dragon: public Type {
    public:
    Dragon(){
        Type();
        name = "Dragon";
        TypeChart["Dragon"] = 2;
        TypeChart["Fairy"] = 2;
        TypeChart["Ice"] = 2;
        TypeChart["Electric"] = 0.5;
        TypeChart["Fire"] = 0.5;
        TypeChart["Grass"] = 0.5;
        TypeChart["Water"] = 0.5;
    }
    ~Dragon();
};