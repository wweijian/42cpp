/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 07:41:17 by weijian           #+#    #+#             */
/*   Updated: 2025/09/21 13:55:36 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <map>

#define	PRINT(os) std::cout << os << std::endl
#define	TRY(name,fn) try {fn;} catch (std::exception &e) {PRINT(name << " : " << e.what());}
#define	DATE_VALUE_FORMAT "date | value"

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
	
	/* funcitons */
		void	evaluatePositions(std::string fileName);
	
	/* exceptions */
		class CannotOpenDatabase : public std::exception
		{
			const char * what() const throw();
		} ;
		class LineError : public std::exception
		{
			public:
				LineError(std::string error, int line);
				const char * what() const throw();
				~LineError() throw ();
			private:
				std::string		_errorMsg;
		} ;
		
	private:
	/* variables */
		std::map<std::string, float>	_exchangeRates;

	/* static const variables */
		static const std::string		_databaseName;

	/* type redefintion */
		typedef std::string::iterator					lineIt;
		typedef std::map<std::string, float>::iterator	mapIt;

	/* main functions */
		std::string	getKey(std::string line, int n);
		float		getValue(std::string line, int n);
		void		loadExchangeRates();
		void		printConversions(std::string line, int n);

	/* utilities */
		bool		validDate(std::string line, int n);
} ;
