#include "Clock.h"
#include <string>
#include <stdio.h>
#include <ctime>
#pragma warning (disable : 4996)
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const Clock& time)
{
	os << time.getHours() << " " << time.getMinutes() << " " << time.getSeconds();
	return os;
}
Clock::Clock()
{
	// current date/time based on current system
	time_t now = time(0);
	tm* ltm = localtime(&now);

	hours = ltm->tm_hour;
	minutes = ltm->tm_min;
	seconds = ltm->tm_sec;
}


const short Clock::getMinutes() const //returns the minutes
{
	return minutes;
}

const short Clock::getHours() const//returns the hours
{
	return hours;
}


const short Clock::getSeconds() const// returns the seconds
{
	return seconds;
}


void Clock::showTime() const// prints the time
{
	//cout << hours << ":" << minutes << ":" << seconds << endl;
	if (hours < 10)
	{
		cout << "0" << hours << ":";
	}
	else
	{
		cout << hours << ":";
	}
	if (minutes < 10)
	{
		cout << "0" << minutes << ":";
	}
	else
	{
		cout << minutes << ":";
	}
	if (seconds < 10)
	{
		cout << "0" << seconds << endl;
	}
	else
	{
		cout << seconds << endl;
	}



}






void Clock::setSeconds(short seconds)
{
	this->seconds = seconds;
}
void Clock::setHours(short hours)
{
	this->hours = hours;
}
void Clock::setMinutes(short minutes)
{
	this->minutes = minutes;
}



