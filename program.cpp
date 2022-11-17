// Dependencies
#include <string>
#include <fstream>
#include <string.h>
#include <iostream>
#include "account.h"

// Using namespace
using namespace std;

// Prototypes
ifstream* openFile(void);
void closeFile(ifstream *file);
void readFile(ifstream* file, string *name, string *password);
bool isValid(Account *user, string name, string password);
void dataInput(string mode, string *name, string *password);



/*
    Main function
*/
int main(void)
{
    // Creating variables
    string name;
    string password;
    int attemps = 3;

    // Objects
    Account *user = new Account();
    ifstream *file = openFile();


    // Error, cannot open file
    if(!file->is_open())
    {
        // End program
        cout << "Error!" << endl;
        return (1);
    }


// SIGN UP
    // Data input for Sign Up
    dataInput("Sign Up", &name, &password);


// SIGN IN
    do
    {
        closeFile(file);
        file = openFile();

        // Data input for Sign In
        dataInput("Sign In", &name, &password);
        
        // Entering values through the set methods
        user-> setName(name);
        user-> setPassword(password);
      
        // Reading values from file
        readFile(file, &name, &password);


        // Sign In
        if(isValid(user, name, password))
        {
            cout << "User valid!" << endl;
        }
        else
        {
            cout << "Error, incorrect username or password!" << endl;
            cout << --attemps <<" times left" << endl;
        }
    }
    while(!(isValid(user, name, password)) && (attemps > 0));



    // End program
    closeFile(file);
    return (0);
}


/*
    isValid() - a boolean function to validate input data
*/
bool isValid(Account *user, string name, string password)
{
    // Making the variables constant to compare them with strcmp
    bool isNameValid = (strcmp(name.c_str(),user->getName().c_str()) == 0);
    bool isPasswordValid = (strcmp(password.c_str(),user->getPassword().c_str()) == 0);

    return (isNameValid && isPasswordValid);
}


/*
    openFile() - function to open file
*/
ifstream* openFile(void)
{

    // Creating object
     ifstream *file;

    // Opening the file
    file = new ifstream("file.txt");

    return (file);
}


/*
    readFile() - function to read file
*/
void readFile(ifstream *file, string *name, string *password)
{
    getline(*file, *name);
    getline(*file, *password);
}


/*
    closeFile() - function to close file
*/
void closeFile(ifstream *file)
{
    file->close();
}


/*
    dataInput() - procedure for entering name and password
*/
void dataInput(string mode, string *name, string *password)
{
    // If the data entry mode is to subscribe
    if(strcmp(mode.c_str(), "Sign Up") == 0)
    {
        // Inserting data into the file
        ofstream *file = new ofstream("file.txt");


        cout << endl;
        cout << "-----" << mode << "-----" << endl;

        // Name
        cout << "Name: ";
        cin >> *name;
        *file << *name;

        // Password
        *file << endl;
        cout << "Password: ";
        cin >> *password;
        *file << *password;
        cout << endl;

        file->close();
    }
    // If the data entry mode is to enter
    else
    {
        cout << endl;
        cout << "-----" << mode << "-----" << endl;
        cout << "Name: ";
        cin >> *name;
        cout << "Password: ";
        cin >> *password;
        cout << endl;
    }
}