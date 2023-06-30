#pragma once

#include "Member.h"

#include <vector>

class MemberDatabase
{
private:
	std::vector<Member> members;

public:
	MemberDatabase();
	void SaveRecord(const Member& m);
	bool Login(std::string name);
	bool CheckPassword(const Member& m, std::string password) const;
	void DisplayMemberInformation();
};
