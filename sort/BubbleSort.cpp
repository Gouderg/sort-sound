#include "../sort/BubbleSort.hpp"

void BubbleSort::sort(Oscillo *os) {
    for (int i = 0; i < NB_FREQ - 1; i++) {
        for (int j = 0; j < NB_FREQ - 1 - i; j++) {
            if (os->getKey(j) > os->getKey(j + 1)) {
                os->update(j, j + 1, false);
            }
        }
    }
    os->update(0, 0, true);
}