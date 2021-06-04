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

// Functions Used from Other Files
void createAccount(bool isAdmin);
void changeAccountInfo(string username, bool isAdmin);
string addSpace(string str);
bool openAccount(bool isAdmin);

void deleteFile(char fileName[20]);
void renameFile(char oldFileName[20], char newFileName[20]);

// Functions Defined in admin.cpp
bool addItems()
{
    cout << "\n----------\nAdd Items - Admin Function [1]\n";
    return false;
}

void removeItems() // COMPLETE
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

    myfile.close();

    const char* file_name = "catalog.txt";

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

    // Delete Old File with the Old Username
    char fileName[20];
    cout << "Enter Your Old File Name (catalog.txt): ";
    cin >> fileName;

    deleteFile(fileName); // Activate Only When tempCatalog Rename Function Has Been Accomplished

    // Rename tempCatalog to catalog.txt
    char oldFileName[20];
    cout << "Enter Your Old File Name Again (tempCatalog.txt): ";
    cin >> oldFileName;

    char newFileName[20];
    cout << "Enter Your New File Name Again (catalog.txt): ";
    cin >> newFileName;

    renameFile(oldFileName, fileName);
}

void manageAdminAccounts() // COMPLETE
{
    string tempName = "";
    int tempYear{ 0 };
    string tempUsername = "";
    string tempPassword = "";

    string targetUsername = "";
    string targetPassword = "";

    string accountName = "";

    cout << "\nEnter Username: ";
    cin >> targetUsername;

    cout << "\nEnter Password: ";
    cin >> targetPassword;

    ifstream myfile(targetUsername + ".txt");

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
        cout << "\n----------\nAccount Not Found. Let's Make an Account!\n";
        createAccount(true);
    }
    else
    {
        cout << "\n----------\nWelcome, " << addSpace(accountName) << "! Great to have you today!";
    }

    changeAccountInfo(targetUsername, true);
}

bool checkAdmin() // COMPLETE
{
    bool result = false;
    string isAccountMade = "";
    string adminPassword = "admin123";
    string tempAdminPassword = "";
    int numOfChecks = 3;

    for (int i = 0; i < numOfChecks; i++)
    {
        cout << "\nEnter Administration Password: ";
        cin >> tempAdminPassword;

        result = (tempAdminPassword == adminPassword);

        if (result)
        {
            i = 3;
        }
    }

    if (!result)
    {
        cout << "\nYou Have Incorrectly Inputted the Admin Password";
        return false;
    }

    cout << "\nHave You Made an Account? [Y] or [N]: ";
    cin >> isAccountMade;

    if (isAccountMade == "n" || isAccountMade == "N")
    {
        createAccount(result);
    }
    else
    {
        openAccount(result);
    }

    return result;
}