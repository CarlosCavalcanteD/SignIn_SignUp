#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

class Account
{
    public:
        // Public methods
        Account();
        void setName(std::string name);
        void setPassword(std::string password);
        std::string getName();
        std::string getPassword();

    private:
        // Private properties
        std::string name;
        std::string password;

};


/*
    Account() - Constructor method
*/
Account::Account()
{
    name = "NULL";
    password = "NULL";
}


/*
    setName() - SET method for string name
*/
void Account::setName(std::string name)
{
    this->name = name;
}


/*
    getName() - GET method for string name
*/
std::string Account::getName()
{
    return (this->name);
}


/*
    setPassword() - SET method for string password
*/
void Account::setPassword(std::string password)
{
    this->password = password;
}


/*
    getPassword() - GET method for string password
*/
std::string Account::getPassword()
{
    return (this->password);
}

#endif