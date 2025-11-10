#ifndef _USER_FUNCTIONS_H
#define _USER_FUNCTIONS_H

#include "facebook.h"
#include <iostream>


const Date getMemberBirthDateFromUser();//get the birth date of member from the user
const std::string getMemberNameFromUser(Facebook& admin); // get name of member from the user
const int getMemberIndexFromUser();//get index of a member from the user
const short getFanPageIndexFromUser();// get index of a fan page from the user
void getMemberIndicesFromUser(int* pIndex1, int* pIndex2, Facebook& admin);//get 2 indices of members from the user
void addNewMemberProcess(Facebook& admin)noexcept(false);//Adding new member to facebook system
void connectTwoMembersProcces(Facebook& admin)noexcept(false);//Create friendship between 2 members
void cancelFriendshipProcces(Facebook& admin)noexcept(false);//Cancel friendship between 2 members
void showFriendsOrFans(Facebook& admin)noexcept(false);//print friends of a specific member or fans of a specific fan page
void Show10RecentStatuses(Facebook& admin)noexcept(false);// print 10 most recent statuses of each friend of a specific member
void printFriendsStatuses(std::vector<Member*> friendsArr);//print the statuses of friends of a specific member
void addStatusToMemberProcedure(Facebook& admin)noexcept(false);//Add a new status to a member
void enterHardCoddedDataToFacebook(Facebook& facebook, bool isEmptyFile);//load hard coded data into the system
void printMenu();//print the menu of facebook
void addFanPageProcedure(Facebook& admin)noexcept(false);//add new fan page to facebook
void addStatusProcedure(Facebook& admin)noexcept(false);//add new status to the system(to member or to fan page)
void addStatusForFanPageProcedure(Facebook& admin)noexcept(false);//add a new status to a fan page
void addFanToFanPageProcedure(Facebook& admin)noexcept(false);// add a new fan to fan page
void removeFanFromFanPageProcedure(Facebook& admin)noexcept(false);//remove a fan from a specific fan page
void showStatusesProcedure(Facebook& admin)noexcept(false);//print status
void cleanBuffer();//cleaning the buffer
void executeUserInterface(Facebook& facebook);// function the manages the running of the program

std::string getStatusFromUser(); // function for getting status text from the user.

void getDataFromFile(std::ifstream& readFile, Facebook& admin, bool& isEmptyFile);
void saveDataToFile(std::ofstream& file, Facebook& admin);

int getIndex(std::list <Member>& lst, std::string& name);

void getDateFromFile(std::ifstream& readFile, Date& birthDate);

void getstatusTimeFromFile(std::ifstream& readFile, Clock& time);

//This class has the functions for interacting with the user and also functions used in the Main.cpp file
//These functions are running all the procedures in facebook.

#endif // !USER_FUNCTIONS_H



