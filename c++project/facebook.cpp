#include "facebook.h"
#include "UserFunctions.h"
#include "Member.h"

#include <iostream>
#pragma warning (disable : 4996)
using namespace std;


Facebook::~Facebook()	// dtor to delete all members and FanPages
{
	allFanPages.clear();
	allMembers.clear();
}

void Facebook::checkFanPageName(const std::string& name) const	noexcept(false)//the function recieves a FanPageName(const char*)
{														// the function checks whether the name exists in facebooks object FanPages array or if its empty throw an exception if name is empty or if the name already exist
	int index = 0;
	bool nameCorrect = true;
	list<FanPage>::const_iterator itr = allFanPages.begin();
	list<FanPage>::const_iterator itrEnd = allFanPages.end();
	if (name.length() == 0)//if the name is empty
	{
		throw ZeroLengthException();
	}
	else
	{
		for (; itr != itrEnd && nameCorrect == true; ++itr)
		{
			if (name.compare((*itr).operator const char* ()) == 0)//if name already exist throw an exception
			{
				nameCorrect = false;
				throw DuplicateFanPageException();
			}
		}
	}
}
void  Facebook::addNewFanPage(const std::string& name) noexcept(false)// the function receives a fanPages name(const string&)
{																	 // the function checks if it is possible to create a new fan page object using the recieved name if it is possible creates it an adds it to the fanPage array
	try                                                              // else throws an exception explaining why it wasnt possible to add the fanpage
	{
		checkFanPageName(name);
		allFanPages.push_back(FanPage(name));
	}
	catch (ZeroLengthException)// catch and re throw the exception back to the main so it will be handled there
	{
		throw ZeroLengthException();
	}
	catch (DuplicateFanPageException)// catch and re throw the exception back to the main so it will be handled there
	{
		throw DuplicateFanPageException();
	}
}

void  Facebook::checkFanPageIndexExistence(const int& index) const noexcept(false)// the function receives a fanPages index and checks if that index in the fanPages list has an object in it, throws an exception if that index doesnt have an object within it
{
	if (index < 0 || index >= allFanPages.size())
	{
		throw FanPageIndexException();
	}
}

void Facebook::removeFanPage(const int& indexOfFanPageToRemove) noexcept(false)	// the function receives a fanPages index and removes it from the system
{																				// throws an exception if removal wasnt possible
	list<FanPage>::iterator itr = allFanPages.begin();
	try
	{
		checkFanPageIndexExistence(indexOfFanPageToRemove);// check if the index recieved is within range
		advance(itr, indexOfFanPageToRemove);
		allFanPages.erase(itr);
	}
	catch (FanPageIndexException)// catch and re throw the exception back to the main so it will be handled there
	{
		throw FanPageIndexException();
	}

}

void Facebook::addStatusToFanPage(const int& fanPageIndex, StatusObject* newStatus) noexcept(false)	// the function receives a status object and a fanpage's index in the fanPages array
{																				//the function checks the index recieved and adds the new status to the fanPage in the index
	list<FanPage>::iterator itr = allFanPages.begin();							//if couldnt add the status throws an appropriate exception
	try
	{
		checkFanPageIndexExistence(fanPageIndex);
		advance(itr, fanPageIndex);	//advance the iterator to the correct index
		itr->addStatus(newStatus);	// add the received status to the correct fanPage
	}
	catch (FanPageIndexException)// catch and re throw the exception back to the main so it will be handled there
	{
		throw FanPageIndexException();
	}
}

void Facebook::checkMemberIndexExistence(const int& index) const noexcept(false) // the function receives a members index and checks if that index in the members list has an object in it, throws an exception if that index doesnt have an object within it
{
	if (index < 0 || index >= allMembers.size())
	{
		throw MemberIndexException();
	}
}

void Facebook::printAllFanPages(bool withIndexes)	// the function receives a bool parameter(default is true) according to which it prints all of the fanpages in the fanpage list in facebook class
{													// if parameter is true prints the fan pages with their indexes in the array else prints them without the indexes
	list<FanPage>::iterator itr = allFanPages.begin();
	list<FanPage>::iterator itrEnd = allFanPages.end();
	if (withIndexes == true)
	{
		for (int i = 0; itr != itrEnd; ++itr, i++)//print fan pages name with indexes
		{
			cout << i << ". ";
			(*itr).showEntity();
			cout << endl;
		}
	}
	else
	{
		for (; itr != itrEnd; ++itr)//print fan pages name without indexes
		{
			(*itr).showEntity();
			cout << endl;
		}
	}
}

