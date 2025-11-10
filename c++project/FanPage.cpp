#include "FanPage.h"
#include "Member.h"

#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

FanPage::FanPage(const std::string& name) :FacebookEntity(name)	//ctor for fan page object intializes the object 
{
}

void FanPage::setNameOfPage(const std::string& name)	//function that receives a string and changes the name of the page accordingly
{
	FacebookEntity::name = name;
}

void  FanPage::addStatus(StatusObject* newStatus)     // the function receives a status object by ref and copies it to create a new status object inside FanPage status array
{												//the function copies received object to create a new status object inside FanPage status array
	statusesPtrVector.push_back(newStatus);
}

void FanPage::showEntity()	// a show function for the fan page object(prints its name)
{
	cout << name.c_str();
}

int FanPage::checkMemberExistence(Member* memberToCheck)	// the function receives a pointer to a member(member*)
{															// the function checks whether this member exists in fanPage's fans array(by checking members name) if it does returns its index in the array if it doesnt returns NOT_FOUND constexpr which is set to -1
	bool found = false;
	int index = 0;
	vector<Member*>::iterator itr = membersPtrVector.begin();
	vector<Member*>::iterator itrEnd = membersPtrVector.end();
	for (; itr != itrEnd && found == false; ++itr)
	{
		if ((*itr)->getName().compare(memberToCheck->getName()) == 0)//check if a member with this name already exists in pages fans list
		{
			found = true;
		}
		index++;
	}
	if (found == true)	// if found return the correct index beacuse the loop increased it by to much
	{
		index--;
	}
	else
	{
		index = NOT_FOUND;
	}
	return(index);
}

void FanPage::showFans() // a print function of the fan page's fans array (prints the fan's name and its index in the fans array)
{
	vector<Member*>::iterator itr = membersPtrVector.begin();
	vector<Member*>::iterator itrEnd = membersPtrVector.end();
	cout << "The names of the members who are fans of this page are:\n";
	for (int i = 0; itr != itrEnd; ++itr, i++)
	{
		cout << i << ". " << (*itr)->getName();
		cout << "\n";
	}
}

void FanPage::addNewFan(Member* newFan) // the function receives a member *
{										// the function adds that member to the array of fans of that fanpage and also adds that fanpage to the received member's array of liked pages(connects fan and fan page in both directions)
										// return true on success
	bool otherDirectionAdd = false;
	membersPtrVector.push_back(newFan);	// adds the new member to list of fans of current page
	newFan->addNewFanPage(this); //add current fan page to received members liked pages
}

void FanPage::removeFan(const int& fanToRemoveIndex)	// the function receives an index of one of its fans by refference(int &)
{														// the function removes the fan from the pages array of fans and also the page from the fan's list of liked pages (removes the link in both directions)
	bool otherDirectionRemove = false;
	vector<Member*>::iterator itr = membersPtrVector.begin();
	vector<Member*>::iterator itrEnd = membersPtrVector.end();
	(*(itr + fanToRemoveIndex))->removeFanPage((*(itr + fanToRemoveIndex))->checkFanPageExistence(this));	//removes the fanPage from the member's liked pages(member that has the received index in the current fanPages Array of fans)
	membersPtrVector.erase(itr + fanToRemoveIndex); //remove the fan from the pages array of fans
}

void FanPage::checkMemberIndexExistence(const int& indexToCheck) noexcept(false)	// the function receives an index in the fanPages fans array(const int&) 
{																					// the function checks whether recieved index is correct acording to size of the fans vector of current fanPage
	if (indexToCheck < 0 || indexToCheck >= membersPtrVector.size())						//the function throws an exception if index is not within range
	{
		throw MemberIndexException();
	}
}

const FanPage& FanPage::operator+=(Member& other) noexcept(false) //+= operator adds the recived member as fan of the fan page that activated the operator
{																  // also add the fan page to the liked pages list of the recieved fan
																  // throws an exception if the member is already a fan
	if (this->checkMemberExistence(&other) != NOT_FOUND)// check if member is already a fan of this page
	{
		throw DuplicateFanException();
	}
	else
	{
		addNewFan(&other);
	}
	return *this;
}

bool FanPage::operator>(const FanPage& other) const	// > operator compares amount of fans of this fanpage to received member's amount of friends
{
	if (membersPtrVector.size() > other.membersPtrVector.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool FanPage::operator>(const Member& other) const //  > operator compares amount of fans of this fanpage to received fanpages's amount of friends
{
	Member temp = other;
	if (membersPtrVector.size() > temp.getMembersPtrVector().size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void  FanPage::checkFansExistance() noexcept(false)	//the function checks whether this fanpage has any fans throws an exception if no fans exist
{
	if (membersPtrVector.size() == 0)
	{
		throw FanPageNoFansException();
	}
}

ostream& operator<<(ostream& os, FanPage& fanpage)
{
	os << fanpage.getName() << "\n";
	vector<Member*>::iterator itr = fanpage.getMembersPtrVector().begin();
	vector<Member*>::iterator itrEnd = fanpage.getMembersPtrVector().end();
	vector<StatusObject*>::iterator statusItr = fanpage.getStatusesPtrVector().begin();
	vector<StatusObject*>::iterator statusItrEnd = fanpage.getStatusesPtrVector().end();
	os << fanpage.getMembersPtrVector().size() << endl;
	for (; itr != itrEnd; ++itr)
	{
		os << (*itr)->getName() << "\n"; // print the fan page name
	}
	os << fanpage.getStatusesPtrVector().size() << endl;
	for (; statusItr != statusItrEnd; ++statusItr)// print the fan page statuses
	{
		os << typeid(*(*statusItr)).name() << "\n";
		os << (*statusItr)->getText() << "\n"; //print the statuses of the member
		os << (*statusItr)->getDate() << "\n";//print status date
		os << (*statusItr)->getTime() << "\n";
		if (typeid(*(*statusItr)).name() == typeid(ImageStatus).name())
		{
			const ImageStatus* temp = dynamic_cast<const ImageStatus*>((*statusItr));
			os << temp->getImageName() << "\n";
		}
		if (typeid(*(*statusItr)).name() == typeid(VideoStatus).name())
		{
			const VideoStatus* temp = dynamic_cast<const VideoStatus*>((*statusItr));
			os << temp->getVideoName() << "\n";
		}


	}

	return (os);
}