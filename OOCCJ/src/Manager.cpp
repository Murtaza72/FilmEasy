#include "Manager.h"

#include <iostream>

using std::cin, std::cout, std::endl;

bool Manager::Login()
{
	int chance = 3;
	bool flag = false;

	while (chance > 0)
	{
		cout << "Username: ";
		cin >> name;
		cout << "Password: ";
		cin >> password;

		if (name == "admin" && password == "admin")
		{
			cout << "Welcome to Manager Menu" << endl;
			flag = true;
			break;
		}
		else
		{
			cout << "Invalid username or password" << endl;
		}
		chance--;
	}

	if (!flag)
	{
		cout << "Exceeded maximum attempts. Terminating." << endl;
		exit(0);
	}

	return flag;
}