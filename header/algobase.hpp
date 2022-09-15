#pragma once

#include <iostream>
#include <array>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

#include "constante.hpp"
#include "oscillo.hpp"

class AlgoBase {

    public:
        // Constructor.
        AlgoBase(){}

        // Virtual Desctructor.
        virtual ~AlgoBase(){}

        // Virtual sort.
        virtual void sort(Oscillo *os) = 0;

        static std::array<int, NB_FREQ> shuffle(std::array<int, NB_FREQ> freqs); 

};