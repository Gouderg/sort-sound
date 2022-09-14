#include "../sort/SelectionSort.hpp"

void SelectionSort::sort(Oscillo *os) {
    int min = 0;
    for (int i = 0; i < NB_FREQ - 1; i++) {
        min = i;
        for (int j = i + 1; j < NB_FREQ; j++) {
            if (os->getKey(j) < os->getKey(min)) {
                min = j;
            }
        }
        if (min != i) os->update(i, min, true, false);
    }
    os->update(0, 0, false, true);  
}