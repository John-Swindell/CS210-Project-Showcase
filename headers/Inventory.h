#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <map>
#include <string>

class Inventory {
public:
    // Constructor
    Inventory();

    void SetInventory(const std::map<std::string, int>& frequencyMap);    // This is a setter that populates the private data member
    std::map<std::string, int> GetInventory() const;    // Returns a copy of the inventory map
    void PrintFrequencyList() const;    // Prints a frequency list to the console
    void PrintHistogram() const;    // Prints a histogram representation to the console
    int GetItemCount(const std::string& itemName) const;    // Searches for an item and returns its count and returns 0 if not found

private:
    std::map<std::string, int> menuInventory;
};

#endif //INVENTORY_H