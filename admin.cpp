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
#include <Bits.h>

using namespace std;

// Functions Used from Other Files
void createAccount(bool isAdmin);
void changeAccountInfo(string username);
string addSpace(string str);
void manageAccount(bool isAdmin);

// Functions Defined in admin.cpp
bool addItems()
{
    cout << "\n----------\nAdd Items - Admin Function [1]\n";
    return false;
}

void removeItems()
{
    int n = 1;

    string tempTitle = "";
    string tempAuthor = "";
    string tempCode = "";

    string targetTitle = "";
    string targetAuthor = "";

    cout << "\nEnter Title of Desired Book With No Spaces: ";
    cin >> targetTitle;

    cout << "\nEnter Author of Desired Book With No Spaces: ";
    cin >> targetAuthor;

    ifstream myfile("catalog.txt");

    bool isItemFound = false;

    while (!isItemFound && myfile >> tempTitle >> tempAuthor >> tempCode)
    {
        if (tempTitle == targetTitle && tempAuthor == targetAuthor)
        {
            isItemFound = true;
        }
        else
        {
            n++;
        }
    }

    const char* file_name = "catalog.txt";

    cout << "\n----------\n" << n << "\n";

    cout << "\n----------\nRemove Items - Admin Function [2]\n";

    // open file in read mode or in mode
    ifstream is(file_name);

    // open file in write mode or out mode
    ofstream ofs;
    ofs.open("tempCatalog.txt", ofstream::out);

    // loop getting single characters
    char c;
    int line_no = 1;
    while (is.get(c))
    {
        // if a newline character
        if (c == '\n')
            line_no++;

        // file content not to be deleted
        if (line_no != n)
            ofs << c;
    }

    // closing output file
    ofs.close();

    // closing input file
    is.close();
}

void manageAdminAccounts()
{
    cout << "\n----------\nManage Accounts - Admin Function [3]\n";

    manageAccount(true);
}

bool checkAdmin()
{
    string isAccountMade = "";

    cout << "\nHave You Made an Account? [Y] or [N]: ";
    cin >> isAccountMade;

    if (isAccountMade == "n" || isAccountMade == "N")
    {
        createAccount(true);
    }
    else
    {
        manageAccount(true);
    }

    return false;
}