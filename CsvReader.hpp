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

    int courseCount = 0;
    string temp;

    while (inputFile.peek() != EOF) {
        getline(inputFile, temp);
        ++courseCount;
    }

    lines.resize(courseCount);

    string line = "";
    CsvLine csvLine;
    for (int i = 0; i < courseCount; ++i) {
        getline(inputFile, line);
        csvLine.parse(line);
        lines.push_back(csvLine);
    }

    
    /*while (getline(inputFile, line)) {
        
        csvLine.parse(line);
        lines.push_back(csvLine);
    }*/

    return lines;

    

    
}

#endif