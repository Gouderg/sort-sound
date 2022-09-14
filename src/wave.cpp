#include "../header/wave.hpp"

Wave::Wave(int freq) {
    this->freq = freq;

    for (double t = 0; t < SAMPLING_RATE; t += 1) {
        samples.push_back((int16_t) (32767 * AMPLITUDE * sin(2 * M_PI * this->freq * t / SAMPLING_RATE)));
    }
}

std::ostream& operator<<(std::ostream& out, const Wave& wave) {
    out << "Wave n° " << wave.freq;
    return out;
}
