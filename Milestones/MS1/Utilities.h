#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
 #include <fstream>

 class Utilities {
     size_t field_width;           // maximum field width needed 
     static char delimiter;        // field delimiter character
     static std::ofstream logFile; // log file
 public:
     Utilities();
     void setFieldWidth(size_t fw);
     size_t getFieldWidth() const;
     const std::string nextToken(const std::string&, size_t&, bool&);

     static void setDelimiter(const char del) { Utilities::delimiter = del; };
     static void setLogFile(const char* log)
     {
        if(Utilities::logFile.is_open())
        {
			Utilities::logFile.close();
        }
		Utilities::logFile.open(log, std::ios::trunc);
        //Add Exception Handler for failed opening
    };
     static std::ofstream& getLogFile() { return Utilities::logFile; };

	 int ftrim(std::string &str);
	 int rtrim(std::string &str);
	 int trim(std::string &str);
 };

#endif //UTILITIES_H