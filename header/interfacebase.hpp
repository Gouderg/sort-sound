#pragma once

#include "oscillo.hpp"

class Oscillo;

class InterfaceBase {
    
    public:
        InterfaceBase(){};

        virtual ~InterfaceBase(){};

        virtual void update(Oscillo* os, const int mod_i, const int mod_j) = 0;
        virtual void run() = 0;
        virtual void animation(Oscillo* os) = 0;
};