#pragma once

#include <iostream>
#include "../header/parser.hpp"


int menu(std::string &sortName, int &argc, char **argv);

void menu_help();           // Message -h.
void menu_missing_so();     // Message missing -so.
void menu_blank_so();       // Message blank -so.