#include "Member.h"
#include <string.h>
#include <iostream>
using namespace std;
#pragma warning (disable : 4996)

Member::Member(const std::string& newName, const Date& _birthDate) :FacebookEntity(newName), birthDate(_birthDate)//ctor
{

}

const Date& Member::getBirthDate() const//returns the birth date of the member.
{
	return birthDate;
}

vector <FanPage*>& Member::getLikedPages()//returns the array of the fan pages that the member likes.
{
	return likedPagesVectorPtr;
}

void Member::showFriends()//print the friends of the member.
{
	if (membersPtrVector.size() == 0)//check if the member has no friends
	{
		cout << "Member " << name << " has no friends";
	}

	else
	{
		vector<Member*>::iterator itr = membersPtrVector.begin();
		vector<Member*>::iterator itrEnd = membersPtrVector.end();
		cout << "Member " << name << " friends are: \n";
		for (int i = 0; itr != itrEnd; ++itr, i++)
		{
			cout << i << ". " << (*itr)->getName() << endl;
		}
	}
}

void Member::showLikedPages()//print the fan pages that the member likes.
{
	if (likedPagesVectorPtr.size() == 0)
	{
		cout << "Member " << name << " does not like any fan page." << endl;
	}
	else
	{
		vector<FanPage*>::iterator itr = likedPagesVectorPtr.begin();
		vector<FanPage*>::iterator itrEnd = likedPagesVectorPtr.end();
		for (int i = 0; itr != itrEnd; ++itr, i++)
		{
			cout << i << ". ";
			(*itr)->showEntity();
			cout << endl;
		}
	}
}


void Member::showEntity()//print member details.
{
	cout << "Member's details:\n";
	cout << "name: " << getName() << endl;
	cout << "birth date: ";
	birthDate.showDate();
	cout << "\nfriends: \n";
	showFriends();
	cout << "\nliked pages: \n";
	showLikedPages();
	cout << "_________________" << endl;
}




void Member::addNewFanPage(FanPage* newFanPage) // add a new fan page to the vector of liked pages of the member.
{
	likedPagesVectorPtr.push_back(newFanPage);
}

void Member::removeFanPage(const int& fanPageToRemoveIndex)//remove a fan page from the vector of liked pages of the member.
{
	likedPagesVectorPtr.erase(likedPagesVectorPtr.begin() + fanPageToRemoveIndex);
}


void Member::addNewFriend(Member* newFriend)//add a new friend to the vector of friends of the member.
{
	membersPtrVector.push_back(newFriend);
}

void Member::removeFriend(const int& memberToRemoveIndex)// remove a member from a member's friends vector.
{
	membersPtrVector.erase(membersPtrVector.begin() + memberToRemoveIndex);
}


int Member::checkFanPageExistence(FanPage* FanPageToCheck)//check if a specific fan page exists in the vector of the fan pages that the member likes.
{
	int position;
	vector<FanPage*>::iterator itr;
	itr = std::find(likedPagesVectorPtr.begin(), likedPagesVectorPtr.end(), FanPageToCheck);


	if (itr != likedPagesVectorPtr.end())//found the fan page
	{
		position = itr - likedPagesVectorPtr.begin();
	}
	else
	{
		position = NOT_FOUND;
	}
	return position;
}


void Member::checkFriendExistence(Member* memberToCheck, bool connectFriend, bool& wrongConnection, bool fromFile)noexcept(false)//check if a specific member exists in the vector of the friends of the member.
{
	bool found = false;
	vector<Member*>::iterator itr;
	itr = std::find(membersPtrVector.begin(), membersPtrVector.end(), memberToCheck);

	if (itr != membersPtrVector.end())//found the member
	{
		if (connectFriend == true && fromFile == false)
		{
			throw DuplicatefriendException();
		}
		else if (connectFriend == true && fromFile == true)
		{
			wrongConnection = true;
		}
	}
	else
	{
		if (connectFriend == false)
		{
			throw RemovefriendException();
		}
	}
}

Member::~Member()//dtor
{
	likedPagesVectorPtr.clear();
}




bool Member::operator>(const Member& other) const//opeartor > which compares between the amount of friends of 2 different members.
{
	return this->membersPtrVector.size() > other.membersPtrVector.size();
}

bool Member::operator>(const FanPage& other) const// operator > which compares between the amount of friends of a members and the amount of fans of a fan page.
{
	FanPage temp = other;
	return (this->membersPtrVector.size() > temp.getMembersPtrVector().size());
}

const Member& Member::operator+=(Member& newFriend)noexcept(false)// operator += for connecting between two members.
{
	bool parameterForFunc = false;
	try
	{
		this->checkFriendExistence(&newFriend, true, parameterForFunc);//check that these two members are actually friends.
		this->addNewFriend(&newFriend);
		newFriend.addNewFriend(this);

	}
	catch (DuplicatefriendException)
	{
		throw DuplicatefriendException();
	}

	return *this;
}

std::ostream& operator <<(std::ostream& os, Member& member)
{
	os << member.name << "\n";  //Print member name to file
	os << member.membersPtrVector.size() << "\n";//Print amount of friends to the file
	{
		std::vector<Member*>::iterator itr = member.membersPtrVector.begin();
		std::vector<Member*>::iterator itrEnd = member.membersPtrVector.end();
		for (; itr != itrEnd; ++itr)
		{
			os << (*itr)->getName() << "\n"; //print the names of the member's friends to the file
		}
	}
	{
		std::vector<StatusObject*>::iterator itr = member.getStatusesPtrVector().begin();
		std::vector<StatusObject*>::iterator itrEnd = member.getStatusesPtrVector().end();
		os << member.getStatusesPtrVector().size() << endl;
		for (; itr != itrEnd; ++itr)
		{
			os << typeid((*(*itr))).name() << "\n";
			os << (*itr)->getText() << "\n"; //print the statuses of the member
			os << (*itr)->getDate() << "\n";//print status date
			os << (*itr)->getTime() << "\n";
			if (typeid(*(*itr)).name() == typeid(ImageStatus).name())
			{
				const ImageStatus* temp = dynamic_cast<const ImageStatus*>((*itr));
				os << temp->getImageName() << "\n";
			}
			if (typeid(*(*itr)).name() == typeid(VideoStatus).name())
			{
				const VideoStatus* temp = dynamic_cast<const VideoStatus*>((*itr));
				os << temp->getVideoName() << "\n";
			}
		}
	}

	return os;
}