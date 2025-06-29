#include <iostream>
#include "FileReader.h"
#include "Inventory.h"
#include "Menu.h"
#include <string>


int main() {

    std::cout << "Loading inventory..." << std::endl;
    const std::map<std::string, int> inventoryMap = FileReader::ConvertFileToFrequencyMap("CS210_Project_Three_Input_File.txt");

    if (inventoryMap.empty()) {
        std::cout << "Could not read or process the inventory file. Exiting." << std::endl;
        return 1;
    }
    // Create new inventory object and pass map to set params
    Inventory storeInventory;
    storeInventory.SetInventory(inventoryMap);
    std::cout << "Inventory loaded successfully." << std::endl;

    int numInput = 0;

    while (numInput != 4) {
        Menu::displayMenu();
        std::cin >> numInput;
        if (std::cin.fail()) { // Check if the input stream is in a failed state
            std::cout << "\n** Invalid input. Please enter a number. **\n" << std::endl;
            std::cin.clear(); // Clear error
            std::cin.ignore(1000, '\n'); // Clear buffer
            numInput = 0;
            continue; // Skip the rest of loop iteration
        }

        if (numInput == 1) {
            std::string itemToSearch;
            std::cout << "Enter item to search for:";
            std::cin >> itemToSearch;
            if (const int itemCount = storeInventory.GetItemCount(itemToSearch); itemCount > 0) {
                std::cout << "** There are " << itemCount << " " << itemToSearch << " **"<< std::endl;
            } else {
                std::cout << "** Sorry, '" << itemToSearch << "' was not found in the inventory." << " **" << std::endl;
            }
        } else if (numInput == 2) {
            storeInventory.PrintFrequencyList();
        } else if (numInput == 3) {
            storeInventory.PrintHistogram();
        } else if (numInput == 4) {
            break;
        } else {
            std::cout << "\n** Please enter a number. 1-4 **\n" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            numInput = 0;
        }
    }
    std::cout << "Goodbye" << std::endl;
    return 0;
}