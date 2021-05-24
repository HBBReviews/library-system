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

void createAccount();
void changeAccountInfo(string username);

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
bool checkoutOrReturnItems()
{
    cout << "\n----------\nCheck-Out or Return Items - Public Function [2]\n";

    return false;
}

// Log Into Account, Change Account Details, Delete Account
bool managePersonalAccount()
{
    string isAccountMade = "";

    cout << "\nHave You Made an Account? [Y] or [N]: ";
    cin >> isAccountMade;

    if (isAccountMade == "n" || isAccountMade == "N")
    {
        createAccount();
    }
    else
    {
        string tempName = "";
        int tempYear { 0 };
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
            createAccount();
        }
        else
        {
            cout << "\n----------\nWelcome, " << accountName << "! Great to have you today!";
            changeAccountInfo(targetUsername);
        }
    }

    return false;
}

// COMPLETE
void createAccount()
{
    string name = "";
    string birthYear = "";
    string username = "";
    string password = "";

    bool isNewAdmin = false;
    bool checkUserInfo = false;

    // Ensures Correct Data Type is Obtained from the User
    while (!checkUserInfo)
    {
        cout << "\nEnter Name: ";
        cin >> name;

        cout << "\nEnter Year of Birth: ";
        cin >> birthYear;

        cout << "\nEnter New Username (No Longer than 10 Characters): ";
        cin >> username;

        cout << "\nEnter New Password (No Longer than 10 Characters): ";
        cin >> password;

        // Check the Data for userType
        if (username.length() <= 10 && password.length() <= 10)
        {
            cout << "Thank You for Creating a New Account\n";

            ofstream myfile;
            myfile.open(username + ".txt");
            myfile << name << " " << birthYear << " " << username << " " << password;
            myfile.close();

            checkUserInfo = true;
        }
        else
        {
            cout << "Please Enter Your Details Again\nand Check for Errors.\n";
        }
    }
}

// Change Account Details, Delete Account
void changeAccountInfo(string username)
{
    cout << "\n----------\nThese are the functions you can do:\n";
    cout << username << "\n";
    cout << "Change Username [1], Change Password [2], Delete Account [3]\n";

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

    // Write the Old Data to These Variables
    string tempName = "";
    string tempYear = "";
    string tempUsername = "";
    string tempPassword = "";

    ifstream myfile(username + ".txt");
    myfile >> tempName >> tempYear >> tempUsername >> tempPassword;

    // Change Username
    if (selectedFunction == 1)
    {
        cout << "\nEnter New Username (No Longer than 10 Characters): ";
        cin >> username;

        // Check the Data to Make Sure It Fits
        if (username.length() <= 10)
        {
            cout << "Thank You for Updating Your Account\n";

            ofstream myfile;
            myfile.open(username + ".txt");
            myfile << tempName << " " << tempYear << " " << username << " " << tempPassword;
            myfile.close();
        }
        else
        {
            cout << "Please Enter Your Details Again\nand Check for Errors.\n";
        }

        // STILL in PROGRESS
        // Delete Old File with the Old Username
    }

    // Change Password // COMPLETE
    else if (selectedFunction == 2)
    {
        cout << "\nEnter New Password (No Longer than 10 Characters): ";
        cin >> tempPassword;

        // Check the Data to Make Sure It Fits
        if (tempPassword.length() <= 10)
        {
            cout << "Thank You for Updating Your Account\n";

            ofstream myfile;
            myfile.open(username + ".txt");
            myfile << tempName << " " << tempYear << " " << username << " " << tempPassword;
            myfile.close();
        }
        else
        {
            cout << "Please Enter Your Details Again\nand Check for Errors.\n";
        }
    }

    // Delete Account
    else
    {
        // STILL in PROGRESS

        if (remove("campeaj.txt") != 0)
            perror("Error deleting file");
        else
            puts("File successfully deleted");
    }
}