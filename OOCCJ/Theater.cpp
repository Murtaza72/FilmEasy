#include "Theater.h"

#include <iostream>
#include <fstream>

using std::cin, std::cout, std::endl;

Theater::Theater()
{
	std::ifstream movieFile("Movies.txt", std::ios::in);

	int i = 0;
	Movie m;
	if (movieFile.is_open())
	{
		while (movieFile.good())
		{
			movieFile >> m;
			m.id = i + 1;
			movies.push_back(m);
			i++;
		}
	}
	movieNum = i - 1;
	movieFile.close();
}

void Theater::AddMovie()
{
	Movie m;
	m.SetDetails();

	std::ofstream movieFile("Movies.txt", std::ios::app);
	movieFile << m;
	movieNum++;
	m.id = movieNum;
	if (movies.size() > 0)
		movies.pop_back();  // some error causes empty record to be pushed
	movies.push_back(m);

	for (int i = 0; i < movieNum; i++)
	{
		cout << "\t[" << i + 1 << "] " << movies[i].name << endl;
	}

	cout << endl;
	cout << "NEW MOVIE ADDED SUCCESSFULLY" << endl;
}

void Theater::DeleteMovie(std::string name)
{
	std::ifstream movieFile("Movies.txt", std::ios::in);
	std::ofstream temp("temp.txt", std::ios::out);

	Movie curr;
	if (movieFile.is_open())
	{
		while (movieFile >> curr)
		{
			if (!(curr.name == name))
			{
				temp << curr;
			}
		}
	}
	movieFile.close();
	temp.close();

	remove("Movies.txt");
	int r = rename("temp.txt", "Movies.txt");

	std::ifstream mFile("Movies.txt", std::ios::in);
	movies.clear();
	int i = 0;
	Movie m;
	if (mFile.is_open())
	{
		while (mFile.good())
		{
			mFile >> m;
			m.id = i + 1;
			movies.push_back(m);
			i++;
		}
	}
	movieNum = i - 1;
	mFile.close();

	cout << endl;
	cout << "MOVIE REMOVED SUCCESSFULLY" << endl << endl;
}

int Theater::DisplayMovies()
{
	int choice;

	cout << endl;
	cout << "Select a Movie" << endl << endl;

	for (int i = 0; i < movieNum; i++)
	{
		cout << "\t[" << i + 1 << "] " << movies[i].name << endl;
	}

	cout << endl;
	cout << "Movie number: ";
	cin >> choice;

	try
	{
		if (choice > 0 && choice <= movieNum)
		{
			return choice;
		}
		throw choice;
	}
	catch (int choice)
	{
		cout << endl;
		cout << "INVALID CHOICE(" << choice << "). ENTER CORRECT MOVIE NUMBER." << endl << endl;
		return -1;
	}
}

void Theater::DisplayMovieDetails(int id)
{
	int index = id - 1;
	if (index >= 0)
	{
		cout << endl;
		cout << "--------Movie Details--------" << endl;
		cout << "Movie Name:\t" << movies[index].name << endl;
		cout << "Duration:\t" << movies[index].duration << " minutes" << endl;
		cout << "Ratings:\t" << movies[index].rating << " / 10" << endl;
	}
}

int Theater::DisplayTimeSlots()
{
	int choice;

	cout << endl;
	cout << "Select a time slot" << endl << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << "\t[" << i + 1 << "] " << timeSlot[i] << ":00 to "
			<< timeSlot[i + 1] << ":00" << endl;
	}

	cout << endl;
	cout << "Slot number: ";
	cin >> choice;
	cout << endl;

	try
	{
		if (choice > 0 && choice <= 5)
		{
			return choice;
		}
		throw choice;
	}
	catch (int choice)
	{
		cout << endl;
		cout << "INVALID CHOICE(" << choice << "). ENTER CORRECT SLOT NUMBER" << endl << endl;
		return -1;
	}
}

Movie Theater::GetMovie(int id) { return movies[id - 1]; }
