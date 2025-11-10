#include "Status.h"
#include "Date.h"
#include <string.h>
#pragma warning (disable : 4996)

#include <iostream>
using namespace std;


Status::Status(string text) : publicationDate(), publicationTime()//ctor
{
	this->text = text;
}

const char* Status::getText() const//returns the text of the status
{
	return text.c_str();
}


const Date& Status::getDate() const//returns the publication date of the status
{
	return publicationDate;
}

const Clock& Status::getTime() const//returns the publication time of the status
{
	return publicationTime;
}


void Status::showStatus() const//prints the status details.
{
	cout << "Status details: \n";
	cout << "text: " << getText() << endl;
	cout << "\npublication date: ";
	publicationDate.showDate();
	cout << "\npublication time: ";
	publicationTime.showTime();
	cout << "________________" << endl;
}

bool Status::operator==(const Status& other) const	// == operator compares two statuses by their text value returns true if equal else returns false
{
	if (text.compare(other.text.c_str()) == 0)//compare the char * of both strings to see if its the same or not
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

bool Status::operator!=(const Status& other) const	// != operator compares two statuses by their text value returns true if not equal else returns false(uses == operator)
{
	bool equal = (*this == other);
	return(!equal);
}