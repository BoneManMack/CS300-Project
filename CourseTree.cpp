//============================================================================
// Name        : CourseTree.cpp
// Author      : Evan Mackey
// Version     : 1.0
// Copyright   : Copyright © 
// Description : Main file for ABCU Advising Program
//============================================================================

#include <iostream>
#include <string>
#include <fstream>

// Imports data structure, node, and course object
#include "dataStructure.hpp"
#include "csvreader.hpp"
//#include "CSVparser.hpp"

using namespace std;

// FIXME: delete this nonsense
// Open file function
void fileOpener() {
    // Declare variable to store file name
    string courseCsv;
    ifstream courseFile;
    // FIXME: change to input
    courseCsv = "Module 7 project input.csv";

    // open file
    courseFile.open(courseCsv);

    // check that file opened correctly
    if (courseFile.fail()) {
        cout << "Unable to open file " << courseCsv << endl;
    }

    while (courseFile.peek() != EOF) {
        string aThingy;
        getline(courseFile, aThingy, ',');
        cout << aThingy << endl;
    }

    // close file
    courseFile.close();
}

// Loads courses
/*void loadCourses(string csvPath, CourseTree* cTree) {
    // Initialize csv parser with given path
    csv::Parser file = csv::Parser(csvPath);
    // read and display header row - optional
    vector<string> header = file.getHeader();
    for (auto const& c : header) {
        cout << c << " | ";
    }
    cout << "" << endl;

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Course course;
            course.courseNumber = file[i][0];
            course.courseName = file[i][1];
            course.coursePreReq1 = file[i][2];
            course.coursePreReq2 = file[i][3];

            //cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

            // push this bid to the end
            cTree->AddCourse(course);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
}*/

// Prints searched for course to screen
void displayCourse(Course course) {
    cout << "Number: " << course.courseNumber << "; " 
         << "Name: " << course.courseName << "; " 
         << "Prerequisites: " << course.coursePreReq1 << ", " 
                              << course.coursePreReq2 << endl;
    return;
}

// Main function, prints menu
int main() {

    // declare and initialize variable for loop control
    int menuControl = 0;

    // Declare and initialize pointer for print all function
    CourseTree* cTree;
    cTree = new CourseTree();

    // Declare variable for search function
    string courseSearch;
    Course course;
    string userFile;

    CsvReader reader;
    vector<CsvLine> lines;

    /*lines = reader.read("Module 7 project input.csv");
    for (auto line : lines) {
        cout << "Num " << line.getString(0) << " Name " << line.getString(1) << " pre1 " << line.getString(2) << " pre2 " << line.getString(3) << endl;
    }*/

    // While loop to maintain fuunction until user input the exit command
    while (menuControl != 4) {
        // Display menu
        cout << "MENU" << endl;
        cout << "1: Load Data Structure" << endl;
        cout << "2: Print Course List" << endl;
        cout << "3: Print Course" << endl;
        cout << "4: Exit" << endl;
        cout << "Enter your selection" << endl;

        // FIXME: error catch for incorrect inputs
        
        //gets user input
        cin >> menuControl;
    
        // conditional statement to control application
        switch (menuControl) {
            case 1:
                // Prompt user and get get input for file name
                cout << "Input file name: ";
                //cin >> userFile;
                //loadCourses(userFile, cTree);
                fileOpener();
                break;
            // Prints all courses in alpha-numeric order
            case 2:
                cTree->PrintAll();
                break;
            // Searches and prints for specific course
            case 3:
                // Get user input for search
                cout << "Input course number: ";
                cin >> courseSearch;
                course = cTree->FindCourse(courseSearch);
                if (!course.courseNumber.empty()) {
                    displayCourse(course);
                }
                else {
                    cout << "Course number " << courseSearch << " was not found." << endl;
                }
                break;
        }
        
        
        
    }

    // Courtesy farewell because I just didn't feel like deleting it and a single line has a low runtime and computational complexity
    cout << "Good bye" << endl;

    // return 0 to prevent error
    return 0;
}