#include "userFunctions.h"
#include "Member.h"
#include <iostream>
#include <string>
#pragma warning (disable : 4996)
using namespace std;


const Date getMemberBirthDateFromUser() // get birth date of member from the user
{
	Date res;
	short day, month, year;
	cout << "Please enter member's birth date in this order: day,month,year" << endl;
	cin >> day;
	cin >> month;
	cin >> year;
	res.setDay(day);
	res.setMonth(month);
	res.setYear(year);
	return res;
}


const string getMemberNameFromUser(Facebook& admin) // get name of member from the user
{
	string res;
	cout << "Please enter member's name" << endl;
	getline(cin, res);
	return res;
}


const int getMemberIndexFromUser()//get index of a member from the user
{
	int res;
	cout << "Please enter the index of the member ";
	cin >> res;
	return res;
}

const short getFanPageIndexFromUser()// get index of a fan page from the user
{
	short res;
	cout << "Please enter the index of the fan page";
	cin >> res;
	return res;
}

void getMemberIndicesFromUser(int* pIndex1, int* pIndex2, Facebook& admin)//get 2 indices of members from the user
{
	int size = admin.getAllMembersList().size();
	cout << "Enter index of the first member";
	cin >> *pIndex1;
	cout << "Enter index of the second member";
	cin >> *pIndex2;

}


void addNewMemberProcess(Facebook& admin)noexcept(false)//Adding new member to facebook system
{

	Date memberBirthDate;
	string memberName;
	cleanBuffer();
	memberName = getMemberNameFromUser(admin);//get the new member birth name
	memberBirthDate = getMemberBirthDateFromUser();//get the new member birth date

	try
	{
		admin.addNewMember(memberName, memberBirthDate);//add the new memebr to facebook while checking that the member's datails are valid.
		cout << "Member added succesfully to facebook." << endl;
	}
	catch (ZeroLengthException& e)//exception for empty name.
	{
		cout << e.lengthError() << endl;
	}
	catch (DuplicatefriendException& e)//exception for empty name.
	{
		cout << e.friendsError() << endl;
	}
	catch (outOfRangeDayExcepton& e)//exception for invalid input for the member's day in his birthdate.
	{
		cout << e.dayError() << endl;
	}
	catch (outOfRangeMonthExcepton& e)//exception for invalid input for the member's month in his birthdate.
	{
		cout << e.monthError() << endl;
	}
	catch (outOfRangeYearExcepton& e)//exception for  invalid input for the member's year in his birthdate.
	{
		cout << e.yearError() << endl;
	}
	catch (DuplicateMemberException& e)//exception for  invalid input for members name
	{
		cout << e.duplicateMemberError() << endl;
	}

}

string getStatusFromUser()//get status from the user
{
	string res;
	cout << "Please enter status ";
	getline(cin, res);
	return res;
}



void addStatusToMemberProcedure(Facebook& admin)noexcept(false)//Add a new status to a member
{
	int index;
	string statusText;
	string anotherField;
	char statusType;
	list<Member>::iterator itr = admin.getAllMembersList().begin();//using iterator to run on the list.
	list<Member>::iterator itrEnd = admin.getAllMembersList().end();

	cout << "Members in the system:" << endl;//print the members in the system
	for (int i = 0; itr != itrEnd; ++itr, i++)
	{
		cout << i << "	" << (itr)->getName().c_str() << endl;
	}

	index = getMemberIndexFromUser();
	cleanBuffer();
	cout << "enter the type of status you want to enter: enter T for text status I for image status V for video status" << endl;
	cin >> statusType;
	cleanBuffer();
	try
	{
		switch (statusType)
		{
		case TEXT_STATUS:
			cout << "please enter text " << endl;
			getline(cin, statusText);
			admin.addStatusToMember(index, new TextStatus(statusText));//add the new status to the requested fan page
			cout << "status created succesfully" << endl;
			break;
		case IMAGE_STATUS:
			cout << "please enter text  and image Path seperated by enter" << endl;
			getline(cin, statusText);
			getline(cin, anotherField);
			admin.addStatusToMember(index, new ImageStatus(statusText, anotherField));//add the new status to the requested fan page
			cout << "status created succesfully" << endl;
			break;
		case VIDEO_STATUS:
			cout << "please enter text  and video Path seperated by enter" << endl;
			getline(cin, statusText);
			getline(cin, anotherField);
			admin.addStatusToMember(index, new VideoStatus(statusText, anotherField));//add the new status to the requested fan page
			cout << "status created succesfully" << endl;
			break;
		default:
			cout << "incorrect option returning to menu..." << endl;
			break;
		}
	}
	catch (MemberIndexException& e)
	{
		cout << e.indexError() << endl;
	}
}

