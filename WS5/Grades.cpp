#include "Grades.h"

Grades::Grades(const char * filename)
{
	//Start in initalized state
	size = 0;
	grades = nullptr;
	studentNums = nullptr;

	//open file
	std::ifstream file(filename);
	if (!file)
	{
		throw "Failed to Open File";
	}

	//Read number of records 
	file.unsetf(std::ios_base::skipws); //dont skip newlines

	size = std::count(
		std::istream_iterator<char>(file),
		std::istream_iterator<char>(), '\n'
	);

	//Allocate Memory
	try {
		grades = new float[size];
		studentNums = new int[size];
	}
	catch (std::bad_alloc)
	{
		throw "Bad Alloc";
	}

	//Assign to Memory
	file.clear(); //clear eof bit 
	file.seekg(0, std::ios::beg); //go to start of file
	file.setf(std::ios_base::skipws); //skip newlines
	for (int i = 0; i < size; i++)
	{
		try
		{
			file >> studentNums[i];
			file >> grades[i];
			file.exceptions(file.failbit);
		}
		catch(std::ios_base::failure &fail)
		{
			throw "Failed to read records";
		}
	}

	//close file
	file.close();
}

Grades::~Grades()
{
	delete[] grades;
	delete[] studentNums;
	size = 0;
	grades = nullptr;
	studentNums = nullptr;
}

void Grades::displayGrades(std::ostream &os, const std::function<const char*(float)>& func) const
{
	for (int i = 0; i < size; i++)
	{
		os << studentNums[i] << " " << grades[i] << " " << func(grades[i]) << std::endl;
	}
}
