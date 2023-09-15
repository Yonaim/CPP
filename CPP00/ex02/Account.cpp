#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout
		<< " "
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created"
		<< std::endl;
}

Account::~Account( void )
{
	_nbAccounts--;
	_totalAmount -= this->_amount;
	_totalNbDeposits -= this->_nbDeposits;
	_totalNbWithdrawals -= this->_nbWithdrawals;

	_displayTimestamp();
	std::cout
		<< " "
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed"
		<< std::endl;
}

int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void Account::_displayTimestamp( void )
{
	char timestamp[18];
	time_t now;
	time(&now);

	std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S]", localtime(&now));
	std::cout << timestamp;
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout
		<< " "
		<< "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals
		<< std::endl;	
}

void Account::makeDeposit( int deposit )
{
	this->_nbDeposits++;
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout
		<< " "
		<< "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount - deposit << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_deposits:" << this->_nbDeposits
		<< std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout
		<< " "
		<< "index:" << this->_accountIndex << ";";

	if (this->_amount < withdrawal)
	{
		std::cout
			<< "p_amount:" << this->_amount << ";"
			<< "withdrawal:" << "refused"
			<< std::endl;
		return (false);
	}

	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout
		<< "p_amount:" << this->_amount + withdrawal << ";"
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals
		<< std::endl;
	return (true);
}

int Account::checkAmount( void ) const
{
	return (this->_amount);
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
		<< " "
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals
		<< std::endl;	
}
