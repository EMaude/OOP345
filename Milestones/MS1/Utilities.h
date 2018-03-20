#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
 #include <fstream>

//! Holds various utilities
 class Utilities {
     size_t field_width;           // maximum field width needed 
     static char delimiter;        // field delimiter character
     static std::ofstream logFile; // log file
 public:

	 //! Sets field width to 1
     Utilities();

	 //!Sets the objects field width
	 /*!
	 \param fw - the value for the feild width of the object
	 \sa getFeildWidth()
	 */
     void setFieldWidth(size_t fw);

	 //! Gets the objects field width
	 /*
	 \return feild width
	 \sa setFieldWidth()
	 */
     size_t getFieldWidth() const;

	 //! gets the next token in a string
	 /*!
	 Reads from the provided position in the string until the delimeter in the object is found. Returns a trimmed string from pos to the next delimeter. Sets the feild width to that length if the current field width is shorter.
	 \param in The input string
	 \param pos The position to start reading from
	 \param more Changes the more boolean to true if there is more to read after the delimeter. 
	 \return trimmed string from pos to the next delimeter
	 \sa trim(), setDelimiter() and setFieldWidth()
	 */
     const std::string nextToken(const std::string&, size_t&, bool&);

	 //! sets the class variable delimiter
	 /*!
	 \param del char to set the delimiter to.
	 */
     static void setDelimiter(const char del) { Utilities::delimiter = del; };

	 //! Opens a log file held in the class variable logFile
	 /*!
	 \param log filename to open in trunc mode
	 */
     static void setLogFile(const char* log)
     {
        if(Utilities::logFile.is_open())
        {
			Utilities::logFile.close();
        }
		Utilities::logFile.open(log, std::ios::trunc);
        //Add Exception Handler for failed opening
    };

	 //! Gets the logFile reference
	 /*!
	 \return A reference to the ofstream class variable logFile 
	 \sa setLogFile()
	 */
     static std::ofstream& getLogFile() { return Utilities::logFile; };

	 //! trims whitespace from the front of a string
	 /*!
	 \param str the string to trim
	 \return the number of characters trimmed
	 */
	 int ftrim(std::string &str);

	 //! trims whitespace from the back of a string
	 /*!
	 \param str the string to trim
	 \return the number of characters trimmed
	 */
	 int rtrim(std::string &str);

	 //! trims whitespace from a string
	 /*!
	 \param str the string to trim
	 \return the number of characters trimmed
	 \sa ftrim() and rtrim()
	 */
	 int trim(std::string &str);
 };

#endif //UTILITIES_H