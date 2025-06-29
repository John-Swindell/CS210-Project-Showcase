#ifndef FILEREADER_H
#define FILEREADER_H

#include <map>
#include <string>
#include <fstream>
#include <iostream>

class FileReader {
public:
    // Takes a filename and returns a map
    static std::map<std::string, int> ConvertFileToFrequencyMap(const std::string& fileName);
};

#endif // FILEREADER_H