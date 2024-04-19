#include "Member.h"

#include <iostream>

using std::cin, std::cout, std::endl;

void Member::Register()
{
	cout << endl;
	cout << "Registering for Membership:" << endl;

	Customer::SetDetails();
	accountNumber = std::to_string((rand() % 9999) + 10000);
	SetPassword();
}

void Member::SetPassword()
{
	std::string temp;
	int flag = 1;

	while (flag)
	{
		cout << "Enter your password: ";
		cin >> password;
		cout << "Reenter your password: ";
		cin >> temp;
		if (temp != password)
		{
			cout << "Password does not match" << endl;
			flag = 1;
		}
		else
		{
			flag = 0;
		}
	}
}

std::istream& operator>>(std::istream& file, Member& m)
{
	std::string temp;
	getline(file, m.accountNumber);
	getline(file, m.name);
	getline(file, m.email);
	getline(file, m.phone);
	getline(file, m.password);
	getline(file, temp);

	return file;
}

std::ostream& operator<<(std::ostream& file, const Member& m)
{
	file << m.accountNumber << endl;
	file << m.name << endl;
	file << m.email << endl;
	file << m.phone << endl;
	file << m.password << endl;
	file << "----------" << endl;

	return file;
}