void cleanBuffer()// cleaning the buffer
{
	int a = getchar();
}

void connectTwoMembersProcces(Facebook& admin)//Create friendship between 2 members
{
	int mem1Index, mem2Index;
	list<Member>::iterator itr = admin.getAllMembersList().begin();//using iterator to run on the list
	list<Member>::iterator itrEnd = admin.getAllMembersList().end();
	cout << "Members in the system:" << endl;
	for (int i = 0; itr != itrEnd; ++itr, i++)//print all the members in the system
	{
		cout << i << ". " << (itr)->getName() << endl;
	}

	getMemberIndicesFromUser(&mem1Index, &mem2Index, admin);

	try
	{
		admin.connectMembers(mem1Index, mem2Index);//Connect between 2  memebr  while checking that the member's indices are valid.
		cout << "These two members are now friends.";
	}
	catch (SameMemberException& e)//exception for same member input
	{
		cout << e.sameIndexError() << endl;
	}

	catch (MemberIndexException& e)
	{
		cout << e.indexError() << endl;
	}

	catch (DuplicatefriendException& e)//exception for trying to connect between 2 members who are already frineds.
	{
		cout << e.friendsError() << endl;
	}

}

void cancelFriendshipProcces(Facebook& admin)noexcept(false)//Cancel friendship between 2 members
{
	int mem1Index, mem2Index;

	cout << "Members in the system:" << endl;
	admin.printAllMembers();
	getMemberIndicesFromUser(&mem1Index, &mem2Index, admin);//get members indices from the user

	try
	{
		admin.cancelFriendship(mem1Index, mem2Index);//Cancel friendship  between 2  memebrs  while checking that they are actualy friends.
		cout << "These 2 members are no longer friends";
	}

	catch (SameMemberException& e)//exception for typing the same member index.
	{
		cout << e.sameIndexError() << endl;
	}

	catch (MemberIndexException& e)
	{
		cout << e.indexError() << endl;
	}
	catch (RemovefriendException& e)//exceotion for the situation which these 2 memebers are not friends in the first place.
	{
		cout << e.removeError() << endl;
	}
}



void showFriendsOrFans(Facebook& admin) //print friends of a specific member or fans of a specific fan page
{
	char input;
	bool res = false;
	list<Member>::iterator memberItr = admin.getAllMembersList().begin();
	list<Member>::iterator memberItrEnd = admin.getAllMembersList().end();
	cout << "do you wish to print friends of a member of fans of a page? press " << MEMBER_CONST << "  for member and " << FAN_PAGE_CONST << " for Fan Page " << endl;
	short index;
	cin >> input;//ger choice from the user if he wants to print freinds of a specific meber or fans of a fan page
	cleanBuffer();
	if (input == MEMBER_CONST)//member path chosen
	{
		list<Member>::iterator itr = admin.getAllMembersList().begin();
		for (int i = 0; memberItr != memberItrEnd; ++memberItr, i++)//print all the members in the system
		{
			cout << i << ". " << memberItr->getName() << endl;
		}
		index = getMemberIndexFromUser();
		try
		{
			admin.checkMemberIndexExistence(index);
			advance(itr, index);
			itr->showFriends(); // show the chosen member friends while checking the the index input is valid.
		}
		catch (MemberIndexException& e)//exception for invalid index input.
		{
			cout << e.indexError() << endl;
		}
	}
	else if (input == FAN_PAGE_CONST)//fan page path chosen
	{
		list<FanPage>::iterator itr = admin.getAllFanPagesList().begin();
		admin.printAllFanPages();//print all fan pages in the system
		index = getFanPageIndexFromUser();
		try
		{
			admin.checkFanPageIndexExistence(index);
			advance(itr, index);
			itr->showFans();// show the chosen fan page fans while checking the the index input is valid.
		}
		catch (FanPageIndexException& e)//exception for invalid index input.
		{
			cout << e.indexError() << endl;
		}
	}
	else
	{
		cout << "Wrong input.";
	}
}

