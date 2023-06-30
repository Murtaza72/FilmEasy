#pragma once

#include "Ticket.h"

#include <vector>

class Booking
{
private:
	int bookedSeats[5 + 1][20 + 1][10 + 1][10 + 1] = { 0 };
	std::vector<Ticket> tickets;

private:
	int CheckSeat(int timeSlot, int mId, int row, int seat);
	void ReserveSeat(Ticket t);
	void RemoveTicketFromFile(int tNum);

public:
	Booking();
	void BookTicket(int slot, int mno);
	void CancelTicket(int tNum);
	void DisplayAvailableSeats(int timeSlot, int mId);
};
