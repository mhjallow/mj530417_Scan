//*******************************************************************
//                                                               	 
//  Class: 	College                                	 
//                                                                	 
//  Author:  	Mohamed Jallow
//  Email:   	mj530417@ohio.edu
//                                                               	 
//  Lab Section: Project 3
//                                                               	 
//  Description: The implementation for the College class. This class holds courses and student names, and allows the user to add courses in order, remove courses, see the total hours taken, see the gpa, display all the courses to the user,and test the copy constructor.
//  Date: Spring 2018
//                                                               	 
//*******************************************************************
#include <iostream>
#include <fstream>
#include <string>
#include "course.h"
#include "node.h"
#include "college.h"

College::College()
{
	student = "N/A";
	head = NULL;
}

College::College(std::string name)
{
	student = name;
	head = NULL;
}

College::~College()
{
	node *rmptr;
	while (head != NULL)
	{
		rmptr = head;
		head = head->link();
		delete rmptr;
	}
}

College::College(const College &other)
{
	if (other.head == NULL)
	{
		head = NULL;
		return;
	}
	head = new node(other.head->data());
	node *s_ptr = other.head->link();
	node *d_ptr = head;
	while (s_ptr != NULL)
	{
		d_ptr->set_link(new node(s_ptr->data()));
		d_ptr = d_ptr->link();
		s_ptr = s_ptr->link();
	}
}

College& College::operator = (const College &other)
{
	if (this == &other)
	{
		return *this;
	}
	node *rmptr;
	while (head != NULL)
	{
		rmptr = head;
		head = head->link();
		delete rmptr;
	}
	node *s_ptr, *d_ptr;
	if (other.head != NULL)
	{
		head = new node(other.head->data());
		s_ptr = other.head->link();
		d_ptr = head;
		while (s_ptr != NULL)
		{
			d_ptr->set_link(new node(s_ptr->data()));
			d_ptr = d_ptr->link();
			s_ptr = s_ptr->link();
		}
	}
	return *this;
}

void College::display(std::ostream &outs)
{
	for (node* cursor = head; cursor != NULL; cursor = cursor->link())
		outs << cursor->data();
}

void College::remove(std::string target)
{
	node *cursor = head;
	node *previous = NULL;
	if (head->data().get_course_number() == target)
	{
		head = head->link();
		delete cursor;
	}
	else
	{
		while (cursor != NULL && cursor->data().get_course_number() != target)
		{
			previous = cursor;
			cursor = cursor->link();
		}
		if (previous == NULL)
		{
			return;
		}
		if (cursor != NULL)
		{
			previous->set_link(cursor->link());
			delete cursor;
		}
	}
}


void College::add(course c)
{
	if (!head)
	{
		head = new node(c);
		return;
	}
	node* curr = head, *prev = NULL;
	while (curr)
	{
		if (c < curr->data())
		{
			node* cursor = new node(c);
			cursor->set_link(curr);
			if (!prev)
			{
				head = cursor;
			}
			else
			{
				prev->set_link(cursor);
			}
			return;
		}
		prev = curr;
		curr = curr->link();
	}
	prev->set_link(new node(c));
}

void College::load(std::istream& ins)
{
	node *cursor;
	course in_course;
	cursor = new node;
	head = cursor;
	std::string name;
	getline(ins, name);
	set_name(name);
	while (!ins.eof())
	{
		ins >> in_course;
		cursor->set_data(in_course);
		cursor->set_link(new node);
		cursor = cursor->link();
	}
	deleteNode(head);
}

double College::hours()
{
	double total = 0;
	node *cursor = head;
	for (cursor; cursor != NULL; cursor = cursor->link())
	{
		total += cursor->data().get_hours();
	}
	return total;
}

double College::gpa()
{
	double sum = 0;
	double totalHours = 0;
	node *cursor = head;
	for (cursor; cursor != NULL; cursor = cursor->link())
	{
		double pointValue = 0;
		totalHours += cursor->data().get_hours();
		pointValue = cursor->data().get_number_grade() * cursor->data().get_hours();
		sum += pointValue;
	}
	return sum / totalHours;
}

void College::save(std::ostream& outs)
{
	for (node* cursor = head; cursor != NULL; cursor = cursor->link())
		outs << cursor->data();
}

void College::set_name(std::string name)
{
	student = name;
}

void College::deleteNode(node* firstNode)
{
	if (firstNode == NULL)
		return;

	if (firstNode->link() == NULL)
	{
		delete firstNode;
		firstNode = NULL;
		return;
	}

	node* currNode = firstNode;
	while (currNode->link() && currNode->link()->link() != NULL)
	{
		currNode = currNode->link();
	}
	delete currNode->link();
	currNode->set_link(NULL);
}