void Show10RecentStatuses(Facebook& admin)// print 10 most recent statuses of each friend of a specific member
{
	list<Member>::iterator itr = admin.getAllMembersList().begin();
	list<Member>::iterator itrEnd = admin.getAllMembersList().end();
	cout << "All the members in the system:" << endl;
	for (int i = 0; itr != itrEnd; ++itr, i++)//print all the members in the system
	{
		cout << i << ". " << itr->getName() << endl;
	}
	itr = admin.getAllMembersList().begin();
	short input;
	cout << "Enter the index of the member you want to show the 10 most recent statuses of each of his friends. ";
	cleanBuffer();
	input = getMemberIndexFromUser();
	try
	{
		admin.checkMemberIndexExistence(input);
		advance(itr, input);
		printFriendsStatuses(itr->getMembersPtrVector());//show the chosen member's friends 1- most recent statuses fans while checking the the index input is valid.
	}
	catch (MemberIndexException& e)//exception for wrong index input.
	{
		cout << e.indexError() << endl;
	}
}


void printFriendsStatuses(vector<Member*> friendsArr)//print the statuses of friends of a specific member
{
	vector<Member*>::iterator itr = friendsArr.begin();
	vector<Member*>::iterator itrEnd = friendsArr.end();

	cout << "Friends statuses of this member's friends are: " << endl;
	for (int i = 0; itr != itrEnd; ++itr)
	{
		cout << (*itr)->getName() << "'s statuses: " << endl;
		(*itr)->showStatuses(true);
		cout << "___________________" << endl;
	}
}

void enterHardCoddedDataToFacebook(Facebook& facebook, bool isEmptyFile)//load hard coded data into the system
{
	if (isEmptyFile == true)
	{
		facebook.addNewFanPage(" fan page number zero"); // hard codded data 
		facebook.addNewFanPage(" fan page number one");
		facebook.addNewFanPage(" fan page number two");
		facebook.addNewFanPage(" fan page number three");

		facebook.addNewMember("member 0", Date(2, 5, 1997));
		facebook.addNewMember("member 1", Date(5, 9, 1995));
		facebook.addNewMember("member 2", Date(5, 9, 1990));
		facebook.addNewMember("member 3", Date(2, 12, 1997));
		list<FanPage>::iterator fanPageItr = facebook.getAllFanPagesList().begin();
		list<Member>::iterator memberItr = facebook.getAllMembersList().begin();
		fanPageItr->addNewFan(&(*memberItr));
		++fanPageItr;
		++fanPageItr;
		fanPageItr->addNewFan(&(*memberItr));
		++memberItr;
		fanPageItr->addNewFan(&(*memberItr));

		facebook.addStatusToFanPage(0, new TextStatus("status text of page 0 "));
		facebook.addStatusToFanPage(0, new ImageStatus("status image of page 0 ", "test image0.jpg"));
		facebook.addStatusToFanPage(0, new VideoStatus("status video of page 0 ", "video image.jpg"));
		facebook.addStatusToFanPage(1, new TextStatus("status text of page 1 "));
		facebook.addStatusToFanPage(1, new ImageStatus("status image of page 1", "test image1.jpg"));
		facebook.addStatusToFanPage(1, new VideoStatus("status video of page 1", "test video1.mov"));

		facebook.addStatusToFanPage(2, new TextStatus("status text of page 2"));
		facebook.addStatusToFanPage(2, new ImageStatus("status image of page 2 ", "test image2.jpg"));
		facebook.addStatusToFanPage(2, new VideoStatus("status video of page 2 ", "video video2.mov"));

		facebook.addStatusToFanPage(3, new TextStatus("status text of page 3"));
		facebook.addStatusToFanPage(3, new ImageStatus("status image of page 3 ", "test image3.jpg"));
		facebook.addStatusToFanPage(3, new VideoStatus("status video of page 2 ", "video video3.mov"));

		facebook.addStatusToMember(0, new TextStatus(" status text of member 0 "));
		facebook.addStatusToMember(0, new ImageStatus(" status Image of member 0 ", "test image for Member 0.jpg"));
		facebook.addStatusToMember(0, new VideoStatus(" status Video of member 0 ", "test video for Member 0.mov"));

		facebook.addStatusToMember(1, new TextStatus(" status text of member 1 "));
		facebook.addStatusToMember(1, new ImageStatus(" status Image of member 1 ", "test image for Member 1.jpg"));
		facebook.addStatusToMember(1, new VideoStatus(" status Video of member 0 ", "test video for Member 1.mov"));

		facebook.addStatusToMember(2, new TextStatus(" status text of member 2 "));
		facebook.addStatusToMember(2, new ImageStatus(" status Image of member 2 ", "test image for Member 2.jpg"));
		facebook.addStatusToMember(2, new VideoStatus(" status Video of member 2 ", "test video for Member 2.mov"));

		facebook.addStatusToMember(3, new TextStatus(" status text of member 3 "));
		facebook.addStatusToMember(3, new ImageStatus(" status Image of member 3 ", "test image for Member 3.jpg"));
		facebook.addStatusToMember(3, new VideoStatus(" status Video of member 3 ", "test video for Member 3.mov"));
		bool test=(*fanPageItr).getStatusesPtrVector()[1] == (*fanPageItr).getStatusesPtrVector()[0];
		facebook.connectMembers(0, 1);
		facebook.connectMembers(0, 2);
		facebook.connectMembers(1, 3);
	}
}

