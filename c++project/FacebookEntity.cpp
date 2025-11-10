#include "FacebookEntity.h"


FacebookEntity::FacebookEntity(const std::string& newName)noexcept(false)
{
	name = newName;
}


const std::string& FacebookEntity::getName() const //returns the name of the entity(Member/Fanpage).
{
	return name;
}

FacebookEntity::operator const char* () const//function that returns the name of the fanPage(char*)
{
	return(name.c_str());
}

std::vector<Member*>& FacebookEntity::getMembersPtrVector()//getMembersVetor(Friends of a member/Fans of a page)
{
	return membersPtrVector;
}


std::vector<StatusObject*>& FacebookEntity::getStatusesPtrVector()//getStatusesVetor(Statuses of a member/Statuses of a page)
{
	return statusesPtrVector;
}


void FacebookEntity::showStatuses(bool onlyTenRecent) const //the function receives a bool parameter(default is false)
{					// the function shows the statuses  acording to receieved parameter, if parameter is true show only the last ten statuses in the vector, if parameter is false shows all statuses in the vector
	std::vector<StatusObject*>::const_iterator itr = statusesPtrVector.begin();
	std::vector<StatusObject*>::const_iterator itrEnd = statusesPtrVector.end();
	std::vector<StatusObject*>::const_reverse_iterator reverseItr = statusesPtrVector.rbegin();
	std::vector<StatusObject*>::const_reverse_iterator reverseItrEnd = statusesPtrVector.rend();
	if (onlyTenRecent == false)	// if parameter is false show all statuses in the vector
	{
		for (; itr != itrEnd; ++itr)
		{
			(*itr)->showStatus();
		}
	}
	else// if parameter is true show only the 10 last statuses
	{
		for (int i = 10; i > 0 && reverseItr != reverseItrEnd; i--, ++reverseItr)
		{
			(*reverseItr)->showStatus();
		}
	}
}


FacebookEntity::~FacebookEntity()//dtor
{
	membersPtrVector.clear();
	statusesPtrVector.clear();
}

