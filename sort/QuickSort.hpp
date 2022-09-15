#pragma once

#include "../header/algobase.hpp"

class QuickSort: public AlgoBase {

    public:
        QuickSort(){}

        void sort(Oscillo *os);

        int partition(Oscillo *os, int low, int high);
        void quickSort(Oscillo *os, int low, int high);

};