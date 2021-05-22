//
//  main.cpp
//  library-management
//
//  Created by Charlie Jin on 5/20/21.
//  Copyright © 2021 Charlie Jin. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

// Functionality: Add New Library Materials to Catalog

// Assign Materials a Location ID like the codes in a library

// Give the User the Location ID upon request

// Check-Out Library Materials

// Return Library Materials

// Account

// Book: Book Title, Book Author, Book Genre, Book Page Length

// Declare Functions in main.cpp
void introText();
string getUserType();
int getFunction();
void selectFunction(int functionNum, bool isAdmin);

// Declare Functions in admin.cpp
bool addItems();
bool removeItems();
void manageAccounts();

// Declare Functions in public.cpp
string getLocationCode();
bool checkoutOrReturnItems();
bool managePersonalAccount();

int main(int argc, const char* argv[])
{
    // Member Variables
    string typeUser = "";
    bool isAdmin = false;
    bool isPublicUser = false;
    int function = 0;

    // Introductory Text
    introText();

    // Get User Type from User
    typeUser = getUserType();

    if (typeUser == "A" || typeUser == "a")
    {
        isAdmin = true;

        cout << "\n----------\nWelcome Administrator!\n";
        cout << "These are the functions you can do:\n";
        cout << "Add New Library Materials [1], Remove Library Materials [2], Manage Public Accounts [3]";
    }
    else if (typeUser == "P" || typeUser == "p")
    {
        isPublicUser = true;

        cout << "\n----------\nWelcome Public User!\n";
        cout << "These are the functions you can do:\n";
        cout << "Find Library Material's Location Code [1], Check-Out/Return Library Materials [2], Log-In/Create Account [3]\n";
    }

    function = getFunction();
    selectFunction(function, isAdmin);

    return 0;
}

void introText()
{
    cout << "Library Management System:\n";
    cout << "Developed by Charlie Jin\n\n";
}

string getUserType()
{
    string userType = "";
    bool checkUserType = false;

    // Ensures Correct Data Type is Obtained from the User
    while (!checkUserType)
    {
        cout << "Select User Type (Admin [A] or Public [P]): ";
        cin >> userType;

        // Check the Data for userType
        if (userType == "A" || userType == "P" || userType == "a" || userType == "p")
        {
            cout << "Thank You for Entering Correct Data\n";
            checkUserType = true;
        }
        else
        {
            cout << "Please Enter in a Proper Response.\n";
        }
    }

    return userType;
}

int getFunction()
{
    int selectedFunction = 0;
    bool checkFunction = false;

    // Ensures Correct Data Type is Obtained from the User
    while (!checkFunction)
    {
        cout << "\n\nSelect Function ([1], [2], or [3]): ";
        cin >> selectedFunction;

        // Check the Data for userType
        if (selectedFunction >= 1 && selectedFunction <= 3)
        {
            cout << "Thank You for Entering Correct Data\n";

            checkFunction = true;
        }
        else
        {
            cout << "Please Enter in a Proper Response.\n";
        }
    }

    return selectedFunction;
}

void selectFunction(int functionNum, bool isAdmin)
{
    if (isAdmin)
    {
        switch (functionNum) {
        case 1:
            addItems();
            break;
        case 2:
            removeItems();
            break;
        case 3:
            manageAccounts();

        default:
            break;
        }
    }
    else
    {
        switch (functionNum) {
        case 1:
            getLocationCode();
            break;
        case 2:
            checkoutOrReturnItems();
            break;
        case 3:
            managePersonalAccount();
            break;
        default:
            break;
        }
    }
}
