#pragma once

#include "Member.h"

#include <vector>

class MemberDatabase
{
private:
	std::vector<Member> members;

public:
	MemberDatabase();
	void SaveRecord(Member m);
	bool Login(std::string name);
	bool CheckPassword(Member m, std::string password);
	void DisplayMemberInformation();
};
