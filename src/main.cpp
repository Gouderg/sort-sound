#include "../header/menu.hpp"
#include "../header/interfacebase.hpp"
#include "../header/gui.hpp"
#include "../header/shell.hpp"
#include "../header/oscillo.hpp"


#include "../sort/BubbleSort.hpp"
#include "../sort/SelectionSort.hpp"
#include "../sort/InsertionSort.hpp"
#include "../sort/QuickSort.hpp"


#include <thread>

int main(int argc, char *argv[]) {
    std::cout << __cplusplus << std::endl;

    /*  Menu input.  */
    std::string sortName;
    int gui_mode = 1;
    
    // Send to menu to get the value.
    if (!menu(sortName, gui_mode, argc, argv)) return 0;

    // Create UI.
    InterfaceBase *gui = nullptr; 
    if (gui_mode) {
        gui = new Gui();
    } else {
        gui = new Shell();
    }
    
    // Launch in other thread.
    std::thread th(&InterfaceBase::run, gui); 

    // Create Oscillo object and Algorithm Object.
    Oscillo os(gui, gui_mode);
    AlgoBase *al1 = getSortAlgorithm(sortName);

    // Shuffle.
    os.setKeys(al1->shuffle(os.getKeys()));

    // Sort.
    al1->sort(&os);

    // Finish.
    th.join();

    // Free.
    delete gui;
    delete al1;

    return 0;
}
