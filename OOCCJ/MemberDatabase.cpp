#include "MemberDatabase.h"

#include <iostream>
#include <fstream>

using std::cin, std::cout, std::endl;

MemberDatabase::MemberDatabase()
{
	Member member;
	std::ifstream memberFile("Members.txt", std::ios::in);

	if (memberFile.is_open()) {
		while (memberFile >> member) {
			members.push_back(member);
		}
	}

	memberFile.close();
}

void MemberDatabase::SaveRecord(Member m)
{
	std::ofstream memberFile("Members.txt", std::ios::app);

	if (memberFile.is_open()) {
		memberFile << m;
		members.push_back(m);
		cout << "Record saved successfully" << endl;
	}

	memberFile.close();
}

bool MemberDatabase::CheckPassword(Member m, std::string password)
{
	if (m.password == password) {
		return true;
	}
	return false;
}

bool MemberDatabase::Login(std::string name)
{
	std::string password;
	bool logged = false;
	for (int i = 0; i < members.size(); i++) {
		if (name == members[i].name) {
			Member m = members[i];
			cout << "Password: ";
			cin >> password;
			if (CheckPassword(m, password)) {
				logged = true;
				cout << "Logged In successfully" << endl << endl;
			}
			else {
				cout << "WRONG PASSWORD" << endl << endl;
			}
			break;
		}
	}
	if (!logged) {
		cout << "MEMBER DOESN'T EXIST. SIGNUP FIRST." << endl << endl;
	}
	return logged;
}

void MemberDatabase::DisplayMemberInformation()
{
	cout << "=========================================================" << endl;
	cout << "                   MEMBER INFORMATION                    " << endl;
	cout << "=========================================================" << endl;

	for (int i = 0; i < members.size(); i++) {
		cout << "Account Number : " << members[i].accountNumber << endl;
		cout << "Name           : " << members[i].name << endl;
		cout << "Phone no.      : " << members[i].phone << endl;
		cout << "E-mail         : " << members[i].email << endl;
		cout << "---------------------------------------------------------"
			<< endl;
	}
}
