//============================================================================
// Name        : course.cpp
// Author      : Evan Mackey
// Version     : 1.0
// Copyright   : Copyright © 
// Description : course object file for ABCU Advising Program
//============================================================================

#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>

using namespace std;

// Creates Course object to store data from CSV file
struct Course {
    // Declares variables for course object
    string courseNumber;
    string courseName;
    string coursePreReq1;
    string coursePreReq2;
};

#endif