void printMenu()
{
	cout << "Choose one option from the menu" << endl;
	cout << "1 - Add new Member" << endl;
	cout << "2 - Add new Fan Page" << endl;
	cout << "3 - Add status" << endl;
	cout << "4 - Show statuses" << endl;
	cout << "5 - Show 10 most recent statuses" << endl;
	cout << "6 - Connect two friends" << endl;
	cout << "7 - Cancel friendship" << endl;
	cout << "8 - Add a fan to a page" << endl;
	cout << "9 - Remove a fan from a page" << endl;
	cout << "10 - Show all entities in the system" << endl;
	cout << "11 - Show all friends(of a member)/fans(of a page)" << endl;
	cout << "12 - Exit" << endl;
}

void addFanPageProcedure(Facebook& admin)//add new fan page to facebook
{
	string name;
	cout << "enter the name of the new FanPage" << endl;
	cleanBuffer();
	getline(cin, name);
	try
	{
		admin.addNewFanPage(name);//check that the name is legal(not already exist in the system)
		cout << "fan page created succesfully" << endl;
	}
	catch (ZeroLengthException& e)//exception for empty name input.
	{
		cout << e.lengthError() << endl;
	}
	catch (DuplicateFanPageException& e)//exception for duplicated name input.
	{
		cout << e.duplicateFanPageError() << endl;
	}
}
void addStatusProcedure(Facebook& admin)//add new status to the system(to member or fan page)
{
	char input;
	bool res = false;
	cleanBuffer();
	cout << "do you wish to enter a status for a fan Page or member? press " << MEMBER_CONST << " to enter Status for member and " << FAN_PAGE_CONST << " to enter Status for Fan Page " << endl;
	input = getchar();
	switch (input)
	{
	case MEMBER_CONST:
		addStatusToMemberProcedure(admin);//add the new status to a member
		break;
	case FAN_PAGE_CONST:
		cleanBuffer();
		addStatusForFanPageProcedure(admin);//add the new status to a fan page
		break;
	default:
		cout << "incorrect option returning to menu..." << endl;
		break;
	}
}

