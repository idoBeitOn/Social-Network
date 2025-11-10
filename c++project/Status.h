#ifndef _STATUS_H
#define _STATUS_H

#include "Date.h"
#include "Clock.h"
#include <iostream>


class Status
{
	std::string text;
	Date publicationDate;
	Clock publicationTime;

public:

	const char* getText() const; //get functions
	const Date& getDate() const;
	const Clock& getTime() const;

	void showStatus()const;//prints status details

	Status(std::string text);//status ctor
	bool operator==(const Status& other) const;// == operator compares two statuses by their text value returns true if equal else returns false
	bool operator!=(const Status& other) const;// != operator compares two statuses by their text value returns true if not equal else returns false(uses == operator)

};

#endif // !_STATUS_H
