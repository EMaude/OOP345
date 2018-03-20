#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <iomanip>

//! Holds the structure of a task  
/*!
*/
 class Task {
     std::string name;          // name of the task
     std::string slots;         // number of slots
     std::string nextTask[2];   // names of the next tasks
     const Task* pNextTask[2];  // addresses of the next tasks
	 static size_t field_width; // current maximum field width of all Task objects

 public:
	 //! Used to select the next task to complete
     enum Quality {
         passed,
         redirect
     }; 

	 //! Initalizes to a safe state, then reads the tokens from the parameter string to populate data
	 /*!
	 The constructor initializes the number of product slots to a default value of 1 and the pointers to the next tasks to safe addresses.  The constructor then uses a Utilities object to extract each token from the record. Once the constructor has extracted all of the tokens from the record, it retrieves the maximum field width needed by the extracted tokens.  If that field width is greater than field_width, the constructor resets this class variable to the value retrieved. 
	  \param  in - a string which contains a single record in the structure of:  Name | Slots | SuccessTask | FailTask 
	  \sa Utilities::nextToken()
	 */
     Task(const std::string&);

	 //! Returns the name of the task
	 /*! 
	 \return Const reference to the task name.
	 */
     const std::string& getName() const;

	 //! Validates and stores the next tasks
	 /*! 
	 compares the name of the parameter task to the next tasks stored in the current object. If the names match the address of the passed task is stored.
	 \param task - Reference to the task to validate against
	 \return Boolean - true if both tasks in the object either point to another task object, or have no name.
	 */
     bool validate(const Task&);

	 //! Returns the number of production slots avaliable to the task
	 /*!
	 \return An integer of the slots converted from string
	 */
     unsigned int getSlots() const;

	 //! Returns the next task based on Quality
	 /*!
	 The selected Quality is used to select which of the stored tasks should be next.
	 \param q - The Quality that has been selected
	 \return A reference to the selected task
	 \sa Quality
	 */
     const Task* getNextTask(Quality) const; 

	 //! Displays the current task to the ostream object
	 /*!
	 uses the field width to display the name, slots and next task(s) in the current object.
	 \param os The ostream object to output to
	 */
     void display(std::ostream&) const;

	 //! Returns the feild width for the class
	 /*!
	 \return size_t of the feild width from the tokens that have been stored in the class
	 */
	 static size_t getFieldWidth() { return field_width; }
 };

 //! Checks if tasks are the same based on name
 bool operator==(const Task&, const Task&);

#endif //TASK_H