void addStatusForFanPageProcedure(Facebook& admin)//add a new status to a fan page
{
	int index;
	string statusText;
	string anotherField;
	char statusType;
	bool res = false;
	cout << "fan pages in the system:" << endl;
	admin.printAllFanPages();//print all the fan pages in facebook
	cout << "enter the number of FanPage you wish to add the status to" << endl;
	cin >> index;
	cleanBuffer();
	cout << "enter the type of status you want to enter: enter T for text status I for image status V for video status" << endl;
	cin >> statusType;
	cleanBuffer();
	try
	{
		switch (statusType)
		{
		case TEXT_STATUS:
			cout << "please enter text " << endl;
			getline(cin, statusText);
			admin.addStatusToFanPage(index, new TextStatus(statusText));//add the new status to the requested fan page
			cout << "status created succesfully" << endl;
			break;
		case IMAGE_STATUS:
			cout << "please enter text  and image Path seperated by enter" << endl;
			getline(cin, statusText);
			//cleanBuffer();
			getline(cin, anotherField);
			admin.addStatusToFanPage(index, new ImageStatus(statusText, anotherField));//add the new status to the requested fan page
			cout << "status created succesfully" << endl;
			break;
		case VIDEO_STATUS:
			cout << "please enter text  and video Path seperated by enter" << endl;
			getline(cin, statusText);
			//cleanBuffer();
			getline(cin, anotherField);
			admin.addStatusToFanPage(index, new VideoStatus(statusText, anotherField));//add the new status to the requested fan page
			cout << "status created succesfully" << endl;
			break;
		default:
			cout << "incorrect option returning to menu..." << endl;
			break;
		}
	}
	catch (FanPageIndexException& e)
	{
		cout << e.indexError() << endl;
	}
}

void addFanToFanPageProcedure(Facebook& admin)// add a new fan to fan page
{
	list<FanPage>::iterator fanPageItr = admin.getAllFanPagesList().begin();
	list<FanPage>::iterator fanPageItrEnd = admin.getAllFanPagesList().end();
	list<Member>::iterator memberItr = admin.getAllMembersList().begin();
	list<Member>::iterator memberItrEnd = admin.getAllMembersList().end();
	int fanPageindex, memberIndex;
	cout << "fan pages in the system:" << endl;
	admin.printAllFanPages();//print all fan pages in facebook
	cout << "enter the number of FanPage you wish to add a new fan to" << endl;
	cin >> fanPageindex;
	try
	{
		admin.checkFanPageIndexExistence(fanPageindex);
		cout << "members in the system:" << endl;//print all members in the system
		for (int i = 0; memberItr != memberItrEnd; ++memberItr, i++)
		{
			cout << i << ". " << memberItr->getName() << endl;
		}
		cout << "enter the number of member you wish to add to the page" << endl;
		cin >> memberIndex;
		admin.addNewFanToFanPage(fanPageindex, memberIndex);//add a new fan to a fan page while checking that the indices input are valid.
		cout << "fan added succesfully to page" << endl;
	}
	catch (FanPageIndexException& e)//excepton for invalid fan page index input.
	{
		cout << e.indexError() << endl;
	}
	catch (MemberIndexException& e)//exception for invalid member index input.
	{
		cout << e.indexError() << endl;
	}
	catch (DuplicateFanException& e)//exception for the situation where 
	{
		cout << e.duplicateFanError() << endl;
	}
}
void removeFanFromFanPageProcedure(Facebook& admin)//remove a fan from a specific fan page
{
	list<FanPage>::iterator itr = admin.getAllFanPagesList().begin();
	list<FanPage>::iterator itrEnd = admin.getAllFanPagesList().end();
	int fanPageindex, memberIndex;
	cout << "fan pages in the system:" << endl;
	admin.printAllFanPages();//print all the fan pages
	cout << "enter the number of FanPage you wish to remove a fan from" << endl;
	cin >> fanPageindex;
	try
	{
		admin.checkFanPageIndexExistence(fanPageindex); //check the fan page index input.
		advance(itr, fanPageindex);
		itr->checkFansExistance();//check that this fan page has friends.
		cout << "page's fans:" << endl;
		itr->showFans();//print the fans of this fan page
		cout << "enter the number of member you wish to remove from the page" << endl;
		cin >> memberIndex;
		itr->checkMemberIndexExistence(memberIndex);
		itr->removeFan(memberIndex);//remove the chosen member from liking that page.
		cout << "fan removed Succesfully from page" << endl;
	}
	catch (FanPageIndexException& e)//exception for invalid fan page index input.
	{
		cout << e.indexError() << endl;
	}
	catch (FanPageNoFansException& e)//exception for a fan page without fans.
	{
		cout << e.fansError() << endl;
	}
	catch (MemberIndexException& e)//exception for invalid member index input.
	{
		cout << e.indexError() << endl;
	}
}

