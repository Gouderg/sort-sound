#include "../header/menu.hpp"


int main(int argc, char *argv[]) {
    std::string sortName, shuffleName;

    // Send to menu to get the value.
    // if (!menu(sortName, shuffleName, argc, argv)) return 0;

    sortName = "BubbleSort";
    shuffleName = "ShuffleKnuth";

    std::cout << sortName << ", " << shuffleName << std::endl;

    return 0;
}
