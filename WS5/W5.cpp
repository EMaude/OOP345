#include <iostream>
#include <exception>
#include "Grades.h"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << argv[0] <<
			": incorrect number of arguments\n";
		std::cerr << "Usage: " << argv[0] << " file_name\n";
		return 1;
	}

	try {
		Grades grades(argv[1]);

		//lambda expression for letter
		auto letter = [](float g) -> const char*{
			if (g < 50) { return "F"; }
			else if (g >= 50 && g < 55) { return "D"; }
			else if (g >= 55 && g < 60) { return "D+"; }
			else if (g >= 60 && g < 65) { return "C"; }
			else if (g >= 65 && g < 70) { return "C+"; }
			else if (g >= 70 && g < 75) { return "B"; }
			else if (g >= 75 && g < 80) { return "B+"; }
			else if (g >= 85 && g < 90) { return "A"; }
			else if (g >= 90 && g < 100) { return "A+"; }
			else { throw "Error converting grade"; }
		};

		grades.displayGrades(std::cout, letter);
	}
	catch (const char* msg)
	{
		std::cout << msg << std::endl;
		std::terminate();
	}

	std::cout << "Press any key to continue ... ";
	std::cin.get();
}