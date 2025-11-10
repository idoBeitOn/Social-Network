#ifndef _VIDEO_STATUS_H
#define _VIDEO_STATUS_H
#include "statusObject.h"

class VideoStatus :public StatusObject
{
private:
	std::string videoPath;
public:
	VideoStatus(std::string text, std::string videoPath);
	VideoStatus(std::string text, std::string videoPath, Date publicationDate, Clock publicationTime);
	virtual void showStatus() const override;
	const char* getVideoName() const; //get functions
	virtual bool operator==(const StatusObject& other) const override;// == operator compares two statuses by their text value returns true if equal else returns false
	virtual bool operator!=(const StatusObject& other) const override;
};


#endif // !_VIDEO_STATUS_H



