#include "../header/oscillo.hpp"

// Constructor.
Oscillo::Oscillo(InterfaceBase *gui) {
    this->step_f = (MAX_FREQ - MIN_FREQ) / NB_FREQ;
    int freq = MIN_FREQ;

    for (int i = 0; i < NB_FREQ; i++) {
        this->waves[i] = Wave(freq);
        this->keys[i] = i;
        freq += step_f;
    }

    this->interface = gui;
}

// Swap two values in an array.
void Oscillo::swap(const int i, const int j) {
    int k = keys[i];
    keys[i] = keys[j];
    keys[j] = k;
}

// Update.
void Oscillo::update(const int i, const int j, const bool isSwap, const bool isEnd) {
    if (isEnd) {
        this->interface->animation(this);
    } else {
        if (isSwap) {
            swap(i, j);
        } else {
            setKey(i, j);
        }
        this->interface->update(this, i, j);
    }   
}

// Display an object.
std::ostream& operator<<(std::ostream& out, const Oscillo& Osci) {

    out << "Keys: ";
    for (int &n : Osci.getKeys()) {
        out << n << " ";
    }
    // Display information about the waves.
    // out << "\n\nWaves: \n";
    // for (auto &n : Osci.getWaves()) {
    //     out << n.first << ": " << n.second << "\n";
    // }
    return out;
}