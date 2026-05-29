#include "Type.hpp"

class Water : public Type {
    public:
    Water(){
        Type();
        name = "Water";
        TypeChart["Fire"] = 0.5;
        TypeChart["Water"] = 0.5;
        TypeChart["Ice"] = 0.5;
        TypeChart["Steel"] = 0.5;
        TypeChart["Electric"] = 2;
        TypeChart["Grass"] = 2;
    }
    ~Water();
};