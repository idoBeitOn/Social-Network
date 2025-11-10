#ifndef _FACEBOOK_H
#define _FACEBOOK_H
#include <list>
#include "fanPage.h"
#include "exceptions.h"
#include "statusObject.h"
#include "textStatus.h"
#include "imageStatus.h"
#include "videoStatus.h"
#include <algorithm>

constexpr int  EXIT = 12;
constexpr char MEMBER_CONST = 'M';
constexpr char FAN_PAGE_CONST = 'F';

class FanPage;
class Member;

class Facebook	 // object that houses all data in the system and is used to enter and receive data from the system 
{
private:
	std::list<Member> allMembers;	//a list of all the members in the system
	std::list<FanPage> allFanPages;	//a list of all the fanpages in the system

public:
	~Facebook();//dtor
	void       checkFanPageName(const std::string& name) const noexcept(false);
	//the function recieves a FanPageName(const string&)
	// the function checks whether the name exists in facebooks object FanPages array or if its empty throw an exception if name is empty or if the name already exist

	void       addNewFanPage(const std::string& name) noexcept(false);
	// the function receives a fanPages name(const string&)
	// the function checks if it is possible to create a new fan page object using the recieved name if it is possible creates it an adds it to the fanPage array
	// else throws an exception explaining why it wasnt possible to add the fanpage

	void       checkMemberName(const std::string& name) const noexcept(false);
	//the function recieves a Members name(const string&)
	// the function checks whether the name exists in facebooks object Members array or if its empty
	// throws an exception if any of the above

	void       checkBirthDate(const Date& birthDate) const noexcept(false);
	// the function recieves a date object by ref and checks whether it day month and year are within range
	// throws an exception if parameters are not within range

	void       removeFanPage(const int& indexOfFanPageToRemove) noexcept(false);
	// the function receives a fanPages index and removes it from the system
	// throws an exception if removal wasnt possible

	void       addNewMember(const std::string& name, const Date& birthDate) noexcept(false);
	// the function receives a members name(const string&) and a members birth date(date object)
	// the function checks if it is possible to create a new member object using the recieved name if it is possible creates it an adds it to the members array
	// if couldnt add the member throws an appropriate exception

	void addStatusToFanPage(const int& fanPageIndex, StatusObject* newStatus) noexcept(false);
	// the function receives a status object and a fanpage's index in the fanPages array
	//the function checks the index recieved and adds the new status to the fanPage in the index
	//if couldnt add the status throws an appropriate exception

	void       addNewFanToFanPage(const int& fanPageIndex, const int& memberIndex) noexcept(false);
	// the function receives a member index and a fanpages index in their repective array's in facebook object by ref(const int&)
	// the function checks the indexes and connects the fanpage and the member by adding the member to the fanpages array of fans and the fan page to the members liked pages
	//throws an appropriate exception on failure

	void       checkFanPageIndexExistence(const int& index) const noexcept(false);
	// the function receives a fanPages index and checks if that index in the fanPages list has an object in it, throws an exception if that index doesnt have an object within it

	void       checkMemberIndexExistence(const int& index) const noexcept(false);
	// the function receives a members index and checks if that index in the members list has an object in it, throws an exception if that index doesnt have an object within it

	std::list<FanPage>& getAllFanPagesList();
	// get function for the fanPages list
	std::list <Member>& getAllMembersList();
	// get function for the members list

	void       printAllFanPages(bool withIndexes = true);
	// the function receives a bool parameter(default is true) according to which it prints all of the fanpages in the fanpage list in facebook class
	// if parameter is true prints the fan pages with their indexes in the array else prints them without the indexes

	void	   printAllMembers(bool withIndexes = true);
	// the function receives a bool parameter(default is true) according to which it prints all of the members in the members list in facebook class
	// if parameter is true prints the members with their indexes in the array else prints them without the indexes

	void	   showAllEntities();
	//a function that prints all entities (fanPages and members) in facebook object's arrays

	void       addStatusToMember(const int& memberIndex, StatusObject* newStatus)noexcept(false);//adds "newStatus" to the vector of statuses of the member throws an exception if wasnt able to add the status
	void       connectMembers(const int& mem1Index, const int& mem2Index, bool fromFile = false)noexcept(false);//Create friendship between 2 members throws an appropriate exception on failure
	void       cancelFriendship(const int& mem1Index, const int& mem2Index)noexcept(false);//cancel friendship between 2 friends throws an appropriate exception on failure
	int        findIndexInVector(Member& member1, Member& member2);//searches in member's 1 friends array where is the index of member 2 and returns it.
	void       checkIndices(const int& mem1Index, const int& mem2Index) const noexcept(false);//the function receives two indexes and if they are the same throws an exception


};

#endif // !_FACEBOOK_H



