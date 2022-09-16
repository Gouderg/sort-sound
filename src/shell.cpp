#include "../header/shell.hpp"

// Construtor.
Shell::Shell() {
    this->nbSwap = 0;
}

void Shell::update(Oscillo* os, const int mod_i, const int mod_j) {
    this->nbSwap += 1;
}

void Shell::animation(Oscillo* os) {
    std::cout << "Nombre de swap effectué: " << this->nbSwap << std::endl;
}