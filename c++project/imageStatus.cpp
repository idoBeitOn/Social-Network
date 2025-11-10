#include "imageStatus.h"
#include <iostream>
#pragma warning (disable : 4996)
using namespace std;


ImageStatus::ImageStatus(string text, string imagePath) :StatusObject(text)
{
	this->imagePath = imagePath;
}
ImageStatus::ImageStatus(std::string text, std::string imagePath, Date publicationDate, Clock publicationTime) : StatusObject(text, publicationDate, publicationTime)
{
	this->imagePath = imagePath;
}
const char* ImageStatus::getImageName() const //get functions
{
	return imagePath.c_str();
}

void ImageStatus::showStatus() const
{
	cout << "Status details: \n";
	cout << "Status type: Image" << endl;
	cout << PICTURE_OR_VIDEO_STATUS_DISPLAY_OPTION << endl;
	cout << TEXT_STATUS_OR_IMAGE_STATUS_DISPLAY_OPTION << endl;
	cout << "Statuses text: " << getText() << endl;
	cout << "Statuses Image name: " << getImageName() << endl;
	cout << "\npublication date: ";
	publicationDate.showDate();
	cout << "\npublication time: ";
	publicationTime.showTime();
	cout << "________________" << endl;
}

bool ImageStatus::operator==(const StatusObject& other) const	// == operator compares two statuses by their text value returns true if equal else returns false
{
	const ImageStatus* temp = dynamic_cast<const ImageStatus*>(&other);
	if (temp == nullptr)
	{
		return (false);
	}
	else
	{
		if ((text.compare(temp->text.c_str()) == 0) && (imagePath.compare(temp->imagePath.c_str()) == 0))//compare the char * of both strings to see if its the same or not
		{
			return (true);
		}
		else
		{
			return (false);
		}
	}
}

bool ImageStatus::operator!=(const StatusObject& other) const
{
	bool equal = (*this == other);
	return(!equal);
}