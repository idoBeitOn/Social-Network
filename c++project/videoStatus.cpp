#include "videoStatus.h"
#include <iostream>
#pragma warning (disable : 4996)
using namespace std;


VideoStatus::VideoStatus(string text, string videoPath) :StatusObject(text)
{
	this->videoPath = videoPath;
}

VideoStatus::VideoStatus(std::string text, std::string videoPath, Date publicationDate, Clock publicationTime) : StatusObject(text, publicationDate, publicationTime)
{
	this->videoPath = videoPath;
}

const char* VideoStatus::getVideoName() const //get functions
{
	return videoPath.c_str();
}

void VideoStatus::showStatus() const
{
	cout << "Status details: \n";
	cout << "Status type: Video" << endl;
	cout << PICTURE_OR_VIDEO_STATUS_DISPLAY_OPTION << endl;
	cout << VIDEO_STATUS_DISPLAY_OPTION << endl;
	cout << "Statuses text: " << getText() << endl;
	cout << "Statuses Video name: " << getVideoName() << endl;
	cout << "\npublication date: ";
	publicationDate.showDate();
	cout << "\npublication time: ";
	publicationTime.showTime();
	cout << "________________" << endl;
}

bool VideoStatus::operator==(const StatusObject& other) const// == operator compares two statuses by their text value returns true if equal else returns false
{
	const VideoStatus* temp = dynamic_cast<const VideoStatus*>(&other);
	if (temp == nullptr)
	{
		return (false);
	}
	else
	{
		if ((text.compare(temp->text.c_str()) == 0) && (videoPath.compare(temp->videoPath.c_str()) == 0))//compare the char * of both strings to see if its the same or not
		{
			return (true);
		}
		else
		{
			return (false);
		}
	}
}

bool VideoStatus::operator!=(const StatusObject& other) const
{
	bool equal = (*this == other);
	return(!equal);
}