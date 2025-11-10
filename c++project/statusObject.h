#ifndef _STATUS_OBJECT_H
#define _STATUS_OBJECT_H

#include "Date.h"
#include "Clock.h"
#include <iostream>
//#include "facebook.h"
constexpr char TEXT_STATUS_DISPLAY_OPTION[] = "this status type can only be displayed in black and white";
constexpr char PICTURE_OR_VIDEO_STATUS_DISPLAY_OPTION[] = "this status type can be displayed in black and white or in color";
constexpr char TEXT_STATUS_OR_IMAGE_STATUS_DISPLAY_OPTION[] = "this status type can be displayed using a simple program";
constexpr char VIDEO_STATUS_DISPLAY_OPTION[] = "this status type can be displayed using a video player";
constexpr char TEXT_STATUS = 'T';
constexpr char IMAGE_STATUS = 'I';
constexpr char VIDEO_STATUS = 'V';


class StatusObject
{
protected:

	std::string text;
	Date publicationDate;
	Clock publicationTime;
	StatusObject(std::string text, Date publicationDate, Clock publicationTime);

public:
	StatusObject(std::string text);//status ctor
	const char* getText() const; //get functions
	const Date& getDate() const;
	const Clock& getTime() const;
	virtual ~StatusObject();
	virtual void showStatus() const = 0;
	virtual bool operator==(const StatusObject& other) const = 0;// == operator compares two statuses by their text value returns true if equal else returns false
	virtual bool operator!=(const StatusObject& other) const = 0;// != operator compares two statuses by their text value returns true if not equal else returns false(uses == operator)
	friend std::ostream& operator<<(std::ostream& os, const StatusObject& status)
	{

		os << status.getText() << "\n "; //print the statuses of the member
		os << status.getDate() << "\n ";//print status date
		os << status.getTime() << "\n";
		return (os);
	}
};




#endif // !_STATUS_OBJECT_H