void Facebook::addNewFanToFanPage(const int& fanPageIndex, const int& memberIndex) noexcept(false)// the function receives a member index and a fanpages index in their repective array's in facebook object by ref(const int&)
{																					// the function checks the indexes and connects the fanpage and the member by adding the member to the fanpages array of fans and the fan page to the members liked pages array
																					//throws an appropriate exception on failure
	list<FanPage>::iterator fanpageItr = allFanPages.begin();
	list<Member>::iterator memberItr = allMembers.begin();
	try
	{
		checkFanPageIndexExistence(fanPageIndex);
		advance(fanpageItr, fanPageIndex);
		checkMemberIndexExistence(memberIndex);
		advance(memberItr, memberIndex);
		if (fanpageItr->checkMemberExistence(&(*memberItr)) == NOT_FOUND) // if member not already a fan of this page try to add the member to the page
		{
			fanpageItr->addNewFan(&(*memberItr));	//connect fanpage to member and to fan page
		}
		else
		{
			throw DuplicateFanException();// if member already a fan of this page throw an exception
		}
	}
	catch (FanPageIndexException)// catch and re throw the exception back to the main so it will be handled there
	{
		throw FanPageIndexException();
	}
	catch (MemberIndexException)// catch and re throw the exception back to the main so it will be handled there
	{
		throw MemberIndexException();
	}
}

list <Member>& Facebook::getAllMembersList()	// get function for the members list
{
	return allMembers;
}

list<FanPage>& Facebook::getAllFanPagesList()	// get function for the fanPages list
{
	return(allFanPages);
}

void Facebook::addNewMember(const string& name, const Date& birthDate)noexcept(false)// the function receives a members name(const string&) and a members birth date(date object)
{																					// the function checks if it is possible to create a new member object using the recieved name if it is possible creates it an adds it to the members array
																					// if couldnt add the member throws an appropriate exception
	try
	{
		checkMemberName(name);
		checkBirthDate(birthDate);
		allMembers.push_back(Member(name, birthDate));
	}

	catch (ZeroLengthException& e)// catch and re throw the exception back to the main so it will be handled there
	{
		throw e;
	}
	catch (DuplicatefriendException& e)// catch and re throw the exception back to the main so it will be handled there
	{
		throw e;
	}
	catch (outOfRangeDayExcepton& e)// catch and re throw the exception back to the main so it will be handled there
	{
		throw e;
	}
	catch (outOfRangeMonthExcepton& e)// catch and re throw the exception back to the main so it will be handled there
	{
		throw e;
	}
	catch (outOfRangeYearExcepton& e)// catch and re throw the exception back to the main so it will be handled there
	{
		throw e;
	}
	catch (DuplicateMemberException& e)// catch and re throw the exception back to the main so it will be handled there
	{
		throw e;
	}

}

void Facebook::checkMemberName(const std::string& name) const noexcept(false)//the function recieves a Members name(const string&)												
{																			// the function checks whether the name exists in facebooks object Members array or if its empty
	bool nameCorrect = true;												 // throws an exception if any of the above
	list<Member>::const_iterator itr = allMembers.begin();
	list<Member>::const_iterator itrEnd = allMembers.end();
	if (name.length() == 0)//if the name is empty
	{
		throw ZeroLengthException();
	}
	else
	{
		for (; itr != itrEnd && nameCorrect == true; ++itr)
		{
			if (name.compare((*itr).operator const char* ()) == 0)//if name already exist throw an exception
			{
				nameCorrect = false;
				throw DuplicateMemberException();
			}
		}
	}

}

void Facebook::addStatusToMember(const int& memberIndex, StatusObject* newStatus)noexcept(false)//adds "newStatus" to the vector of statuses of the member throws an exception if wasnt able to add the status
{
	try
	{
		checkMemberIndexExistence(memberIndex);// checks whether the received index is within range 
		list<Member>::iterator itr = allMembers.begin();
		advance(itr, memberIndex);
		(*itr).getStatusesPtrVector().push_back(newStatus);
	}
	catch (MemberIndexException& e)//catch and re throw the exception to handle it in the main
	{
		throw e;
	}

}

void Facebook::showAllEntities()//a function that prints all entities (fanPages and members) in facebook object's arrays
{
	list<FanPage>::iterator fanpageItr = allFanPages.begin();
	list<FanPage>::iterator fanpageItrEnd = allFanPages.end();
	list<Member>::iterator memberItr = allMembers.begin();
	list<Member>::iterator memberItrEnd = allMembers.end();

	cout << "The members who are registerd to facebook are: \n";
	for (; memberItr != memberItrEnd; ++memberItr)
	{
		(*memberItr).showEntity();
	}

	cout << "\nThe fan pages who are registered to facebook are: \n";
	for (; fanpageItr != fanpageItrEnd; ++fanpageItr)
	{
		(*fanpageItr).showEntity();
		cout << endl;
	}
}

