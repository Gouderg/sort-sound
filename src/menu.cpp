#include "../header/menu.hpp"



void menu_help() {
    std::cout << "usage: sortman [-h] [-so SORT_ALGO_NAME] \n";
    std::cout << "\nSorting algorithm visualizer\n"; 
    std::cout << "\noptional arguments\n";
    std::cout << "\t-h, --help \t\t\t\t\t\t  Show this help message and exit.\n";
    std::cout << "\t-so SORT_ALGO_NAME, --sort SORT_ALGO_NAME \t\t  Sorting algorithm.\n";
    std::cout << std::endl;
}

void menu_missing_so() {
    std::cout << "usage: ./sortman [-h] [-so SORT_ALGO_NAME] \n";
    std::cout << "./sortman: error: missing -so SORT_ALGO_NAME or --sort SORT_ALGO_NAME \n";
    std::cout << std::endl;
}

void menu_blank_so() {
    std::cout << "usage: ./sortman [-h] [-so SORT_ALGO_NAME] \n";
    std::cout << "./sortman: error: missing name -so SORT_ALGO_NAME or --sort SORT_ALGO_NAME \n";
    std::cout << std::endl;
}


int menu(std::string &sortName, int &argc, char **argv) {


    // Parse arguments.
    InputParser input(argc, argv);

    // Help Menu.
    if (input.cmdOptionExists("-h") || input.cmdOptionExists("--help")) {
        menu_help();
        return 0;
    }

    // Sort algo not specify.
    if (!input.cmdOptionExists("-so") && !input.cmdOptionExists("--sort")) {
        menu_missing_so();
        return 0;
    }

    // Get the sort algorithm.
    const std::string &so1 = input.getCmdOption("-so");
    const std::string &so2 = input.getCmdOption("--sort");

    if (so1.empty() && so2.empty()) {
        menu_blank_so();
        return 0;
    } else {
        sortName = (so1.empty()) ? so2 : so1;
    }

    return 1;
}