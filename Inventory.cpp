#include "Inventory.h"

// Default constructor
Inventory::Inventory() {
}

void Inventory::SetInventory(const std::map<std::string, int>& fullMenuMap) {
    // This refers to the private menuInventory
    this->menuInventory = fullMenuMap;
}

std::map<std::string, int> Inventory::GetInventory() const {
    return this->menuInventory;
}

void Inventory::PrintFrequencyList() const {
    std::cout << "\n--- Item Frequencies ---" << std::endl;
    for (auto const& [item, count] : this->menuInventory) {
        std::cout << item << " " << count << std::endl;
    }
}

void Inventory::PrintHistogram() const {
    std::cout << "\n--- Item Histogram ---" << std::endl;
    for (auto const& [item, count] : this->menuInventory) {
        std::cout << item << " ";
        // Print a star for each count
        for (int i = 0; i < count; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int Inventory::GetItemCount(const std::string& itemName) const {
    // .find() for safe search
    auto it = this->menuInventory.find(itemName);

    if (it != this->menuInventory.end()) {
        // Found return item count
        return it->second;
    } else {
        // Didn't find Return 0
        return 0;
    }
}