void Facebook::printAllMembers(bool withIndexes)// the function receives a bool parameter(default is true) according to which it prints all of the members in the members list in facebook class
{												// if parameter is true prints the members with their indexes in the array else prints them without the indexes
	if (withIndexes == true)
	{
		list<Member>::iterator itr = allMembers.begin();
		list<Member>::iterator itrEnd = allMembers.end();

		for (int i = 0; itr != itrEnd; ++itr, i++)//print members data with indexes
		{
			cout << i << ". ";
			itr->showEntity();
			cout << endl;
		}
	}
	else
	{
		list<Member>::iterator itr = allMembers.begin();
		list<Member>::iterator itrEnd = allMembers.end();
		for (; itr != itrEnd; ++itr)//print members data without indexes
		{
			itr->showEntity();
			cout << endl;
		}
	}
}

void Facebook::connectMembers(const int& mem1Index, const int& mem2Index, bool fromFile)noexcept(false)//Create friendship between 2 members throws an appropriate exception on failure
{
	list<Member>::iterator itr1 = allMembers.begin();
	list<Member>::iterator itr2 = allMembers.begin();
	bool fromFileWrongConnection = false;
	try
	{
		checkIndices(mem1Index, mem2Index);
		checkMemberIndexExistence(mem1Index);
		checkMemberIndexExistence(mem2Index);
		advance(itr1, mem1Index);
		advance(itr2, mem2Index);
		(itr1)->checkFriendExistence(&(*itr2), true, fromFileWrongConnection, fromFile);// check if the 2 members are friends of each other
		(itr2)->checkFriendExistence(&(*itr1), true, fromFileWrongConnection, fromFile);//check if the 2 members are friends of each other
		if (fromFileWrongConnection == false)
		{
			(itr1)->addNewFriend(&(*(itr2)));//add member2 to member 1 friends vector
			(itr2)->addNewFriend(&(*(itr1)));//add member2 to member 1 friends vector
		}
	}
	catch (SameMemberException& e)
	{
		throw e;
	}
	catch (MemberIndexException& e)
	{
		throw e;
	}

	catch (DuplicatefriendException& e)
	{
		throw e;
	}
}

void Facebook::cancelFriendship(const int& mem1Index, const int& mem2Index)noexcept(false) //cancel friendship between 2 friends throws an appropriate exception on failure
{
	list<Member>::iterator itr1 = allMembers.begin();
	list<Member>::iterator itr2 = allMembers.begin();
	bool parameterForFunction = false;
	try
	{
		checkMemberIndexExistence(mem1Index);
		checkMemberIndexExistence(mem2Index);
		advance(itr1, mem1Index);
		advance(itr2, mem2Index);
		itr1->checkFriendExistence(&(*itr2), false, parameterForFunction);// check if the 2 members are friends of each other
		itr2->checkFriendExistence(&(*itr1), false, parameterForFunction);//check if the 2 members are friends of each other
		int friendToRemoveIndex1 = findIndexInVector(*itr1, *itr2);//search in friends of mem1, where is the index of mem2 ?
		int friendToRemoveIndex2 = findIndexInVector(*itr2, *itr1);//search in friends of mem2, where is the index of mem1 ?
		itr1->removeFriend(friendToRemoveIndex1);//remove member 2 from the array of friends of member 1
		itr2->removeFriend(friendToRemoveIndex2);//remove member 1 from the array of friends of member 2
	}
	catch (MemberIndexException& e)
	{
		throw e;
	}
	catch (RemovefriendException& e)
	{
		throw e;
	}

}

int Facebook::findIndexInVector(Member& member1, Member& member2)//searches in member's 1 friends array where is the index of member 2 and returns it.
{
	int res = -1;
	int index = 0;
	vector <Member*>::iterator itr = member1.getMembersPtrVector().begin();
	vector <Member*>::iterator itrEnd = member1.getMembersPtrVector().end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName().compare(member2.getName()) == 0)// if the friends vector has a member with that name return his index in the vector
			res = index;
		index++;
	}
	return res;
}

void Facebook::checkBirthDate(const Date& birthDate) const noexcept(false)// the function recieves a date object by ref and checks whether it day month and year are within range
{																		// throws an exception if parameters are not within range

	if (birthDate.getDay() < 1 || birthDate.getDay() > 31)
	{
		throw outOfRangeDayExcepton();
	}
	if (birthDate.getMonth() < 1 || birthDate.getMonth() > 12)
	{
		throw outOfRangeMonthExcepton();
	}
	if (birthDate.getYear() < 0 || birthDate.getYear() > 2023)
	{
		throw outOfRangeYearExcepton();
	}

}

void Facebook::checkIndices(const int& mem1Index, const int& mem2Index) const noexcept(false)//the function receives two indexes and if they are the same throws an exception
{
	if (mem1Index == mem2Index)
		throw SameMemberException();
}