void showStatusesProcedure(Facebook& admin)//Print status
{
	list<FanPage>::iterator fanPageItr = admin.getAllFanPagesList().begin();
	list<FanPage>::iterator fanPageItrEnd = admin.getAllFanPagesList().end();
	list <Member>::iterator memberItr = admin.getAllMembersList().begin();
	list <Member>::iterator memberItrEnd = admin.getAllMembersList().end();
	char input;
	bool res = false;
	int indexOfEntity;
	cleanBuffer();
	cout << "do you wish to view statuses for a fan Page or member? press " << MEMBER_CONST << "  for member and " << FAN_PAGE_CONST << " for Fan Page " << endl;
	input = getchar();//choice if to print status of a fan page or status of a member
	cleanBuffer();
	switch (input)
	{
	case MEMBER_CONST://if member
		cout << "Members in the system:" << endl;//print all members in facebook

		for (int i = 0; memberItr != memberItrEnd; i++, ++memberItr)
		{
			cout << i << ". " << memberItr->getName() << endl;
		}
		cout << "enter the number of Member you wish to view the statuses of" << endl;
		cin >> indexOfEntity;//get the requested member index
		cleanBuffer();
		memberItr = admin.getAllMembersList().begin();
		try
		{
			admin.checkMemberIndexExistence(indexOfEntity);//check that the member index input is valid.
			advance(memberItr, indexOfEntity);
			cout << "statuses of selected member" << endl;
			memberItr->showStatuses();//printh the statuses of the chosen member.
		}
		catch (MemberIndexException& e)
		{
			cout << e.indexError() << endl;
		}
		break;
	case FAN_PAGE_CONST://if fan page
		cout << "fan pages in the system:" << endl;
		admin.printAllFanPages();//print all fan pages in the system
		cout << "enter the number of FanPage you wish to view the statuses of" << endl;
		cin >> indexOfEntity;//get the requested fan page index
		cleanBuffer();
		try
		{
			admin.checkFanPageIndexExistence(indexOfEntity);
			cout << "statuses of selected Fan Page" << endl;
			advance(fanPageItr, indexOfEntity);
			fanPageItr->showStatuses();//print the statuses of the selected fan page
		}
		catch (FanPageIndexException& e)
		{
			cout << e.indexError() << endl;
		}
		break;
	default:
		cout << "incorrect option returning to menu..." << endl;
		break;
	}
}

void executeUserInterface(Facebook& facebook)// function the manages the running of the program
{
	printMenu();
	short input;
	cin >> input;

	while (input != EXIT)
	{
		switch (input)
		{
		case 1:
			try
			{
				addNewMemberProcess(facebook);
				cleanBuffer();
				cout << endl;
				printMenu();
				cin >> input;
			}
			catch (...)
			{
				cout << "unknown error" << endl;
			}
			break;
		case 2:
			try
			{
				addFanPageProcedure(facebook);
				cout << endl;
				printMenu();
				cin >> input;
				printMenu();
			}
			catch (...)
			{
				cout << "unknown error" << endl;
			}
			break;
		case 3:
			try
			{
				addStatusProcedure(facebook);
				cout << endl;
				printMenu();
				cin >> input;
			}
			catch (...)
			{
				cout << "unknown error" << endl;
			}
			break;
		case 4:
			try
			{
				showStatusesProcedure(facebook);
				cout << endl;
				printMenu();
				cin >> input;
			}
			catch (...)
			{
				cout << "unknown error" << endl;
			}
			break;
		case 5:
			try
			{
				Show10RecentStatuses(facebook);
				cout << endl;
				printMenu();
				cin >> input;
			}
			catch (...)
			{
				cout << "unknown error" << endl;
			}
			break;
		case 6:
			try
			{
				connectTwoMembersProcces(facebook);
				cout << endl;
				printMenu();
				cin >> input;
			}
			catch (...)
			{
				cout << "unknown error" << endl;
			}
			break;
		case 7:
			try
			{
				cancelFriendshipProcces(facebook);
				cout << endl;
				printMenu();
				cin >> input;
			}
			catch (...)
			{
				cout << "unknown error" << endl;
			}
			break;
		case 8:
			try
			{
				addFanToFanPageProcedure(facebook);
				printMenu();
				cin >> input;
			}
			catch (...)
			{
				cout << "unknown error" << endl;
			}
			break;

		case 9:
			try
			{
				removeFanFromFanPageProcedure(facebook);
				cout << endl;
				printMenu();
				cin >> input;
			}
			catch (...)
			{
				cout << "unknown error" << endl;
			}
			break;

		case 10:
			try
			{
				facebook.showAllEntities();
				cout << endl;
				printMenu();
				cin >> input;
			}
			catch (...)
			{
				cout << "unknown error" << endl;
			}
			break;

		case 11:
			try
			{
				showFriendsOrFans(facebook);
				cout << endl;
				printMenu();
				cin >> input;
			}
			catch (...)
			{
				cout << "unknown error" << endl;
			}

			break;
		case 12:
			cout << "exiting...";
			break;
		default:
			cout << "please enter one of options in the menu " << endl;
			cout << endl;
			printMenu();
			cin >> input;
			break;
		}
	}
}

