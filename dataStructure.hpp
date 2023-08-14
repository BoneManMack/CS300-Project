//============================================================================
// Name        : dataStructure.cpp
// Author      : Evan Mackey
// Version     : 1.0
// Copyright   : Copyright © 
// Description : data structure and node file for ABCU Advising Program
//============================================================================

#include <string>
#include <iostream>

#include "course.hpp"

using namespace std;

#ifndef DATASTRUCTURE_CPP
#define DATASTRUCTURE_CPP

// Create Node for pointing to stored course data
struct Node {
    // Declare variables
    Course course;
    Node* left;
    Node* right;

    // Default constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }

    // Initialize node with a course
    Node(Course aCourse) :
        Node() {
            course = aCourse;
        }
};

// Binary Search Tree class
class CourseTree {
// Declare private variables and methods
private:
    Node* root;
    void printAll(Node* node);
    void addCourse(Node* node, Course course);
    void deleteTree(Node* node);

// Declare constructor, destructor, and public methods
public:
    CourseTree();
    virtual ~CourseTree();
    void AddCourse(Course course);
    void PrintAll();
    Course FindCourse(string course);
};

// Constructor, initialize root variable
CourseTree::CourseTree() {
    root = nullptr;
}

// Destructor
CourseTree::~CourseTree() {
    deleteTree(root);
}

// Method to recursively delete BST
void CourseTree::deleteTree(Node* node) {
    // check that node is not null
    if (node != nullptr) {
        // check for left pointer and recursive call to function to delete the left node
        if (node->left != nullptr) {
            deleteTree(node->left);
        }
        // check for right pointer and recursive call to function to delete the right node
        if (node->right != nullptr) {
            deleteTree(node->right);
        }
        // delete the node
        delete node;
    }
}

// Method to add course to the root node of the BST
void CourseTree::AddCourse(Course course) {
    // Checks root if no Node at root adds root node
    if (root == nullptr) {
        root = new Node(course);
    }
    // if root has a node call method to add course to BST
    else {
        this->addCourse(root, course);
    }
}

// Method to add node to BST
void CourseTree::addCourse(Node* node, Course course) {
    // if the current node is greater then the node to add
    if (node->course.courseNumber.compare(course.courseNumber) > 0) {
        // and the node to the left of the current node is empty
        if (node->left == nullptr) {
            // Assign the node to the node indicated by the left pointer
            node->left = new Node(course);
        }
        // Otherwise recursively call the function on the left node
        else {
            this->addCourse(node->left, course);
        }
    }
    // if the current node is less than or equal to the node tto add
    else {
        // and if the node to the right of the current node is empty
        if (node->right ==nullptr) {
            // assign the new node to the node indicated by the right pointer
            node->right = new Node(course);
        }
        // Otherwise recursively call the function on the right pointer
        else {
            this->addCourse(node->right, course);
        }
    }
}

// Method to start printing all courses in alpha-numeric order
void CourseTree::PrintAll() {
    // Calls print method from the root
    if (root != nullptr) {
        printAll(root);
    }
}

// Method to print courses in alpha-numeric order
void CourseTree::printAll(Node* node) {
    // Recursive call to the left node
    printAll(node->left);
    // Prints course data at node
    cout << "Number: " << node->course.courseNumber << "; " 
         << "Name: " << node->course.courseName << "; " 
         << "Prerequisites: " << node->course.coursePreReq1 << ", " 
                              << node->course.coursePreReq2 << endl;
    // Recursive call to the right node
    printAll(node->right);
}

// Method to search for a specific course
Course CourseTree::FindCourse(string courseNumber) {
    // Starts at root node
    Node* current = root;

    // While loop to stop if current node is a null pointer
    while (current != nullptr) {
        // If the course is found return the course
        if (current->course.courseNumber.compare(courseNumber) == 0) {
            return current->course;
        }
        // If the current course number is greater than the course being searched for
        if (current->course.courseNumber.compare(courseNumber) > 0) {
            // Assign current node to the left pointer
            current = current->left;
        } 
        // If the current course number is less than or equal to the node being searched for
        else {
            // assign the current node to the right pointer
            current = current->right;
        }
    }

    // If course is not found create an empty course variable and return it
    Course course;
    return course;
}

#endif