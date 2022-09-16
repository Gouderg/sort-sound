#include "../header/menu.hpp"



void menu_help() {
    std::cout << "usage: sortman [-h] [-so SORT_ALGO_NAME] [-ng]\n";
    std::cout << "\nSorting algorithm visualizer\n"; 
    std::cout << "\noptional arguments\n";
    std::cout << "\t-h, --help \t\t\t  Show this help message and exit.\n";
    std::cout << "\t--sort SORT_ALGO_NAME \t\t  [BubbleSort, SelectionSort, InsertionSort, QuickSort].\n";
    std::cout << "\t-ng, --no_gui \t\t\t  Disable SFML Interface.\n";
    std::cout << std::endl;
}

void menu_missing_so() {
    std::cout << "usage: sortman [-h] [-so SORT_ALGO_NAME] [-ng]\n";
    std::cout << "./sortman: error: missing --sort SORT_ALGO_NAME \n";
    std::cout << std::endl;
}

void menu_blank_so() {
    std::cout << "usage: sortman [-h] [-so SORT_ALGO_NAME] [-ng]\n";
    std::cout << "./sortman: error: missing name --sort SORT_ALGO_NAME \n";
    std::cout << std::endl;
}


int menu(std::string &sortName, int& gui, int &argc, char **argv) {


    // Parse arguments.
    InputParser input(argc, argv);

    // Help Menu.
    if (input.cmdOptionExists("-h") || input.cmdOptionExists("--help")) {
        menu_help();
        return 0;
    }

    // Gui.
    if (input.cmdOptionExists("-ng") || input.cmdOptionExists("--no_gui")) {
        std::cout << "Terminal Graphics mode enable." << std::endl;
        gui = 0;
    }

    // Sort algo not specify.
    if (!input.cmdOptionExists("--sort")) {
        menu_missing_so();
        return 0;
    }

    // Get the sort algorithm.
    const std::string &so2 = input.getCmdOption("--sort");

    if (so2.empty()) {
        menu_blank_so();
        return 0;
    } else {
        sortName = so2;
    }

    return 1;
}

AlgoBase* getSortAlgorithm(const std::string sortName) {

    if (sortName == "InsertionSort") return new InsertionSort();
    else if (sortName == "BubbleSort") return new BubbleSort();
    else if (sortName == "SelectionSort") return new SelectionSort();
    else if (sortName == "QuickSort") return new QuickSort();

    std::cout << "Bad name, launch with SelectionSort" << std::endl;

    return new SelectionSort();
}