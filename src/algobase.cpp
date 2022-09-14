#include "../header/algobase.hpp"

// Shuffle an array of int and return it.
std::array<int, NB_FREQ> AlgoBase::shuffle(std::array<int, NB_FREQ> freqs) {
    
    // Time-based seed.
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::shuffle (freqs.begin(), freqs.end(), std::default_random_engine(seed));

    return freqs;
}