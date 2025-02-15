/* ************************************************************************** */
/*                                                                            */
/*                Account.cpp for GlobalBanksters United                      */
/*                Created on  : Thu Nov 20 19:43:15 1989                      */
/*                Last update : Wed Jan 04 14:54:06 1992                      */
/*                By: Brad "Buddy" McLane <bm@gbu.com>                        */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

/*
  Static member variables must be defined outside the class.
*/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*
  The private default constructor is declared but not used in the tests.
  It’s good practice to define it (empty) to avoid linker errors.
*/
Account::Account(void) {
	/* This constructor should never be called directly. */
}

/*
  Parametric constructor
  Sets the account index, initial amount, and updates global stats.
  Also logs the creation.
*/
Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

	std::cout << "[";
	_displayTimestamp();
	std::cout << "] "
	          << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";created" << std::endl;
}

/*
  Destructor
  Logs the account closure (index & final amount).
*/
Account::~Account(void) {
	std::cout << "[";
	_displayTimestamp();
	std::cout << "] "
	          << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";closed" << std::endl;
}

/*
  Displays overall account information (static).
  E.g.: [timestamp] accounts:8;total:21524;deposits:8;withdrawals:0
*/
void Account::displayAccountsInfos(void) {
	std::cout << "[";
	_displayTimestamp();
	std::cout << "] "
	          << "accounts:" << getNbAccounts()
	          << ";total:" << getTotalAmount()
	          << ";deposits:" << getNbDeposits()
	          << ";withdrawals:" << getNbWithdrawals()
	          << std::endl;
}

/*
  Displays the status of a single account.
  E.g.: [timestamp] index:0;amount:42;deposits:0;withdrawals:0
*/
void Account::displayStatus(void) const {
	std::cout << "[";
	_displayTimestamp();
	std::cout << "] "
	          << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";deposits:" << _nbDeposits
	          << ";withdrawals:" << _nbWithdrawals
	          << std::endl;
}

/*
  Makes a deposit:
  - Prints the pre-deposit amount (p_amount),
  - Prints the deposit amount,
  - Updates the current amount, the number of deposits, and global counters,
  - Logs everything.

  Example log line:
    [timestamp] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
*/
void Account::makeDeposit(int deposit) {
	int p_amount = _amount;

	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;

	std::cout << "[";
	_displayTimestamp();
	std::cout << "] "
	          << "index:" << _accountIndex
	          << ";p_amount:" << p_amount
	          << ";deposit:" << deposit
	          << ";amount:" << _amount
	          << ";nb_deposits:" << _nbDeposits
	          << std::endl;
}

/*
  Makes a withdrawal:
  - Checks if there is enough balance to cover `withdrawal`,
  - If yes, updates amounts, logs, and returns true,
  - If not, logs "withdrawal:refused" and returns false.

  Example success log:
    [timestamp] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1

  Example failure log:
    [timestamp] index:0;p_amount:47;withdrawal:refused
*/
bool Account::makeWithdrawal(int withdrawal) {
	int p_amount = _amount;

	if (withdrawal <= _amount) {
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << "[";
		_displayTimestamp();
		std::cout << "] "
		          << "index:" << _accountIndex
		          << ";p_amount:" << p_amount
		          << ";withdrawal:" << withdrawal
		          << ";amount:" << _amount
		          << ";nb_withdrawals:" << _nbWithdrawals
		          << std::endl;
		return true;
	} else {
		std::cout << "[";
		_displayTimestamp();
		std::cout << "] "
		          << "index:" << _accountIndex
		          << ";p_amount:" << p_amount
		          << ";withdrawal:refused"
		          << std::endl;
		return false;
	}
}

/*
  Returns the current amount (used internally in tests).
*/
int Account::checkAmount(void) const {
	return _amount;
}

/*
  Below are the static getters returning the global (static) counters.
*/
int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

/*
  Displays a timestamp in the log. The exact format can vary, since
  the project states your timestamps will naturally differ.
  We replicate a format like [YYYYMMDD_HHMMSS] without trailing newline.
*/
void Account::_displayTimestamp(void) {
	std::time_t t = std::time(NULL);
	std::tm* now = std::localtime(&t);
	// Format: YYYYMMDD_HHMMSS
	std::cout << (now->tm_year + 1900)
	          << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
	          << std::setw(2) << std::setfill('0') << now->tm_mday
	          << "_"
	          << std::setw(2) << std::setfill('0') << now->tm_hour
	          << std::setw(2) << std::setfill('0') << now->tm_min
	          << std::setw(2) << std::setfill('0') << now->tm_sec;
}
