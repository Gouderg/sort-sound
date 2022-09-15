#pragma once

#include <vector>
#include <iostream>
#include <cmath>

#include "constante.hpp"

class Wave {
    public:

        // Constructor.
        Wave(){};
        Wave(int freq);

        // Getter.
        int getFreq() const {return freq;}
        std::vector<int16_t> getSamples() {return samples;}

        // Setter.
        void setFreq(const int freq) {this->freq = freq;}
        void setSamples(const std::vector<int16_t> samples) {this->samples = samples;}

        // Operator.
        friend std::ostream& operator<<(std::ostream&, const Wave&);

    private:
        int freq;
        std::vector<int16_t> samples;

};