void getDataFromFile(ifstream& readFile, Facebook& admin, bool& isEmptyFile)
{

	int numberOfMembers, numberOfFanpages;
	Date statusDate;
	Clock statusTime;
	if (readFile.peek() != std::ifstream::traits_type::eof())
	{
		readFile >> numberOfMembers;//get the number of members in facebook
		for (int i = 0; i < numberOfMembers; i++)// For each member: get his name and birth date and then add him to facebook
		{
			string memberName;
			Date memberBirthDate;
			readFile.ignore(1);
			getline(readFile, memberName, ',');
			getDateFromFile(readFile, memberBirthDate);
			admin.getAllMembersList().push_back(Member(memberName, memberBirthDate));
		}
		readFile >> numberOfFanpages;// get the number of fan pages in facebook
		readFile.ignore(1);
		for (int i = 0; i < numberOfFanpages; i++)//For each fan page : get his name and add him to facebook
		{
			string pageName;
			getline(readFile, pageName);
			admin.getAllFanPagesList().push_back(FanPage(pageName));
		}

		//Add more members details and connect between frineds.
		int numOfFriends, friendIndexInList, numOfStatuses;
		list<Member>::iterator itr = admin.getAllMembersList().begin();//using iterator to run on the list.
		for (int i = 0; i < numberOfMembers; i++)//Add data for each memebr: his friends and his statuses.
		{
			string str, friendName;
			getline(readFile, str);
			readFile >> numOfFriends; // 
			readFile.ignore(1);
			for (int k = 0; k < numOfFriends; k++)// for each frind of the cureent memebr, we connect
			{
				getline(readFile, friendName);
				friendIndexInList = getIndex(admin.getAllMembersList(), friendName);//get the indes of the memebr from the list
				admin.connectMembers(i, friendIndexInList, true);
			}

			readFile >> numOfStatuses;//get the number of statuses of the member
			readFile.ignore(1);
			for (int j = 0; j < numOfStatuses; j++) //for each status: get his type, date and time
			{
				string statusType;
				string text;
				string anotherField;
				getline(readFile, statusType);
				getline(readFile, text);

				getDateFromFile(readFile, statusDate);
				readFile.ignore(1);
				getstatusTimeFromFile(readFile, statusTime);
				readFile.ignore(1);
				if (statusType == typeid(TextStatus).name())
				{
					itr->getStatusesPtrVector().push_back(new TextStatus(text, statusDate, statusTime));
				}
				else
				{
					getline(readFile, anotherField);
					if (statusType == typeid(VideoStatus).name())
					{
						itr->getStatusesPtrVector().push_back(new VideoStatus(text, anotherField, statusDate, statusTime));
					}
					else//if (statusType == typeid(ImageStatus).name())
					{
						itr->getStatusesPtrVector().push_back(new ImageStatus(text, anotherField, statusDate, statusTime));
					}
				}

			}

			++itr;// end of loop, continue to the next member.

		}

		list<FanPage>::iterator itrPage = admin.getAllFanPagesList().begin();
		for (int fanPageIndex = 0; fanPageIndex < numberOfFanpages; fanPageIndex++)//Add data to the fan pages
		{

			int numOfFans, memberIndex, numOfStatuses;
			string str;
			getline(readFile, str);
			readFile >> numOfFans;
			readFile.ignore(1);
			for (int k = 0; k < numOfFans; k++)//add the fans of each page
			{
				getline(readFile, str);
				memberIndex = getIndex(admin.getAllMembersList(), str);
				admin.addNewFanToFanPage(fanPageIndex, memberIndex);
			}

			readFile >> numOfStatuses;
			readFile.ignore(1);
			for (int j = 0; j < numOfStatuses; j++)// add for each page his statuses
			{
				string statusType;
				string text;
				string anotherField;
				getline(readFile, statusType);
				getline(readFile, text);
				getDateFromFile(readFile, statusDate);
				readFile.ignore(1);
				getstatusTimeFromFile(readFile, statusTime);
				readFile.ignore(1);

				if (statusType == typeid(TextStatus).name())
				{
					itrPage->getStatusesPtrVector().push_back(new TextStatus(text, statusDate, statusTime));
				}
				else
				{
					getline(readFile, anotherField);
					if (statusType == typeid(VideoStatus).name())
					{
						itrPage->getStatusesPtrVector().push_back(new VideoStatus(text, anotherField, statusDate, statusTime));
					}
					else//if (statusType == typeid(ImageStatus).name())
					{
						itrPage->getStatusesPtrVector().push_back(new ImageStatus(text, anotherField, statusDate, statusTime));
					}
				}
			}

			++itrPage;
		}
	}
	else
	{
		isEmptyFile = true;
	}

		readFile.close();
}

