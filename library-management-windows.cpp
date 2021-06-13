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

// Declare Functions in main.cpp
void introText();
string getUserType();
int getFunction();
void selectFunction(int functionNum, bool isAdmin);

bool openAccount(bool isAdmin);
void createAccount(bool isAdmin);
void changeAccountInfo(string username, bool isAdmin);

string addSpace(string str);
string removeSpace(string str);
bool checkIfSpace(string str);

void deleteFile(char fileName[20]);
void renameFile(char oldFileName[20], char newFileName[20]);

// Declare Functions in admin.cpp
bool addItems();
void removeItems();
void manageAdminAccounts();
bool checkAdmin();
void addItemToCatalogFile(string name, string author, string locCode);

// Declare Functions in public.cpp
string getLocationCode();
void checkoutOrReturnItems();
bool managePersonalAccount();

int main(int argc, const char* argv[]) // COMPLETE
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
        cout << "\n----------\nWelcome Administrator!\n";
        cout << "These are the functions you can do:\n";
        cout << "Add New Library Materials [1], Remove Library Materials [2], Manage Personal Account [3]\n";

        isAdmin = checkAdmin();
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

void introText() // COMPLETE
{
    cout << "Library Management System:\n";
    cout << "Developed by Charlie Jin\n\n";
}

string getUserType() // COMPLETE
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

int getFunction() // COMPLETE
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

void selectFunction(int functionNum, bool isAdmin) // COMPLETE
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
            manageAdminAccounts();
            break;
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

bool openAccount(bool isAdmin) // COMPLETE
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
        createAccount(isAdmin);
    }
    else
    {
        cout << "\n----------\nWelcome, " << addSpace(accountName) << "! Great to have you today!";
    }

    return true;
}

// COMPLETE
void createAccount(bool isAdmin)
{
    string name = "";
    string birthYear = "";
    string username = "";
    string password = "";

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
            if (isAdmin)
            {
                myfile << name << " " << birthYear << " " << username << " " << password << " " << "A";
            }
            else
            {
                myfile << name << " " << birthYear << " " << username << " " << password << " " << "U";
            }
            
            myfile.close();

            checkUserInfo = true;
        }
        else
        {
            cout << "Please Enter Your Details Again\nand Check for Errors.\n";
        }
    }
}

// Change Account Details, Delete Account // COMPLETE
void changeAccountInfo(string username, bool isAdmin)
{
    cout << "\n----------\nThese are the functions you can do:\n";
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
            cout << endl;

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
    string userType = "";

    if (isAdmin)
    {
        userType = "A";
    }
    else
    {
        userType = "U";
    }

    ifstream myfile(username + ".txt");
    myfile >> tempName >> tempYear >> tempUsername >> tempPassword;
    myfile.close();

    // Change Username // COMPLETE
    if (selectedFunction == 1)
    {
        string oldUsername = tempUsername;

        cout << "\nEnter New Username (No Longer than 10 Characters): ";
        cin >> username;

        // Check the Data to Make Sure It Fits
        if (username.length() <= 10)
        {
            cout << "Thank You for Updating Your Account\n";

            ofstream myfile;
            myfile.open(username + ".txt");
            myfile << tempName << " " << tempYear << " " << username << " " << tempPassword << userType;
            myfile.close();
        }
        else
        {
            cout << "Please Enter Your Details Again\nand Check for Errors.\n";
        }

        // Delete Old File with the Old Username
        char fileName[14];
        cout << "Enter Your Old Username Again (and the .txt File Extension): ";
        cin >> fileName;

        deleteFile(fileName);
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
            myfile << tempName << " " << tempYear << " " << username << " " << tempPassword << userType;
            myfile.close();
        }
        else
        {
            cout << "Please Enter Your Details Again\nand Check for Errors.\n";
        }
    }

    // Delete Account // COMPLETE
    else
    {
        char fileName[14];
        cout << "Enter Username Again (and the .txt File Extension): ";
        cin >> fileName;

        deleteFile(fileName);
    }
}

// Add Space to a String // COMPLETE
string addSpace(string str)
{
    string strNew = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (isupper(str[i]) != 0 && i != 0)
        {
            strNew += ' ';
        }

        strNew += str[i];
    }

    return strNew;
}

// Remove Space from a String // COMPLETE
string removeSpace(string str)
{
    string strNew = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            strNew += str[i];
        }
    }

    return strNew;
}

// Check if String Has a Space
bool checkIfSpace(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            return true;
        }
    }

    return false;
}

// Delete a File // COMPLETE
void deleteFile(char fileName[20])
{
    int status = 0;
    status = remove(fileName);

    if (status == 0)
    {
        cout << "\nFile Deleted Successfully!\n";
    }
    else
    {
        cout << "\nError Occurred!\n";
    }
}

void renameFile(char oldFileName[20], char newFileName[20]) // COMPLETE
{
    int status = rename(oldFileName, newFileName);

    if (status == 0)
    {
        cout << "\nFile Renamed Successfully!\n";
    }
    else
    {
        cout << "\nError Occurred!\n";
    }
}
