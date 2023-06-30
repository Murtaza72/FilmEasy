#include "Movie.h"

#include <iostream>
#include <string>

using std::cin, std::cout, std::endl;

void Movie::SetDetails()
{
	cout << "Movie Name: ";
	cin >> name;
	cout << "Duration: ";
	cin >> duration;
	cout << "Rating: ";
	cin >> rating;
}

std::istream& operator>>(std::istream& file, Movie& m)
{
	std::string temp;

	try {
		getline(file, m.name);

		getline(file, temp);
		m.duration = stoi(temp);

		getline(file, temp);
		m.rating = stof(temp);

		getline(file, temp);
	}
	catch (...) {
		// cout << "Exception(in Movie)" << endl;
	}

	return file;
}

std::ostream& operator<<(std::ostream& file, const Movie& m)
{
	file << m.name << endl;
	file << m.duration << endl;
	file << m.rating << endl;
	file << "--------" << endl;

	return file;
}
