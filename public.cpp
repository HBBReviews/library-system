//
//  public.cpp
//  library-management
//
//  Created by Charlie Jin on 5/21/21.
//  Copyright © 2021 Charlie Jin. All rights reserved.
//

// Find Library Material's Location Code [1], Check-Out/Return Library Materials [2], Log-In/Create Account [3]

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

bool openAccount(bool isAdmin);
void createAccount(bool isAdmin);
void changeAccountInfo(string username, bool isAdmin);
string addSpace(string str);

// Public User Function 1 // COMPLETE
string getLocationCode()
{
    cout << "\n----------\nGet Location Code - Public Function [1]\n";

    string tempTitle = "";
    string tempAuthor = "";
    string tempCode = "";

    string targetTitle = "";
    string targetAuthor = "";

    string locationCode = "";

    cout << "\nEnter Title of Desired Item With No Spaces: ";
    cin >> targetTitle;

    cout << "\nEnter Author of Desired Item With No Spaces: ";
    cin >> targetAuthor;

    ifstream myfile("catalog.txt");

    bool isItemFound = false;

    while (!isItemFound && myfile >> tempTitle >> tempAuthor >> tempCode)
    {
        if (tempTitle == targetTitle && tempAuthor == targetAuthor)
        {
            locationCode = tempCode;
            isItemFound = true;
        }
    }

    if (locationCode == "")
    {
        cout << "\n----------\nItem Not Found in Catalog\n";
    }
    else
    {
        cout << "\n----------\n" << tempTitle << " by " << tempAuthor << " Found at " << tempCode << endl;
    }

    return locationCode;
}

// Public User Function 2
void checkoutOrReturnItems()
{
    cout << "\n----------\nCheck-Out or Return Items - Public Function [2]\n";
}

// Log Into Account, Change Account Details, Delete Account  // COMPLETE
bool managePersonalAccount()
{
    string isAccountMade = "";
    string username = "";

    cout << "\nHave You Made an Account? [Y] or [N]: ";
    cin >> isAccountMade;

    if (isAccountMade == "n" || isAccountMade == "N")
    {
        createAccount(false);
    }
    else
    {
        openAccount(false);
        cout << "\nEnter Username Again Please: ";
        cin >> username;
        changeAccountInfo(username, false);
    }

    return false;
}