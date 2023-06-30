#pragma once

#include <iostream>

class Movie
{
private:
	int id;
	std::string name;
	int duration;
	float rating;

private:
	void SetDetails();

	friend std::istream& operator>>(std::istream& file, Movie& m);
	friend std::ostream& operator<<(std::ostream& file, Movie& m);
	friend class Theater;
	friend class Billing;
};
