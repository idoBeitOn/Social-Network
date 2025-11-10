#ifndef _EXCEPTIONS_H
#define _EXCEPTIONS_H
#include <iostream>


//This class manages the exceptions in the system.
class ZeroLengthException : public std::exception // Exception for empty name input.
{
public:
	const char* lengthError()
	{
		return("name cannot be empty");
	}

};

class DuplicateMemberException : public std::exception//Exception for duplicate member name input.
{
public:
	const char* duplicateMemberError()
	{
		return("Member with this name already exists");
	}

};


class DuplicateFanPageException : public std::exception//Exception for duplicate fan page name input.
{
public:
	const char* duplicateFanPageError()
	{
		return("fan page with that name already exists");
	}

};

class DuplicateFanException : public std::exception//Exception for the situation which a member tries to like the same page again.
{
public:
	const char* duplicateFanError()
	{
		return("member already a fan of this page");
	}

};

class DuplicatefriendException : public std::exception// Exception for the situation which trying to connect between two members who are already friends.
{
public:
	const char* friendsError()
	{
		return("These members are already friends!, can't connect between them again.");
	}
};

class RemovefriendException : public std::exception// Exception for the situation which trying to disconnect between two members who are not friends.
{
public:
	const char* removeError()
	{
		return("These members are not friends!, can't cancel friendship");
	}
};


class FanPageIndexException : public std::exception//Exception for wrong fan page index input.
{
public:
	const char* indexError()
	{
		return("fan page index out of range");
	}
};

class MemberIndexException : public std::exception//Exception for wrong member index input.
{
public:
	const char* indexError()
	{
		return("member index out of range");
	}
};

class StatusIndexException : public std::exception//Exception for wrong status index input.
{
public:
	const char* indexError()
	{
		return("status index out of range");
	}
};

class FanPageNoFansException : public std::exception//Exception for a fan page without fans.
{
public:
	const char* fansError()
	{
		return("the fan page has no fans");
	}
};

class outOfRangeDayExcepton : public std::exception//Exception for wrong day input.
{
public:
	const char* dayError()
	{
		return("Day out of range");
	}
};

class outOfRangeMonthExcepton : public std::exception//Exception for wrong month input.
{
public:
	const char* monthError()
	{
		return("Month out of range");
	}
};

class outOfRangeYearExcepton : public std::exception//Exception for wrong year input.
{
public:
	const char* yearError()
	{
		return("Year out of range");
	}
};

class SameMemberException : public std::exception//Exception for typing the same member index when trying to create/cancel friendship.
{
public:
	const char* sameIndexError()
	{
		return("cant connect or disconnect between same member");
	}
};

#endif 




