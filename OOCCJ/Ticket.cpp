#include "Ticket.h"

#include <iostream>

using std::cin, std::cout, std::endl;

void Ticket::SetDetails(int slot, int mno)
{
	SetTicketNum();
	timeSlot = slot;
	movieID = mno;
	SetRow();
	SetSeat();
	SetType();
	SetPrice();
}

int Ticket::SetRow()
{
	char c;
	cout << "Row: ";
	cin >> c;
	int i = c;

	while (i < 'A' || i >(10 + 'A' - 1))  // i > (6 + 65 - 1)
	{
		cout << "Enter the correct row (capital): ";
		cin >> c;
		i = c;
	}

	rowNo = i - 'A' + 1;  // 65 - 65 + 1, 66 - 65 + 1
	return rowNo;
}

void Ticket::SetSeat()
{
	cout << "Seat No: ";
	cin >> seatNo;
	while (seatNo <= 0 || seatNo > 10) {
		cout << "Enter the correct seat no: ";
		cin >> seatNo;
	}
}

void Ticket::SetType()
{
	if (rowNo <= 3) {
		type = "Platinum";
	}
	else if (rowNo > 3 && rowNo <= 6) {
		type = "Gold";
	}
	else if (rowNo > 6 && rowNo <= 10) {
		type = "Silver";
	}
	cout << "Type: " << type << endl << endl;
}

void Ticket::SetPrice()
{
	if (type == "Platinum")
		price = 750;
	else if (type == "Gold")
		price = 500;
	else if (type == "Silver")
		price = 250;
}

void Ticket::SetTicketNum() { ticketNum = rand() % 99 + 100; }

std::istream& operator>>(std::istream& file, Ticket& t)
{
	std::string temp;
	try {
		getline(file, temp);
		t.ticketNum = stoi(temp);

		getline(file, temp);
		t.timeSlot = stoi(temp);

		getline(file, temp);
		t.movieID = stoi(temp);

		getline(file, temp);
		t.rowNo = stoi(temp);

		getline(file, temp);
		t.seatNo = stoi(temp);

		getline(file, temp);
		t.price = stoi(temp);

		getline(file, t.type);
		getline(file, temp);
	}
	catch (std::exception e) {
		//cout << "Exception(in Ticket)" << endl;
	}

	return file;
}

std::ostream& operator<<(std::ostream& file, Ticket& t)
{
	file << t.ticketNum << endl;
	file << t.timeSlot << endl;
	file << t.movieID << endl;
	file << t.rowNo << endl;
	file << t.seatNo << endl;
	file << t.price << endl;
	file << t.type << endl;
	file << "--------" << endl;

	return file;
}
