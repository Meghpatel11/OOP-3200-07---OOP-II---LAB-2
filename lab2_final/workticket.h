#pragma once
#ifndef __WORKTICKET__
#define __WORKTICKET__

#include <string>

class WorkTicket
{
public:

	// Constructor

	WorkTicket(int ticket_number = 0, int date = 112000, int month = 12, int year = 2000, std::string client_id = "", std::string issue = "");

	// Destructor
	~WorkTicket();

	// Getter
	int GetTicketNumber();
	int GetDate();
	int GetMonth();
	int GetYear();
	std::string GetClientId();
	std::string GetIssue();

	std::string showmsg();
	std::string ShowWorkTicket();

	// Setter
	void SetTicketNumber(int ticket_num);
	void SetDate(int date);
	void SetMonth(int date);
	void SetYear(int date);
	void SetClientId(std::string client_id);
	void SetIssue(std::string issue);
	void SetWorkTicket(int ticket_num, int date, int month, int year, std::string client_id, std::string issue);
	WorkTicket(const WorkTicket& ticket);
	bool friend operator==(WorkTicket& obj1, WorkTicket& obj2);
	void operator=(WorkTicket& obj1);
	friend std::istream& operator>> (std::istream& input, WorkTicket& obj1);
	friend std::ostream& operator<< (std::ostream& output, WorkTicket& obj1);


	// validators 
	int valid_ticket(int m_ticket_number);
	int ValidYear(int m_year);
	int ValidDay(int m_day);
	int ValidMonth(int m_month);
	bool ValidClientId(std::string m_clientId);
	bool ValidIssue(std::string m_issue);

	

public:

	// members variables
	int m_ticket_number;
	std::string m_client_id;
	int m_date;
	int m_month;
	int m_year;
	std::string m_issue;

};

#endif
