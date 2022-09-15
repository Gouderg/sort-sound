#pragma once

#include <iostream>
#include "../header/parser.hpp"

#include"../header/algobase.hpp"

#include "../sort/BubbleSort.hpp"
#include "../sort/SelectionSort.hpp"
#include "../sort/InsertionSort.hpp"
#include "../sort/QuickSort.hpp"


int menu(std::string &sortName, int &argc, char **argv);

void menu_help();           // Message -h.
void menu_missing_so();     // Message missing -so.
void menu_blank_so();       // Message blank -so.

AlgoBase* getSortAlgorithm(const std::string sortName);