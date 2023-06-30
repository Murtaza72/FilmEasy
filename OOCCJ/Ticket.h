#pragma once

#include <string>

class Ticket
{
private:
	int ticketNum;
	int timeSlot;
	int movieID;
	int seatNo, rowNo;
	int price;
	std::string type;

private:
	int SetRow();
	void SetSeat();
	void SetType();
	void SetPrice();
	void SetTicketNum();

public:
	void SetDetails(int slot, int mno);

	friend std::istream& operator>>(std::istream& file, Ticket& t);
	friend std::ostream& operator<<(std::ostream& file, Ticket& t);
	friend class Booking;
	friend class Billing;
};
