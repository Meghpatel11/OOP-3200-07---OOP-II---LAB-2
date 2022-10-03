#include "workticket.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>

// constructure
WorkTicket::WorkTicket(int ticket_number, int date, int month, int year, std::string client_id, std::string issue)
{
	m_ticket_number = ticket_number;
	m_client_id = std::move(client_id);
	m_date = date;
	m_month = month;
	m_year = year;
	m_issue = std::move(issue);
}

// deconstructure
WorkTicket::~WorkTicket()
= default;

// getters
int WorkTicket::GetTicketNumber()
{
	return m_ticket_number;
}

int WorkTicket::GetDate()
{
	return m_date;
}
int WorkTicket::GetMonth()
{
	return m_month;
}
int WorkTicket::GetYear()
{
	return m_year;
}

std::string WorkTicket::GetClientId()
{
	return m_client_id;
}

std::string WorkTicket::GetIssue()
{
	return m_issue;
}


// method to display results
std::string  WorkTicket::ShowWorkTicket()
{
	std::stringstream ss;
	//ss << "(" << point.GetTicketNumber() << ", " << point.GetClientId() << ", " << point.GetIssue() << ", " << point.GetDate()<<", " << point.GetMonth() << ", " << point.GetYear() <<  ")";
	std::cout << '\n';
	std::cout << std::setw(28) << std::left << "Work Ticket Number: " << std::setw(15) << std::right << GetTicketNumber() << '\n';
	std::cout << std::setw(28) << std::left << "Work Client ID: " << std::setw(15) << std::right << GetClientId() << '\n';
	std::string date = std::to_string(GetDate()) + "/" + std::to_string(GetMonth()) + "/" + std::to_string(GetYear());
	std::cout << std::setw(28) << std::left << "Work Ticket date (dd/mm/yyyy): " << std::setw(12) << std::right << date << '\n';
	std::cout << std::setw(28) << std::left << "Issue: " << std::setw(15) << std::right << GetIssue() << std::endl;

	return ss.str();


}

// validators to check user inputs
int WorkTicket::valid_ticket(int m_ticket_number)
{
	if ((m_ticket_number <= 0))
	{
		throw std::out_of_range("Work Ticket must be whole positive number");
	}
	return m_ticket_number;

}
//  validators to check valid year.
int WorkTicket::ValidYear(int m_year)
{
	if ((m_year < 2000) || (m_year > 2099))
	{
		throw std::out_of_range("Year must be in between 2000 and 2099");  //throwing the out of range exception if the user entered the input out of range
	}
	return m_year;
}

//  validators to check valid day.

int WorkTicket::ValidDay(int m_day)
{
	if ((m_day <= 0) || (m_day > 31))
	{
		throw std::out_of_range("Date must be in between 1 to 31");
	}
	return m_day;
}

//validators to check validMonth.
int WorkTicket::ValidMonth(int m_month)
{
	if ((m_month <= 0) || (m_month > 12))
	{
		throw std::out_of_range("Month must be in between 1 to 12");  //throwing the out of range exception if the user entered the input out of range
	}
	return m_month;
}

