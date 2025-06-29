#include "FileReader.h"

std::map<std::string, int> FileReader::ConvertFileToFrequencyMap(const std::string& fileName) {
    std::map<std::string, int> frequencyMap;
    std::string currentItem;
    std::ifstream inventoryFile(fileName);

    // Check if the input file opened
    if (!inventoryFile.is_open()) {
        std::cout << "Error: Could not open file " << fileName << std::endl;
        return {};
    }

    // Read the file and populate the map
    while (getline(inventoryFile, currentItem)) {
        frequencyMap[currentItem]++;
    }
    inventoryFile.close();

    // Create the backup file from the map
    std::ofstream backupFile("backupFile.dat");

    // Check if the backup file opened successfully
    if (!backupFile.is_open()) {
        std::cout << "Error: Could not create backup file." << std::endl;
        return frequencyMap;
    }

    for (const auto& [fst, snd] : frequencyMap) {
        backupFile << fst << " " << snd << std::endl;
    }

    backupFile.close();

    return frequencyMap;
}