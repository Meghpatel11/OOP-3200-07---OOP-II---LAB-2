#include <iostream>

#include "workticket.h"
// Name : - Nirmal Patel & Megh Patel
// Group 2.
// SUbject: - OOPs lab2.
int main()
{

	WorkTicket ticket_arr[3];
	bool tryNow = true;

	int input_ticket_num = 0;
	std::string input_client_id = "";
	int input_date = 01;
	int input_month = 01;
	int input_year = 2000;
	std::string input_issue = "";

	WorkTicket ticket1, ticket4;

	
	// Parameter raised constructor called
	
	WorkTicket ticket2(100, 12, 10, 2002, "aaa", "issue");

	// Copy constructor
	WorkTicket ticket3(ticket2);

	// Input from >>(istream)operator
	
	std::cout << "\nInput using >>(istream) operator";
	std::cin >> ticket1;

	// Output using conversion operator
	
	std::cout << "\nOutput using conversion operator";
	std::cout << ticket2.showmsg();

	//output using << operator
	
	std::cout << "\nOutput using <<(ostream) operator";
	std::cout << ticket3;


	//using ==operator overloading
	
	std::cout << "\nusing equality(==) operator overloading";
	
	if (ticket2 == ticket3)
	{
		std::cout << "\nObjects are equal";
	}
	else
	{
		std::cout << "\nObjects are different";
	}

	// Assigning =operator overloading
	ticket4 = ticket1;
	
}
