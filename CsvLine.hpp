#ifndef CSVLINE_HPP
#define CSVLINE_HPP

#include <string>
#include <sstream>
#include <vector>

using namespace std;

class CsvLine {
private:
    vector<string> values;
public:
    // default constructor
    CsvLine () {}

    // copy constructor
    CsvLine (const CsvLine& other) {
        values = other.values;
    }
    
    // Overload operator
    CsvLine operator = (const CsvLine& other) {
        values = other.values;
    }
    // default destructor
    ~CsvLine() {}
    void parse(string line, char delimiter = ',');
    string getString(int column);
};


void CsvLine::parse(string line, char delimiter) {
    stringstream inLine(line);
    string temp = "";
    while (getline(inLine, temp, delimiter)) {
        values.push_back(temp);
    }
}

string CsvLine::getString(int column) {
    return values[column];
}

#endif