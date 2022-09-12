#include "../header/menu.hpp"



void menu_help() {
    std::cout << "usage: sortman [-h] [-sh SHUFFLE_ALGO_NAME] [-so SORT_ALGO_NAME] \n";
    std::cout << "\nSorting algorithm visualizer\n"; 
    std::cout << "\noptional arguments\n";
    std::cout << "\t-h, --help \t\t\t\t\t\t  Show this help message and exit.\n";
    std::cout << "\t-so SORT_ALGO_NAME, --sort SORT_ALGO_NAME \t\t  Sorting algorithm.\n";
    std::cout << "\t-sh SHUFFLE_ALGO_NAME, --shuffle SHUFFLE_ALGO_NAME \t  Shuffle algorithm.\n"; 
    std::cout << std::endl;
}

void menu_missing_so() {
    std::cout << "usage: ./sortman [-h] [-sh SHUFFLE_ALGO_NAME] [-so SORT_ALGO_NAME] \n";
    std::cout << "./sortman: error: missing -so SORT_ALGO_NAME or --sort SORT_ALGO_NAME \n";
    std::cout << std::endl;
}

void menu_missing_sh() {
    std::cout << "usage: ./sortman [-h] [-sh SHUFFLE_ALGO_NAME] [-so SORT_ALGO_NAME] \n";
    std::cout << "./sortman: error: missing -sh SHUFFLE_ALGO_NAME or --shuffle SHUFFLE_ALGO_NAME \n";
    std::cout << std::endl;
}

void menu_blank_so() {
    std::cout << "usage: ./sortman [-h] [-sh SHUFFLE_ALGO_NAME] [-so SORT_ALGO_NAME] \n";
    std::cout << "./sortman: error: missing name -so SORT_ALGO_NAME or --sort SORT_ALGO_NAME \n";
    std::cout << std::endl;
}

void menu_blank_sh() {
    std::cout << "usage: ./sortman [-h] [-sh SHUFFLE_ALGO_NAME] [-so SORT_ALGO_NAME] \n";
    std::cout << "./sortman: error: missing name -sh SHUFFLE_ALGO_NAME or --shuffle SHUFFLE_ALGO_NAME \n";
    std::cout << std::endl;
}


int menu(std::string &sortName, std::string &shuffleName, int &argc, char **argv) {


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

    // Shuffle algo not specify.
    if (!input.cmdOptionExists("-sh") && !input.cmdOptionExists("--shuffle")) {
        menu_missing_sh();
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

   // Get the shuffle algorithm.
    const std::string &sh1 = input.getCmdOption("-sh");
    const std::string &sh2 = input.getCmdOption("--shuffle");

    if (sh1.empty() && sh2.empty()) {
        menu_blank_sh();
        return 0;
    } else {
        shuffleName = (sh1.empty()) ? sh2 : sh1;
    }

    return 1;
}