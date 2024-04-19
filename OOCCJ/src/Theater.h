#pragma once

#include "Movie.h"

#include <vector>
#include <string>

class Theater
{
private:
	int movieNum;
	std::string name;
	std::string location;
	int timeSlot[6] = { 9, 12, 15, 18, 21, 0 };
	std::vector<Movie> movies;

public:
	Theater();
	int DisplayMovies();
	void DisplayMovieDetails(int id);
	int DisplayTimeSlots();
	Movie GetMovie(int id);
	int GetTimeSlot(int time) { return timeSlot[time - 1]; }
	void AddMovie();
	void DeleteMovie(std::string name);

	friend class Manager;
};
