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

		m_FW = FW;
		m_ND = ND;
	}

	template<class T>
	T DataTable<T>::mean() const
	{
		T mean = std::accumulate(m_y.begin(), m_y.end(), 0) / m_y.size();
		return mean;
	}

	template<class T>
	T DataTable<T>::sigma() const
	{
		//USE LAMBDA

		std::vector<T> diffMeanSq;
		for (int i = 0; i < m_y.size(); i++){ temp = std::exp(m_y[i] - mean());}

		T sumDiffMeanSq = std::accumulate(diffMeanSq.begin(), diffMeanSq.end(), 0);

		T ssd = sqrt(sumDiffMeanSq / m_y.size() - 1);
		return ssd;
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
		T sumX = std::accumulate(m_x.begin(), m_x.end(), 0);
		T expSumX = std::exp(sumX);
		T sumY = std::accumulate(m_y.begin(), m_y.end(), 0);
		int size = m_x.size();

		slope = ((size * (sumX * sumY)) - (sumX * sumY)) / ((n * expSumX) - expSumX);
		y_intercept = (sumY - (slope * sumX)) / size;
	}

	template<class T>
	void DataTable<T>::display(std::ostream &os) const
	{
		os.width(m_FW);
		os << std::right << "X";
		os.width(m_FW);
		os << std::right << "X";

		for (int i = 0; i < m_x.size(); i++)
		{
			os.width(m_FW);
			os.precision(m_ND);
			os << std::right << std::fixed << m_X[i];

			os.width(m_FW);
			os.precision(m_ND);
			os << std::right << std::fixed << m_Y[i];
		}
	}

	std::ostream& operator<<(std::ostream &os, const DataTable &in)
	{
		in.display(os);
		return os;
	}
}