void saveDataToFile(ofstream& writeFile, Facebook& admin)
{
	int numOfMembers = admin.getAllMembersList().size();
	int numOfFanpages = admin.getAllFanPagesList().size();
	writeFile << numOfMembers << endl;//print to the file the amount of members in facebook.
	{
		list<Member>::iterator itr = admin.getAllMembersList().begin();//using iterator to run on the list.
		list<Member>::iterator itrEnd = admin.getAllMembersList().end();
		for (; itr != itrEnd; ++itr)
		{
			writeFile << (*itr).getName() << "," << (*itr).getBirthDate() << endl;//print all the memebrs in facebook, name and birthdate for each member.
		}
	}

	{
		writeFile << numOfFanpages << endl;//print to the file the amount of fan pages in facebook.
		list<FanPage>::iterator itr = admin.getAllFanPagesList().begin();
		list<FanPage>::iterator itrEnd = admin.getAllFanPagesList().end();
		for (; itr != itrEnd; ++itr)
		{
			writeFile << (*itr).getName() << endl;//print all the fan pages in facebook.
		}
	}

	{
		list<Member>::iterator itr = admin.getAllMembersList().begin();//using iterator to run on the list.
		list<Member>::iterator itrEnd = admin.getAllMembersList().end();
		for (; itr != itrEnd; ++itr)
		{
			writeFile << *itr;//print each member into the file, deatils are: name, birthdate, list of friends, list of liked fan pages, list of statses.

		}
	}

	{
		list<FanPage>::iterator itr = admin.getAllFanPagesList().begin();
		list<FanPage>::iterator itrEnd = admin.getAllFanPagesList().end();
		for (; itr != itrEnd; ++itr)
		{
			writeFile << *itr;//print each fan page into the file, deatils are: name, list of fans

		}
	}
	writeFile.close();
}

int getIndex(std::list <Member>& lst, std::string& name)//This function searches a member in the list and returns his position
{
	list<Member>::iterator itr = lst.begin();
	list<Member>::iterator itrEnd = lst.end();
	int res= -1, i = 0;
	bool found = false;
	while (itr != itrEnd && found == false)
	{
		if (itr->getName() == name)
		{
			res = i;
			found = true;
		}
		i++;
		++itr;
	}
	return res;
}

void getDateFromFile(ifstream& readFile, Date& birthDate)
{
	short day, month, year;
	readFile >> day;
	readFile >> month;
	readFile >> year;


	birthDate.setDay(day);
	birthDate.setMonth(month);
	birthDate.setYear(year);
}

void getstatusTimeFromFile(ifstream& readFile, Clock& time)
{
	short hours, minutes, seconds;
	readFile >> hours;
	readFile >> minutes;
	readFile >> seconds;

	time.setHours(hours);
	time.setMinutes(minutes);
	time.setSeconds(seconds);
}
/*
void readStatusDataFromFile(ifstream& readFile, Facebook& admin, bool FanPageOrMembersStatuses) think how and is it possible to get
{

}
*/


