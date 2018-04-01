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
		int m_FW;
		int m_ND;
	public:
		/*!
		Upon instantiation, a DataTable object receives a reference to the file stream that holds the data values, the field width for displaying the data and the number of decimals to display.  The object retrieves the data values from the file and stores them in its instance variables.
		*/
		DataTable(std::ifstream& file, const int FW, const int ND)
		{
			if (!file)
			{
				std::cout << "Invalid File" << std::endl;
			}
			else
			{
				while (file.good())
				{
					T temp = -1;
					file >> temp;
					if (temp != -1)
					{
						m_x.push_back(temp);
						file >> temp;
						m_y.push_back(temp);
					}
				}
			}

			m_FW = FW;
			m_ND = ND;
		}

		//! returns the mean value of the dependent coordinate
		T mean() const
		{
			T mean = std::accumulate(m_y.begin(), m_y.end(), 0) / m_y.size();
			return mean;
		}

		//! returns the standard deviation of the dependent coordinates
		T sigma() const
		{
			T m = mean();
			T sumDiffMeanSq = std::accumulate(m_y.begin(), m_y.end(), 0.0, [&](T a, T b) { return a + std::exp(b - m); });
			T ssd = sqrt(sumDiffMeanSq / m_y.size() - 1);
			return ssd;
		}

		//! returns the median value of the dependent coordinate
		T median() const
		{
			std::sort(&m_y.begin(), &m_y.end());
			T median = m_y[m_y.size() / 2];
			return median;
		}

		//! returns the slope and intercept for the data set
		void regression(T& slope, T& y_intercept) const
		{
			T sumX = std::accumulate(m_x.begin(), m_x.end(), 0.0);
			T expSumX = std::exp(sumX);
			T sumY = std::accumulate(m_y.begin(), m_y.end(), 0.0);
			int size = m_x.size();

			slope = ((size * (sumX * sumY)) - (sumX * sumY)) / ((size * expSumX) - expSumX);
			y_intercept = (sumY - (slope * sumX)) / size;
		}

		//! displays the data pairs as shown below
		void display(std::ostream& os) const
		{
			os.width(m_FW);
			os << std::right << "X";
			os.width(m_FW);
			os << std::right << "Y" << std::endl;

			for (int i = 0; i < m_x.size(); i++)
			{
				os.width(m_FW);
				os.precision(m_ND);
				os << std::right << std::fixed << m_x[i];

				os.width(m_FW);
				os.precision(m_ND);
				os << std::right << std::fixed << m_y[i] << std::endl;
			}
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const DataTable<T>& in)
	{
		in.display(os);
		return os;
	}
}
#endif //DATATABLE_H