#include "Billing.h"
#include "Booking.h"
#include "Customer.h"
#include "Manager.h"
#include "Member.h"
#include "MemberDatabase.h"
#include "Movie.h"
#include "Theater.h"
#include "Ticket.h"

using namespace std;

// helper functions

void Title()
{
	system("cls");
	const int WIDTH1 = 90;
	const int WIDTH2 = 20;
	const string heading = "MOVIE TICKET RESERVATION SYSTEM";

	cout << endl;

	for (int i = 0; i < WIDTH2; i++) {
		cout << ' ';
	}
	for (int i = 0; i < WIDTH1; i++) {
		cout << '*';
	}

	cout << endl << endl;
	for (int i = 0; i < 6; i++) {
		cout << "\t";
	}
	cout << heading;
	cout << endl << endl;

	for (int i = 0; i < WIDTH2; i++) {
		cout << ' ';
	}
	for (int i = 0; i < WIDTH1; i++) {
		cout << '*';
	}
	cout << endl << endl;
}

// global variables

Theater theater;
Booking booking;
MemberDatabase db;
Billing billing;
Manager manager;

void TicketMenu()
{
	int slot, mno, ch = 0;

	while (ch != 3) {
		Title();
		cout << endl;
		cout << "[1] Book a Ticket" << endl;
		cout << "[2] Cancel Ticket" << endl;
		cout << "[3] Previous Menu" << endl << endl;
		cout << "Choice: ";
		cin >> ch;

		switch (ch) {
		case 1:
		{
			system("cls");

			mno = theater.DisplayMovies();
			if (mno != -1) {
				system("cls");
				slot = theater.DisplayTimeSlots();
				if (slot != -1) {
					system("cls");
					theater.DisplayMovieDetails(mno);
					booking.DisplayAvailableSeats(slot, mno);
					booking.BookTicket(slot, mno);
				}
			}
			system("pause");
			break;
		}

		case 2:
		{
			system("cls");

			int tNum;
			cout << "Enter Ticket Number: ";
			cin >> tNum;

			booking.CancelTicket(tNum);

			system("pause");
			break;
		}

		case 3:
		{
			break;
		}

		default:
			cout << "INVALID CHOICE" << endl << endl;
			system("pause");
			break;
		}
	}
}

void CustomerMenu()
{
	int choice = 0;
	string name;

	while (choice != 4) {
		Title();

		cout << endl;
		cout << "[1] Login (for Members)" << endl;
		cout << "[2] Signup for Membership" << endl;
		cout << "[3] Continue as guest" << endl;
		cout << "[4] Previous Menu" << endl << endl;
		cout << "Choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
		{
			cout << endl;
			cout << "Enter the details of the Member:" << endl;
			cout << "Name: ";
			cin >> name;
			bool logged = db.Login(name);

			if (logged) {
				TicketMenu();
			}

			system("pause");
			break;
		}

		case 2:
		{
			Member m;
			m.Register();
			db.SaveRecord(m);

			TicketMenu();
			break;
		}

		case 3:
		{
			Customer c;
			c.SetDetails();

			TicketMenu();
			break;
		}

		case 4:
		{
			break;
		}

		default:
			cout << "INVALID CHOICE" << endl << endl;
			system("pause");
			break;
		}
	}
}

void ManagerMenu()
{
	int choice = 0;
	string name;
	Manager m;

	while (choice != 4) {
		Title();

		cout << endl;
		cout << "[1] Add Movie" << endl;
		cout << "[2] Delete Movie" << endl;
		cout << "[3] Display Member Information" << endl;
		cout << "[4] Previous Menu" << endl << endl;
		cout << "Choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
		{
			theater.AddMovie();
			system("pause");
			break;
		}

		case 2:
		{
			string name;
			cout << "Movie Name: ";
			cin >> name;
			theater.DeleteMovie(name);
			system("pause");
			break;
		}

		case 3:
		{
			db.DisplayMemberInformation();
			system("pause");
			break;
		}

		case 4:
		{
			break;
		}

		default:
			cout << "INVALID CHOICE" << endl << endl;
			system("pause");
			break;
		}
	}
}

int main()
{
	srand(time(0));  // generates random values

	int choice = 0;

	while (choice != 3) {
		Title();

		cout << endl;
		cout << "[1] Customer Menu" << endl;
		cout << "[2] Manager Menu" << endl;
		cout << "[3] Exit" << endl << endl;
		cout << "Choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
		{
			CustomerMenu();
			break;
		}

		case 2:
		{
			if (manager.Login())
				ManagerMenu();

			break;
		}

		case 3:
		{
			cout << "Exiting" << endl;
			break;
		}

		default:
			cout << "INVALID CHOICE" << endl;
			system("pause");
			break;
		}
	}
	return 0;
}
