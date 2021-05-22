//
//  admin.cpp
//  library-management
//
//  Created by Charlie Jin on 5/21/21.
//  Copyright © 2021 Charlie Jin. All rights reserved.
//

// Add New Library Materials [1], Remove Library Materials [2], Manage Public Accounts [3]

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

bool addItems()
{
    cout << "\n----------\nAdd Items - Admin Function [1]\n";
    return false;
}

bool removeItems()
{
    cout << "\n----------\nRemove Items - Admin Function [2]\n";
    return false;
}

void manageAccounts()
{
    cout << "\n----------\nManage Accounts - Admin Function [3]\n";

    string tempName = "";
    string tempYear = "";
    string tempUsername = "";
    string tempPassword = "";

    string targetUsername = "";
    string targetPassword = "";

    string accountName = "";

    cout << "\nEnter Username: ";
    cin >> targetUsername;

    cout << "\nEnter Password: ";
    cin >> targetPassword;

    ifstream myfile("accounts.txt");

    bool isAccountFound = false;

    while (!isAccountFound && myfile >> tempName >> tempYear >> tempUsername >> tempPassword)
    {
        if (tempUsername == targetUsername && tempPassword == targetPassword)
        {
            accountName = tempName;
            isAccountFound = true;
        }
    }

    if (accountName == "")
    {
        cout << "\n----------\nAccount Not Found\n";
    }
    else
    {
        cout << "\n----------\n" << accountName << " is the Name and was born in " << tempYear << " and has the username " << tempUsername;
    }
}
