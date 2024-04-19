#pragma once

#include <string>

class Customer
{
protected:
	std::string name, phone, email;
	int numTicket;

private:
	void SetName();
	void SetPhone();
	void SetEmail();

public:
	void SetDetails();
};
