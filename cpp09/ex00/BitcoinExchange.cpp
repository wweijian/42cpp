/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 07:41:25 by weijian           #+#    #+#             */
/*   Updated: 2025/09/21 14:13:36 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	loadExchangeRates();
	// for (mapIt it = _exchangeRates.begin(); it != _exchangeRates.end(); it++) {
	// 	std::cout << it->first << "  =>  " << it->second << std::endl;
	// } // print if needed
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
		: _exchangeRates(other._exchangeRates)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other) {
		delete this;
		new (this) BitcoinExchange(other);
	}
	return (*this);
}

/* static const variables */
const std::string	BitcoinExchange::_databaseName("data.csv");

BitcoinExchange::~BitcoinExchange()
{}

/* functions */
bool	BitcoinExchange::validDate(std::string line, int n)
{
	int		year(std::stoi(line));
	int		month(std::stoi(line.substr(4)));
	int		day(std::stoi(line.substr(8)));
	bool	leap = (year % 4 == 0);
	int		totalDays = 31;

	if (month > 12)
		return false;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		totalDays--;
	else if (month == 2)
		totalDays = 28 + leap;
	if (day > totalDays)
		throw LineError("bad date format : " + line, n);
	if (year > 2025)
		throw LineError("date after 2024-12-31 : " + line, n);
	return (true);
}

// YYYY - MM - DD ,  0
// 0123 4 56 7 89 10 11
std::string	BitcoinExchange::getKey(std::string line, int n)
{	
	if (line.size() < 12)
		throw LineError("malformed line", n);
	for (int i = 0; i < 11; i++) {
		if ((i == 4 || i == 7)) {
			if (line[i] != '-')
				throw LineError("missing '-' where expected", n);
		}
		else if (i < 10) {
			if (!isdigit(line[i]))
				throw LineError("missing digit where expected", n);
		}
		else {
			if (line[i] != ',')
				throw LineError("missing ',' where expected", n);
		}
	}
	std::string date(line.substr(0, 9));
	if(validDate(line.substr(0, 9), n))
		return (date);
	else
		throw LineError("bad date format : " + date, n);
}

float	BitcoinExchange::getValue(std::string line, int n)
{
	line = line.substr(11);
	for (lineIt it = line.begin(); it != line.end(); it++) {
		if (!isdigit(*it) && *it != '.')
			throw LineError("malformed exchange rate", n);
	}
	try {
		return (std::stof(line));
	} catch (std::exception &err) {
		throw LineError("malformed exchange rate", n);
	}
}

void	BitcoinExchange::loadExchangeRates()
{
	std::string		line;
	std::string		key;
	int				value;
	std::ifstream	exchangeRates(_databaseName);

	if (!exchangeRates.is_open())
		throw CannotOpenDatabase();
	std::getline(exchangeRates, line);
	for (int i = 2; std::getline(exchangeRates, line); i++) {
		TRY(_databaseName, key = getKey(line, i); value = getValue(line, i); _exchangeRates.insert(std::make_pair(key, value)))
	}
}

// YYYY - MM - DD ' ' | ''   x
// 0123 4 56 7 89 10  11 12 13
void	BitcoinExchange::printConversions(std::string line, int n)
{
	if (line.size() < 14 || (line[11] != '|' && line[12] != ' '))
		throw LineError("bad input", n);
	std::string date(line.substr(0, 10));
	if (!validDate(date, n))
		throw LineError("bad date format", n);
	line = line.substr(13);
	for (lineIt it = line.begin(); it != line.end(); it++) {
		if (!isdigit(*it)) {
			if (it == line.begin() && *it == '-')
				throw LineError("positive value only", n);
			throw LineError("bad value", n);
		}
	}
	int value;
	try {
		value = std::stoi(line);
	} catch (std::exception &err) {
		throw LineError("value too large", n);
	}
	mapIt	it = _exchangeRates.lower_bound(date);
	float	rate;
	if (it->first == date)
		rate = it->second;
	else if (it != _exchangeRates.begin())
		rate = (--it)->second;
	else
		throw LineError("date before earliest date : " + date, n);
	std::cout << date << " => " << value << " * " << rate << " = " <<  value * rate << std::endl;
}

void	BitcoinExchange::evaluatePositions(std::string fileName)
{
	std::string		line;
	std::ifstream	readFile(fileName);

	if (!readFile)
		throw std::invalid_argument(fileName + "cannot be opened");
	std::getline(readFile, line);
	if (line.compare(DATE_VALUE_FORMAT) != 0)
		throw LineError(fileName + ": unknown header" , 1);
	for (int i = 2; std::getline(readFile, line); i++) {
		TRY(fileName, printConversions(line, i));
	}
}

/* exceptions */
const char * BitcoinExchange::CannotOpenDatabase::what() const throw()
{
	return ("BitcoinExchange : database cannot be opened");
}

BitcoinExchange::LineError::LineError(std::string error, int line)
		:	_errorMsg("[ERROR] line " + std::to_string(line) + " : " + error)
{}

BitcoinExchange::LineError::~LineError() throw ()
{}

const char * BitcoinExchange::LineError::what() const throw()
{
	return (_errorMsg.c_str());
}


