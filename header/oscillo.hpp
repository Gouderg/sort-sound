#pragma once

#include <iostream>
#include <array>
#include <unordered_map>

#include "wave.hpp"
#include "constante.hpp"
#include "interfacebase.hpp"

class InterfaceBase;

class Oscillo {

    public:
        // Constructor.
        Oscillo(InterfaceBase *gui);

        // Getter.
        std::array<int, NB_FREQ> getKeys() const {return keys;}
        std::unordered_map<int, Wave> getWaves() const {return waves;}
        int getKey(const int i) const {return keys[i];}
        Wave getWave(const int i) {return waves[i];}

        // Setter.
        void setKeys(const std::array<int, NB_FREQ> keys) {this->keys = keys;}
        void setWaves(const std::unordered_map<int, Wave> waves) {this->waves = waves;}

        // Swap elements.
        void swap(const int i, const int j);

        // Update.
        void update(const int i, const int j, const bool end);

        // Opertor.
        friend std::ostream& operator<<(std::ostream&, const Oscillo&);

    private:
        std::array<int, NB_FREQ> keys;
        std::unordered_map<int, Wave> waves;

        int step_f;

        InterfaceBase *interface;
};