#include "Date.h"
#include <ctime>
#include <iostream>
using namespace std;

#pragma warning (disable : 4996)


Date::Date(short day, short month, short year)//ctor
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date()//ctor
{
	time_t now = time(0);
	tm* ltm = localtime(&now);

	year = 1900 + ltm->tm_year;
	month = 1 + ltm->tm_mon;
	day = ltm->tm_mday;
}



void Date::showDate()const//prints the date
{
	//cout << day << "/" << month << "/" << year << endl;
	if (day < 10)
	{
		cout << "0" << day << "/";
	}
	else
	{
		cout << day << "/";
	}
	if (month < 10)
	{
		cout << "0" << month << "/";
	}
	else
	{
		cout << month << "/";
	}
	cout << year << endl;
}


void Date::setDay(short day)//set day
{
	this->day = day;
}
void Date::setMonth(short month)//set month
{
	this->month = month;
}

void Date::setYear(short year)//set year
{
	this->year = year;
}



short Date::getDay() const
{
	return day;
}
short Date::getMonth() const
{
	return month;
}
short Date::getYear() const
{
	return year;
}

std::ostream& operator<<(std::ostream& os, const Date& birthDate)
{
	os << birthDate.getDay() << " " << birthDate.getMonth() << " " << birthDate.getYear();
	return os;
}