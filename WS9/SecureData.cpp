#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include <vector>
#include "SecureData.h"

namespace w10 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key) {
		// open text file
		std::fstream input(file, std::ios::in);
		if (!input)
			throw std::string("\n***Failed to open file ") +
			std::string(file) + std::string(" ***\n");

		// copy from file into memory
		nbytes = 0;
		input >> std::noskipws;
		while (input.good()) {
			char c;
			input >> c;
			nbytes++;
		}
		nbytes--;
		input.clear();
		input.seekg(0, std::ios::beg);
		text = new char[nbytes + 1];

		int i = 0;
		while (input.good())
			input >> text[i++];
		text[--i] = '\0';
		std::cout << "\n" << nbytes << " bytes copied from text "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		std::cout << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key) {

		int noThreads = 7;

		int tsize = nbytes / noThreads;


		auto f1 = std::bind(converter, std::placeholders::_1, key, std::placeholders::_2, Cryptor());

		std::vector<char*> split;
		std::vector<std::thread> threads;

		for (int i = 0; i < noThreads; i++)
		{
			char* t = nullptr;
			if (nbytes % noThreads != 0 && i == noThreads - 1)
			{
				int ntsize = tsize + (nbytes % noThreads);
				t = new char[ntsize + 1];
				strncpy(t, text + (tsize * i), ntsize);
				split.push_back(t);
				threads.push_back(std::thread(f1, split[i], ntsize));
			}
			else
			{
				t = new char[tsize + 1];
				strncpy(t, text + (tsize * i), tsize);
				split.push_back(t);
				threads.push_back(std::thread(f1, split[i], tsize));
			}
		}

		tsize = nbytes / noThreads;

		delete[] text;
		text = new char[nbytes + 1];

		for (int i = 0; i < noThreads; i++)
		{
			threads[i].join();
			if (nbytes % noThreads != 0 && i == noThreads - 1)
			{
				int ntsize = tsize + (nbytes % noThreads);
				strncpy(text + (tsize * i), split[i], ntsize);
			}
			else
			{
				strncpy(text + (tsize * i), split[i], tsize);
			}
		}

		encoded = !encoded;

		for (int i = 0; i < noThreads; i++)
		{
			delete[] split[i];
			split[i] = nullptr;
		}
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else {
			// open binary file
			std::ofstream fs(file, std::ios::out | std::ios::binary | std::ios::trunc);
			// write binary file here
			fs.write(text, nbytes);
		}
	}

	void SecureData::restore(const char* file, char key) {
		// open binary file
		std::ifstream fs(file, std::ios::in | std::ios::binary | std::ios::ate);

		// allocate memory here
		nbytes = fs.tellg();
		nbytes -= 1;
		text = new char[nbytes];
		fs.seekg(0, std::ios::beg);
		// read binary file here
		fs.read(text, nbytes);

		std::cout << "\n" << nbytes + 1 << " bytes copied from binary file "
			<< file << " into memory (null byte included)\n";
		encoded = true;

		// decode using key
		code(key);
		std::cout << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}

}