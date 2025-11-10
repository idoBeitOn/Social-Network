#ifndef _DATE_H
#define _DATE_H

#include <iostream>
#include <fstream>
#include <ostream>
#include <istream>
class Date
{
	short day;
	short month;
	short year;
public:

	Date(short day, short month, short year);//ctor
	Date();//ctor

	void showDate()const;//prints the date//prints the date

	void setDay(short day);//set functions
	void setMonth(short month);
	void setYear(short year);

	short getDay() const;
	short getMonth() const;
	short getYear() const;
	friend std::ostream& operator<<(std::ostream& os, const Date& birthDate);
};

#endif


