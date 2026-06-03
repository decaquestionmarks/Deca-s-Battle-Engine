#include "Type.hpp"

class Psychic: public Type {
    public:
    Psychic(){
        Type();
        name = "Psychic";
        TypeChart["Fighting"] = 0.5;
        TypeChart["Psychic"] = 0.5;
        TypeChart["Bug"] = 2;
        TypeChart["Ghost"] = 2;
        TypeChart["Dark"] = 2;
    }
    ~Psychic();
};