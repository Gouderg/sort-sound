#include "../header/parser.hpp"
#include "../header/menu.hpp"


int main(int argc, char *argv[]) {

    InputParser input(argc, argv);

    if(input.cmdOptionExists("-h") || input.cmdOptionExists("--help")) menu_help();

    return 0;
}
