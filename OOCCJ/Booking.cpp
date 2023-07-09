#include "Billing.h"
#include "Booking.h"

#include <iostream>
#include <fstream>

using std::cin, std::cout, std::endl;


Booking::Booking()
{
	std::ifstream booking("Tickets.txt", std::ios::in);

	Ticket t;

	if (booking.is_open())
	{
		while (booking >> t)
		{
			bookedSeats[t.timeSlot][t.movieID][t.rowNo][t.seatNo] = 1;
			tickets.push_back(t);
		}
		booking.close();
	}
}

void Booking::BookTicket(int slot, int mno)
{
	Ticket t;
	t.SetDetails(slot, mno);
	ReserveSeat(t);
}

int Booking::CheckSeat(int timeSlot, int mId, int row, int seat)
{
	return bookedSeats[timeSlot][mId][row][seat];
}

void Booking::ReserveSeat(const Ticket& t)
{
	std::ofstream booking("Tickets.txt", std::ios::app);

	if (CheckSeat(t.timeSlot, t.movieID, t.rowNo, t.seatNo) == 0)
	{
		booking << t;
		tickets.push_back(t);
		bookedSeats[t.timeSlot][t.movieID][t.rowNo][t.seatNo] = 1;
		Billing::PrintReceipt(t);
	}
	else
	{
		cout << "SEAT IS RESERVED. SELECT ANOTHER SEAT" << endl;
	}
}

void Booking::RemoveTicketFromFile(int tNum)
{
	std::ifstream booking("Tickets.txt", std::ios::in);
	std::ofstream temp("temp.txt", std::ios::out);

	Ticket curr;
	if (booking.is_open())
	{
		while (booking >> curr)
		{
			if (!(curr.ticketNum == tNum))
			{
				temp << curr;
			}
		}
	}
	booking.close();
	temp.close();

	remove("Tickets.txt");
	int r = rename("temp.txt", "Tickets.txt");

	cout << endl;
	cout << "TICKET CANCELLED SUCCESSFULLY" << endl << endl;
}

void Booking::ReloadTicketsFromFile()
{
	std::ifstream booking("Tickets.txt", std::ios::in);
	Ticket t;
	tickets.clear();

	if (booking.is_open())
	{
		while (booking >> t)
		{
			tickets.push_back(t);
		}
		booking.close();
	}
}

void Booking::CancelTicket(int tNum)
{
	Ticket t;
	bool flag = false;

	for (int i = 0; i < tickets.size(); i++)
	{
		if (tickets[i].ticketNum == tNum)
		{
			t = tickets[i];
			flag = true;
		}
	}

	if (flag)
	{
		if (CheckSeat(t.timeSlot, t.movieID, t.rowNo, t.seatNo) == 1)
		{
			bookedSeats[t.timeSlot][t.movieID][t.rowNo][t.seatNo] = 0;
			RemoveTicketFromFile(tNum);
			ReloadTicketsFromFile();
		}
	}
	else
	{
		cout << endl;
		cout << "TICKET DOESN'T EXIST IN OUR DATABASE. DID YOU ENTER THE "
			"CORRECT TICKET NUMBER?"
			<< endl
			<< endl;
	}
}

void Booking::DisplayAvailableSeats(int timeSlot, int mId)
{
	int skip = 0;

	cout << endl << endl;
	cout << "--------Displaying Seats--------" << endl;
	for (int i = 1; i <= 10; i++)
	{
		if (i <= 3 && skip % 2 == 0)
		{
			cout << "[Platinum]" << endl;
			skip++;
		}
		else if (i > 3 && i <= 6 && skip % 2 == 1)
		{
			cout << endl;
			cout << "[Gold]" << endl;
			skip++;
		}
		else if (i > 6 && i <= 10 && skip % 2 == 0)
		{
			cout << endl;
			cout << "[Silver]" << endl;
			skip++;
		}
		char c = i + 64;
		cout << c << ": ";

		for (int j = 1; j <= 10; j++)
		{
			if (CheckSeat(timeSlot, mId, i, j))
			{
				cout << "\t[X]";
			}
			else
			{
				cout << "\t[" << j << "]";
			}
		}
		cout << endl;
	}

	cout << endl;
	cout << "\t\t\t-----------------------------------" << endl;
	cout << "\t\t\t     All Eyes This Way Please!" << endl;
	cout << endl << endl;
	cout << "X: Seat Taken" << endl << endl << endl;

	cout << "--------Price Details--------" << endl;
	cout << "Platinum: \tRs. 750" << endl;
	cout << "Gold: \t\tRs. 500" << endl;
	cout << "Silver: \tRs. 250" << endl << endl;
}
