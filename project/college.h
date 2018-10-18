//*******************************************************************
//                                                               	 
//  Class: 	College                                	 
//                                                                	 
//  Author:  	Mohamed Jallow
//  Email:   	mj530417@ohio.edu
//                                                               	 
//  Lab Section: Project 3
//                                                               	 
//  Description: The header for the College class. This class holds courses and student names, and allows the user to add courses in order, remove courses, see the total hours taken, see the gpa, display all the courses to the user,and test the copy constructor.
//  Date: Spring 2018
//                                                               	 
//*******************************************************************
#include <iostream>
#include <fstream>
#include <string>
#include "course.h"
#include "node.h"
#ifndef COLLEGE_H
#define COLLEGE_H

class College {
public:
	College();
	College(std::string name);
	~College();
	College(const College &other);
	College &operator = (const College &other);
	void display(std::ostream &ins);
	void remove(std::string target);
	void add(course c);
	void load(std::istream& ins);
	double hours();
	double gpa();
	void save(std::ostream& outs);
	void set_name(std::string name);
	void deleteNode(node* firstNode);



private:
	std::string student;
	node *head;

};

#endif