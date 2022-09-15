#include "../header/menu.hpp"
#include "../header/gui.hpp"
#include "../header/oscillo.hpp"


#include "../sort/BubbleSort.hpp"
#include "../sort/SelectionSort.hpp"
#include "../sort/InsertionSort.hpp"
#include "../sort/QuickSort.hpp"


#include <thread>

int main(int argc, char *argv[]) {

    /*  Menu input.  */
    std::string sortName;
    
    // Send to menu to get the value.
    if (!menu(sortName, argc, argv)) return 0;
       
    // sortName = "BubbleSort";
    std::cout << sortName << std::endl;

    // Create UI.
    Gui *gui = new Gui();

    // Launch in other thread.
    std::thread th(&Gui::run, gui);

    // Create Oscillo object and Algorithm Object.
    Oscillo os(gui);
    AlgoBase *al1 = getSortAlgorithm(sortName);

    // Shuffle.
    os.setKeys(al1->shuffle(os.getKeys()));

    // Sort.
    al1->sort(&os);

    // Finish.
    th.join();
    delete gui;
    delete al1;

    return 0;
}
