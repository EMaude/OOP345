#ifndef GRADES_H
#define GRADES_H

#include <string>
#include <iostream>
#include <fstream>
#include <istream>
#include <functional>
#include <iterator>
#include <algorithm>

class Grades
{
private:
	//!Hold the student numbers
	int *studentNums;
	//!Hold the grades
	float *grades;
	//!Holds the size of the student number and grades arrays
	int size;

public:
	//!Grades Constuctor takes in a file, counts the records and allocates memory. Then reads the records into the arrays. Closes the file.
	Grades(const char* filename);
	//!Destroys the dynamic memory
	~Grades();
	//! Deleted Copy Constructor
	Grades(Grades&) = delete;
	//! Deleted Copy Operator
	Grades operator=(Grades&) = delete;
	//! Deleted Move Constructor
	Grades(Grades&&) = delete;
	//! Deleted Move Operator
	Grades& operator=(Grades&&) = delete;
	//! Display function, outputs Student Num, Grade(Number), Grade(letter) for each record. Number to letter conversion done through lambda -> const char*(float)
	void displayGrades(std::ostream &os, const std::function<const char*(float)>& func) const;
};
#endif // !GRADES_H
