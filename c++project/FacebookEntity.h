#ifndef _FACEBOOK_ENTITY_H
#define _FACEBOOK_ENTITY_H

#include <iostream>
#include <vector>
#include "statusObject.h"

class StatusObject;
class Member;

class FacebookEntity
{
protected://Data members
	std::string name;
	std::vector<Member*> membersPtrVector;
	std::vector<StatusObject*> statusesPtrVector;

public:
	FacebookEntity(const std::string& newName)noexcept(false);//ctor
	const std::string& getName() const;//getName

	operator const char* () const;//getName
	std::vector<StatusObject*>& getStatusesPtrVector();//getStatusesVetor(Statuses of a member/Statuses of a page)

	void showStatuses(bool onlyTenRecent = false) const;// the function shows the statuses acording to receieved parameter
	virtual void showEntity() = 0;// printing function used by fanpage and member.


	~FacebookEntity();//dtor
	std::vector<Member*>& getMembersPtrVector(); 
};

#endif // !_FACEBOOK_ENTITY_H



