#ifndef _IMAGE_STATUS_H
#define _IMAGE_STATUS_H
#include "statusObject.h"

class ImageStatus :public StatusObject
{
private:
	std::string imagePath;
public:
	ImageStatus(std::string text, std::string imagePath);
	ImageStatus(std::string text, std::string imagePath, Date publicationDate, Clock publicationTime);
	virtual void showStatus() const override;
	const char* getImageName() const; //get functions
	virtual bool operator==(const StatusObject& other) const override;// == operator compares two statuses by their text value returns true if equal else returns false
	virtual bool operator!=(const StatusObject& other) const override;
};



#endif // !_IMAGE_STATUS_H



