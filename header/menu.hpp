#pragma once

#include <iostream>
#include "../header/parser.hpp"



int menu(std::string &sortName, std::string &shuffleName, int &argc, char **argv);
void menu_help();

void menu_missing_so();
void menu_missing_sh();
void menu_blank_so();
void menu_blank_sh();
void menu_error();