bool WorkTicket::ValidClientId(std::string m_clientId)
{
	try
	{
		if (std::stoi(m_clientId))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	catch (std::exception& ex)
	{

	}
}

bool WorkTicket::ValidIssue(std::string m_issue)
{

	try
	{
		if (std::stoi(m_issue))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	catch (std::exception& ex)
	{
	}
}


// Setters for variables
void WorkTicket::SetTicketNumber(int ticket_num)
{
	m_ticket_number = ticket_num;
}
void WorkTicket::SetDate(int date)
{
	m_date = date;
}
void WorkTicket::SetMonth(int date)
{
	m_month = date;
}
void WorkTicket::SetYear(int date)
{
	m_year = date;
}

void WorkTicket::SetClientId(std::string client_id)
{
	m_client_id = std::move(client_id);
}

void WorkTicket::SetIssue(std::string issue)
{
	m_issue = std::move(issue);
}

// set the properties to new objects
void WorkTicket::SetWorkTicket(int ticket_num, int date, int month, int year, std::string client_id, std::string issue)
{
	m_ticket_number = ticket_num;
	m_date = date;
	m_month = month;
	m_year = year;
	m_client_id = std::move(client_id);
	m_issue = std::move(issue);
}

WorkTicket::WorkTicket(const WorkTicket& ticket)
{
	std::cout << "Copy constructor called." << std::endl;
	m_ticket_number = ticket.m_ticket_number;
	m_client_id = std::move(ticket.m_client_id);
	m_date = ticket.m_date;
	m_month = ticket.m_month;
	m_year = ticket.m_year;
	m_issue = std::move(ticket.m_issue);
}
void WorkTicket::operator=(WorkTicket& obj1)
{
	m_ticket_number = obj1.m_ticket_number;
	m_client_id = obj1.m_client_id;
	m_date = obj1.m_date;
	m_month = obj1.m_month;
	m_year = obj1.m_year;
	m_issue = obj1.m_issue;

	std::cout << "\n\nA object was ASSIGNED.\n";
}

bool operator==(WorkTicket& obj1, WorkTicket& obj2)
{
	return (obj1.GetTicketNumber() == obj2.GetTicketNumber() &&
		obj1.GetClientId() == obj2.GetClientId() &&
		obj1.GetDate() == obj2.GetDate() &&
		obj1.GetMonth() == obj2.GetMonth() &&
		obj1.GetYear() == obj2.GetYear() &&
		obj1.GetIssue() == obj2.GetIssue());
}

std::istream& operator>>(std::istream& input, WorkTicket& obj1)
{
	bool tryAgain = true;
	try
	{
		std::cout << "\nEnter Ticket No. : ";
		input >> obj1.m_ticket_number;
		obj1.valid_ticket(obj1.m_ticket_number);

		std::cout << "Enter Client ID : ";
		input >> obj1.m_client_id;
		tryAgain = obj1.ValidClientId(obj1.m_client_id);
		if (!obj1.ValidClientId(obj1.m_client_id))
		{
			throw std::exception("Must enter at least 1 Character");
		}

		
		std::cout << "Enter Day: ";
		//input the date.
		input >> obj1.m_date;
		obj1.ValidDay(obj1.m_date);
		std::cout << "Enter Month: ";
		//input the month. 
		input >> obj1.m_month;
		obj1.ValidMonth(obj1.m_month);
		
		std::cout << "Enter Year: ";
		//input year
		input >> obj1.m_year;
		obj1.ValidYear(obj1.m_year);

		std::cout << "\nEnter Issue : ";
		//input issue
		input >> obj1.m_issue;
		tryAgain = obj1.ValidIssue(obj1.m_issue);
		
		if (!obj1.ValidIssue(obj1.m_issue))
		{
			throw std::exception("Must enter at least 1 Character");
		}

		return input;
	}
	//Exception error
	catch (std::exception& ex)
	{
		std::cerr << ex.what() << " \nEnding the program..." << std::endl
			<< "\n\nPlease Try Again";
	}
}

std::ostream& operator<<(std::ostream& output, WorkTicket& obj1)
{
	std::string date = std::to_string(obj1.m_date) + "/" + std::to_string(obj1.m_month) + "/" + std::to_string(obj1.m_year);
	output << '\n'
		<< std::setw(28) << std::left << "Work Ticket Number: " << std::setw(15) << std::right << obj1.m_ticket_number << '\n'
		<< std::setw(28) << std::left << "Work Client Id: " << std::setw(15) << std::right << obj1.m_client_id << '\n'

		<< std::setw(28) << std::left << "Work Ticket date (dd/mm/yyyy): " << std::setw(12) << std::right << date << '\n'
		<< std::setw(28) << std::left << "Issue: " << std::setw(15) << std::right << obj1.m_issue;

	return output;
}

std::string WorkTicket::showmsg()
	{
		std::string date = std::to_string(m_date) + "/" + std::to_string(m_month) + "/" + std::to_string(m_year);
		std::string message = "\nWork Ticket # " + std::to_string(GetTicketNumber()) + " - " + GetClientId() + "(" + date + "): " + GetIssue() + "\n";
		return message;
	}
