#include "Type.hpp"

class Normal : public Type {
    public:
    Normal(){
        Type();
        name = "Normal";
        TypeChart["Fighting"] = 2;
        TypeChart["Ghost"] = 0;
    }
    ~Normal();
};