#ifndef _CLOCK_H
#define _CLOCK_H

#include <iostream>
#include <fstream>
#include <ostream>
#include <istream>

//This class manages the time, saves the real time which the statuses are created.
class Clock
{
	short minutes;
	short hours;
	short seconds;
public:

	Clock();
	const short getMinutes() const; // get functions
	const short getHours() const;
	const short getSeconds() const;
	void setSeconds(short seconds);
	void setHours(short hours);
	void setMinutes(short minutes);

	friend std::ostream& operator<<(std::ostream& os, const Clock& time);
	void showTime() const;//prints the time.
};

#endif // !_CLOCK_H



