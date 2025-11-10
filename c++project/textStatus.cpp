#include "textStatus.h"
#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

TextStatus::TextStatus(std::string text) : StatusObject(text)
{

}
TextStatus::TextStatus(std::string text, Date publicationDate, Clock publicationTime) : StatusObject(text, publicationDate, publicationTime)
{

}
void TextStatus::showStatus() const
{
	cout << "Status details: \n";
	cout << "Status type: Text" << endl;
	cout << TEXT_STATUS_DISPLAY_OPTION << endl;
	cout << TEXT_STATUS_OR_IMAGE_STATUS_DISPLAY_OPTION << endl;
	cout << "Statuses text: " << getText() << endl;
	cout << "\npublication date: ";
	publicationDate.showDate();
	cout << "\npublication time: ";
	publicationTime.showTime();
	cout << "________________" << endl;
}

bool TextStatus::operator==(const StatusObject& other) const
{
	const TextStatus* temp = dynamic_cast<const TextStatus*>(&other);
	if (temp == nullptr)
	{
		return (false);
	}
	else
	{
		if (text.compare(temp->text.c_str()) == 0)//compare the char * of both strings to see if its the same or not
		{
			return (true);
		}
		else
		{
			return (false);
		}
	}
}

bool TextStatus::operator!=(const StatusObject& other) const
{
	bool equal = (*this == other);
	return(!equal);
}
