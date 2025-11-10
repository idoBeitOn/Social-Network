#include <iostream>
#pragma warning (disable : 4996)
using namespace std;
#include "facebook.h"
#include "Member.h"
#include "Date.h"
#include "fanPage.h"
#include "UserFunctions.h"

void newTerminate()
{
    std::cout << "unknown problem occured!!!!!!" << std::endl;
    exit(1);
}

int main()
{
    bool isEmptyFile = false;
    set_terminate(newTerminate);
    Facebook admin; // create Facebook object that houses all data in the system
    ifstream readFile("Data.txt", ios::in);//open data file for getting data into facebook
    getDataFromFile(readFile, admin, isEmptyFile);// get data from previous run
    enterHardCoddedDataToFacebook(admin, isEmptyFile);   // enter hard codded data into the system
    executeUserInterface(admin);    // activate the user interface for the system
    ofstream writeFile("Data.txt", ios::trunc);
    saveDataToFile(writeFile, admin);//Save data

}