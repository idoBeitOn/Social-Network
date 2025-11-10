#ifndef _MEMBER_H
#define _MEMBER_H


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ostream>
#include <istream>
#include "Date.h"
#include "FacebookEntity.h"
#include "FanPage.h"
class FanPage;


class Member :public FacebookEntity
{
	Date birthDate;
	//std::vector<Member*> membersPtrVector;
	std::vector <FanPage*> likedPagesVectorPtr;


public:
	Member(const std::string& newName, const Date& _birthDate) noexcept(false);//ctor

	const Date& getBirthDate() const;
	std::vector <FanPage*>& getLikedPages();



	void showLikedPages();//print the fan pages that the member likes.
	void showFriends();//print the friends of the member.
	virtual void showEntity()override;//print member details.



	void addNewFanPage(FanPage* newFanPage);//add a new fan page to the array of liked pages of the member.
	void removeFanPage(const int& fanPageToRemoveIndex);//remove a new fan page from the array of liked pages of the member.
	void addNewFriend(Member* newFriend);//add a new friend to the array of friends of the member.
	void removeFriend(const int& memberToRemoveIndex);//remove a friend from the array of friends of the member.
	int  checkFanPageExistence(FanPage* memberToCheck);//check if a specific fan page exists in the array of the fan pages that the member likes.
	void checkFriendExistence(Member* memberToCheck, bool connectFriend, bool& wrongConnection, bool fromFile = false)noexcept(false);//check if a specific member exists in the array of the friends of the member.

	const Member& operator+=(Member& newFriend)noexcept(false);// operator += for connecting between two members.
	bool operator>(const Member& other) const;//operator > for comparing the amount of friends between 2 memebrs.
	bool operator>(const FanPage& other) const;//operator > for comparing the amount of fans of a fan page to the amount of friends of a member.
	friend std::ostream& operator<<(std::ostream& os, Member& member);

	//std::vector<Member*>& getMembersPtrVector();

	~Member();//dtor

};
#endif // !_MEMBER_H
