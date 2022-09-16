#pragma once

#include "../header/interfacebase.hpp"

class Shell: public InterfaceBase {
    public:
        Shell();

        void run(){};
        void update(Oscillo* os, const int mod_i, const int mod_j);
        void animation(Oscillo* os);
    
    private:
        long nbSwap;

};