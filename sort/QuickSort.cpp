#include "../sort/QuickSort.hpp"

void QuickSort::sort(Oscillo* os) {
    quickSort(os, 0, NB_FREQ-1);
    os->update(0, 0, false, true);
}


void QuickSort::quickSort(Oscillo *os, int low, int high) {
    
    if (low < high) { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(os, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(os, low, pi - 1); 
        quickSort(os, pi + 1, high); 
    } 
}

int QuickSort::partition(Oscillo *os, int low, int high) {
    int pivot = os->getKey(high); // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++)  { 
        // If current element is smaller than the pivot 
        if (os->getKey(j) < pivot)  { 
            i++; // increment index of smaller element 
            os->update(i, j, true, false);

        } 
    } 
    os->update(i + 1, high, true, false); 
    return (i + 1); 
}