#include "statusObject.h"
#include "Date.h"
#include <string.h>
#pragma warning (disable : 4996)

#include <iostream>
using namespace std;


StatusObject::StatusObject(string text) : publicationDate(), publicationTime()//ctor
{
	this->text = text;
}



StatusObject::StatusObject(string text, Date publicationDate, Clock publicationTime)
{
	this->text = text;
	this->publicationDate.setDay(publicationDate.getDay());
	this->publicationDate.setMonth(publicationDate.getMonth());
	this->publicationDate.setYear(publicationDate.getYear());

	this->publicationTime.setHours(publicationTime.getHours());
	this->publicationTime.setMinutes(publicationTime.getMinutes());
	this->publicationTime.setSeconds(publicationTime.getSeconds());

}



const char* StatusObject::getText() const//returns the text of the status
{
	return text.c_str();
}

const Date& StatusObject::getDate() const//returns the publication date of the status
{
	return publicationDate;
}

const Clock& StatusObject::getTime() const//returns the publication time of the status
{
	return publicationTime;
}

StatusObject::~StatusObject()
{
	//dtor just for polymorfism
}