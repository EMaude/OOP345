#include "DataTable.h"

namespace w7 {
	template<class T>
	DataTable<T>::DataTable(std::ifstream file, const int FW, const int ND)
	{
		if (!file)
		{
			std::cout << "Invalid File" << std::cout;
		}
		else
		{
			while (!file.good())
			{
				T temp = 0;
				file >> temp;
				m_x.push_back(temp);
				file >> temp;
				m_y.push_back(temp);
			}
		}

	}

	template<class T>
	T DataTable<T>::mean() const
	{
		T mean = std::accumulate(m_y.begin(), m_y.end()) / m_y.size();
		return mean;
	}

	template<class T>
	T DataTable<T>::sigma() const
	{
		T sigma = sqrt( (std::accumulate(m_y.begin(), m_y.end()) * exp(m_y[i] - mean()) ) / m_y.size() - 1);
		return sigma;
	}

	template<class T>
	T DataTable<T>::median() const
	{
		std::sort(m_y.begin(), m_y.end());
		T median = m_y[m_y.size() / 2];
		return median;
	}

	template<class T>
	void DataTable<T>::regression(T & slope, T & y_intercept) const
	{
	}

	template<class T>
	void DataTable<T>::display(std::ostream &) const
	{
	}

	template<class T>
	std::ostream& operator<<(std::ostream &, const DataTable&)
	{
		// TODO: insert return statement here
	}
}