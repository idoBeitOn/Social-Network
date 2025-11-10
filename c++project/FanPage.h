#ifndef _FAN_PAGE_H
#define _FAN_PAGE_H
#include <iostream>
constexpr int NOT_FOUND = -1;
#include <string>
#include <vector>
#include "exceptions.h"
#include "statusObject.h"
#include "FacebookEntity.h"
#include "textStatus.h"
#include "imageStatus.h"
#include "videoStatus.h"
#include "Member.h"
#include <fstream>
#include <ostream>
#include <istream>
class Member;


class FanPage : public FacebookEntity	//FanPage object class
{
	//std::vector<Member*> membersPtrVector;
public:
	FanPage(const std::string& name);// FanPage Ctor
	const FanPage& operator+=(Member& other) noexcept(false);
	//+= operator adds the recived member as fan of the fan page that activated the operator
	// also add the fan page to the liked pages list of the recieved fan
	// throws an exception if the member is already a fan

	bool operator>(const FanPage& other) const;// > operator compares amount of fans of this fanpage to recived member's amount of friends
	bool operator>(const Member& other) const;//  > operator compares amount of fans of this fanpage to received fanpages's amount of friends

	void setNameOfPage(const std::string& name);
	//function that receives a string and changes the name of the page accordingly
	//operator const char* () const;
	//function that returns the name of the fanPage(char*)

	void addNewFan(Member* newFan);
	// the function receives a member *	
	// the function adds that member to the array of fans of that fanpage and also adds that fanpage to the received member's array of liked pages(connects fan and fan page in both directions)

	void removeFan(const int& fanToRemoveIndex);
	// the function receives an index of one of its fans by refference(int &)
	// the function removes the fan from the pages array of fans and also the page from the fan's list of liked pages (removes the link in both directions)

	//get function for the fanpage's array of fans


	virtual void showEntity() override;

	// a show function for the fan page object(prints its name)

	void             showFans();
	// a print function of the fan page's fans array (prints the fan's name and its index in the fans array)

	int              checkMemberExistence(Member* memberToCheck);
	// the function receives a pointer to a member(member*)
	// the function checks whether this member exists in fanPage's fans array(by checking members name) if it does returns its index in the array if it doesnt returns NOT_FOUND constexpr which is set to -1

	void checkMemberIndexExistence(const int& indexToCheck) noexcept(false);
	// the function receives an index in the fanPages fans array(const int&) 
	// the function checks whether recieved index is correct acording to size of the fans vector of current fanPage
	//the function throws an exception if index is not within range

	void  addStatus(StatusObject* newStatus);
	// the function receives a status object by ref and copies it to create a new status object inside FanPage status array
	//the function copies received object to create a new status object inside FanPage status array

	void  checkFansExistance() noexcept(false);//the function checks whether this fanpage has any fans throws an exception if no fans exist

	friend std::ostream& operator<<(std::ostream& os, FanPage& fanpage);
	//std::vector<Member*>& getMembersPtrVector();
};

#endif // !_FAN_PAGE_H




