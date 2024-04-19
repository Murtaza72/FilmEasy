#include "Customer.h"

#include <iostream>

using std::cin, std::cout, std::endl;

void Customer::SetDetails()
{
	SetName();
	SetPhone();
	SetEmail();
}

void Customer::SetName()
{
	cout << "Enter your name: ";
	cin >> name;
}

void Customer::SetPhone()
{
	cout << "Enter your phone number: ";
	cin >> phone;

	while (phone.length() != 10)
	{
		cout << endl;
		cout << "Phone number should have 10 digits" << endl;
		cout << "Enter a valid phone number: ";
		cin >> phone;
	}
}

void Customer::SetEmail()
{
	int validEmail = 0;

	cout << "Enter your email address: ";
	cin >> email;

	while (!validEmail)
	{
		for (int i = 0; i < email.length(); ++i)
		{
			if (email.at(i) == '@')
			{
				validEmail = 1;
				return;
			}
		}

		cout << "INVALID EMAIL ADDRESS" << endl;
		cout << "Enter a valid email address: ";
		cin >> email;
	}
}
