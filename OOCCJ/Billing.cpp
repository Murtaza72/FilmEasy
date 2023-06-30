#include "Billing.h"
#include "Theater.h"

using std::cin, std::cout, std::endl;

void Billing::PrintReceipt(Ticket t)
{
	Theater theater;
	Movie m = theater.GetMovie(t.movieID);
	int time = theater.GetTimeSlot(t.timeSlot);
	char row = t.rowNo + 64;

	system("cls");
	cout << "======================================================\n"
		<< "                       RECEIPT                        \n"
		<< "======================================================\n";

	cout << "Ticket Number: " << t.ticketNum << endl;
	cout << "Movie Name: " << m.name << "\t\tTime: " << time << ":00" << endl;
	cout << "Duration: " << m.duration << " minutes" << endl;
	cout << "Seat Type: " << t.type << endl;
	cout << "Seat: " << row << t.seatNo << endl;
	cout << "Price: Rs. " << t.price << endl;
	cout << "------------------------------------------------------" << endl
		<< endl;
}
