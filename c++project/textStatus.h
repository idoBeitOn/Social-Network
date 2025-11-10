#ifndef _TEXT_STATUS_H
#define _TEXT_STATUS_H
#include "statusObject.h"

class TextStatus :public StatusObject
{
public:
	TextStatus(std::string text);
	TextStatus(std::string text, Date publicationDate, Clock publicationTime);

	virtual void showStatus() const override;
	virtual bool operator==(const StatusObject& other) const override;
	virtual bool operator!=(const StatusObject& other) const override;

};



#endif // !_TEXT_STATUS_H




