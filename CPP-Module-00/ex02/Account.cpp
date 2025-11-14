#include "Account.hpp"
#include <iostream>
#include <ctime>


/*! @brief Static members must be defined and initialized outside the class definition. */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
    std::time_t time_raw = time(NULL);
    std::tm* time_info = localtime(&time_raw);
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "[%Y%M%d_%H%M%S] ", time_info);
    std::cout << buffer;
}


/*! @brief the Constructor public methode */
Account::Account(int initial_deposit) :
 _accountIndex(Account::_nbAccounts), _amount(initial_deposit), 
_nbDeposits(0), _nbWithdrawals(0)
{
    Account::_nbAccounts++;

    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
    << "amount:" << _amount << ";"
    << "created" << std::endl;
}

/*! @brief the Constructor private methode */
Account::Account(){

}

// int Account::getNbAccounts()
// {

// }

// void Account::displayAccountsInfos()
// {

// }

Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
    << "amount:" << this->_amount << ";"
    << "closed" << std::endl;
}