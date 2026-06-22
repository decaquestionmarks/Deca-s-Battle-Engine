#pragma once
#include "Natures.hpp"
class NatureFactory{
    public:
    static Nature* getNature(const int id){ //sry guys we're using ids for these
        switch(id){
            case 0: return new Hardy();
            case 1: return new Lonely();
            case 2: return new Brave();
            case 3: return new Adamant();
            case 4: return new Naughty();
            case 5: return new Bold();
            case 6: return new Docile();
            case 7: return new Relaxed();
            case 8: return new Impish();
            case 9: return new Lax();
            case 10: return new Timid();
            case 11: return new Hasty();
            case 12: return new Serious();
            case 13: return new Jolly();
            case 14: return new Naive();
            case 15: return new Modest();
            case 16: return new Mild();
            case 17: return new Quiet();
            case 18: return new Bashful();
            case 19: return new Rash();
            case 20: return new Calm();
            case 21: return new Gentle();
            case 22: return new Sassy();
            case 23: return new Careful();
            case 24: return new Quirky();
            default: return new Serious();
        }
    }
};