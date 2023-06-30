#pragma once

#include "Customer.h"

#include <string>

class Member : Customer
{
private:
	std::string accountNumber, password;

private:
	void SetPassword();

public:
	void Register();

	friend std::istream& operator>>(std::istream& file, Member& m);
	friend std::ostream& operator<<(std::ostream& file, const Member& m);
	friend class MemberDatabase;
};