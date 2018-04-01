#ifndef DATATABLE_H
#define DATATABLE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

namespace w7 {
	template <class T>
	class DataTable
	{
	private:
		std::vector<T> m_x;
		std::vector<T> m_y;
	public:
		/*!
		Upon instantiation, a DataTable object receives a reference to the file stream that holds the data values, the field width for displaying the data and the number of decimals to display.  The object retrieves the data values from the file and stores them in its instance variables.
		*/
		DataTable(std::ifstream file, const int FW, const int ND);

		T mean() const; //!< returns the mean value of the dependent coordinate
		T sigma() const; //!< returns the standard deviation of the dependent coordinates
		T median() const; //!< returns the median value of the dependent coordinate
		void regression(T& slope, T& y_intercept) const; //!< returns the slope and intercept for the data set

		void display(std::ostream&) const; //!< displays the data pairs as shown below
	};

	template<class T>
	std::ostream& operator<<(std::ostream&, const DataTable &);
}
#endif //DATATABLE_H