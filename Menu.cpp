#include "Menu.h"


void Menu::displayMenu() {
    const std::string border(40, '*');
    const std::string indent = "    ";

    // Print the menu
    std::cout << "\n" << border << std::endl;
    std::cout << "    * INVENTORY MANAGEMENT SYSTEM *" << std::endl;
    std::cout << border << "\n" << std::endl; // Two newlines for spacing

    std::cout << indent << "Please select an option:\n" << std::endl;

    std::cout << indent << "1. Search for an item" << std::endl;
    std::cout << indent << "2. Print item frequency list" << std::endl;
    std::cout << indent << "3. Print item frequency histogram" << std::endl;
    std::cout << indent << "4. Exit" << std::endl;

    std::cout << "\n" << indent << "Enter your choice [1-4]: ";
}