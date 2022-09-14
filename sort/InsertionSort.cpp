#include "../sort/InsertionSort.hpp"

void InsertionSort::sort(Oscillo *os) {
    int x = 0, j = 0;
    for (int i = 1; i < NB_FREQ; i ++) {
        x = os->getKey(i);
        j = i-1;
        while (j >= 0 && os->getKey(j) > x) {
            os->update(j+1, os->getKey(j));
            j -= 1;
        }
        os->update(j+1, x);
    }
    os->update(0, 0, false, true);   
}