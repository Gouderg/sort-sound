#include "../header/shell.hpp"

// Construtor.
Shell::Shell() {
    this->nbSwap = 0;
    this->start = clock();


}

void Shell::update(Oscillo* os, const int mod_i, const int mod_j) {
    this->nbSwap += 1;
}

void Shell::animation(Oscillo* os) {
    this->end = clock();

    std::cout << "Time execution: " << ((float) this->end - this->start)/CLOCKS_PER_SEC << " sec" << std::endl;

    std::cout << "Nunber of swap:  " << this->nbSwap << std::endl;
}