#ifndef CSVREADER_HPP
#define CSVREADER_HPP

#include <vector>
#include <fstream>

#include "CsvLine.hpp"

using namespace std;

class CsvReader {
private:
    vector<CsvLine> lines;
public:
    CsvReader() {}
    vector<CsvLine> read(string fileName);
};

vector<CsvLine> CsvReader::read(string fileName) {
    ifstream inputFile;
    vector<CsvLine> lines;
    inputFile.open(fileName);

    string line = "";
    while (getline(inputFile, line)) {
        CsvLine csvLine;
        csvLine.parse(line);
        lines.push_back(csvLine);
    }

    return lines;

    

    
}

#endif