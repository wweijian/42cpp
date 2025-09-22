/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:25:03 by weijian           #+#    #+#             */
/*   Updated: 2025/09/22 12:43:11 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* usless constructors */
ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& sc)
{ (void) sc; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& sc)
{ (void) sc; return (*this);}

ScalarConverter::~ScalarConverter()
{}

/* functions */

bool	ScalarConverter::isChar(std::string const & str)
{
	return (str.size() == 3 && *str.begin() == '\'' && *(str.end() - 1) == '\'');
}

bool	ScalarConverter::isCharRange(int const & i)
{
	return (i >= 0 && i <= 126);
}

bool	ScalarConverter::isDigit(int const & i)
{
	return (i >= '0' && i <= '9');
}

bool	ScalarConverter::isSign(int const & i)
{
	return (i == '-' || i == '+');
}

bool	ScalarConverter::isDisplayableChar(int const & i)
{
	return (i >= 32 && i <= 126);
}

bool	ScalarConverter::isInt(std::string const & str)
{
	std::string::const_iterator i;

	for (i = str.begin(); i != str.end(); ++i) {
		if (isSign(*i)) {
			if (i != str.begin())
				return (false);
		}
		else if (!isDigit(*i))
			return(false);
	}
	try {
		long i = atol(str.c_str());
		if (i < INT_MIN || i > INT_MAX)
			throw std::out_of_range("outside of integer limits");
	} catch (std::exception &err) {
		return (false);
	}
	return (true);
}

ScalarConverter::_type	ScalarConverter::isFloatOrDouble(std::string const & str)
{
	std::string::const_iterator	i;
	int							dot = 0;
	int							e = 0;
	int							f = 0;

	i = str.begin();
	while (i != str.end()) {
		if (*i == '.') {
			if (i == str.begin()) 
				return (NONE);
			dot = i - str.begin();
			i++;
			break ;
		}
		else if (isSign(*i)) {
			if (i != str.begin() || *(i + 1) == '.')
				return (NONE);
		}
		else if (!isDigit(*i))
			return(NONE);
		i++;
	}
	if (!isDigit(str[dot + 1]) || dot == 0)
		return (NONE);
	while (i != str.end()) {
		if (*i == 'e') {
			if (e == 1 || !isSign(*(++i)) 
				|| (isSign(str[0]) && str[2] != '.') 
				|| (!isSign(str[0]) && str[1] != '.'))
				return (NONE);
			e = 1;
		}
		else if (*i == 'f') {
			if (i + 1 != str.end())
				return (NONE);
			f = 1;
			break ;
		}
		else if (!isDigit(*i))
			return (NONE);
		i++;
	}
	if (f)
		return(FLOAT);
	else
		return (DBL);
}


bool	ScalarConverter::isPseudoLiteral(std::string const & str)
{
	return (str == "-inf" || str == "+inf" || str == "nan" || str == "-inff" || str == "+inff");
}

ScalarConverter::_type	ScalarConverter::checkType(std::string const & str)
{
	if (isPseudoLiteral(str))
		return (PSEUDO);
	if (isChar(str))
		return (CHAR);
	if (isInt(str))
		return (INT);
	return (isFloatOrDouble(str));
}

void	ScalarConverter::convertNone()
{
	std::cout	<< "invalid inputs.\n"
				<< "usage: ./convert <string> \n"
				<< "use C++ literals in its most common literal forms\n"
				<< "char  : 'c' \n"
				<< "int   : only digits within limits\n"
				<< "double: use a single decimal (up to 6 places), numbers only e.g. 0.0f, within limits\n"
				<< "float : use a single decimal (up to 6 places), use the letter f e.g. 0.0f, within limits\n"
				<< std::endl;
}

void	ScalarConverter::convertPseudo(std::string const & str)
{
	std::cout << "char  :  " << "impossible" << std::endl;
	std::cout << "int   :  " << "impossible" << std::endl;
	if (str == "nan") {
		std::cout << "double:  " << str << std::endl;
		std::cout << "float :  " << str << std::endl;
	}
	else if (str == "+inf") {
		std::cout << "double:  " << "+inff" << std::endl;
		std::cout << "float :  " << "+inf" << std::endl;		
	}
	else {
		std::cout << "double:  " << "-inff" << std::endl;
		std::cout << "float :  " << "-inf" << std::endl;
	}
	std::cout << std::endl;
}

void	ScalarConverter::convertChar(std::string const & str)
{
	char	c = str[1];

	std::cout << "(CHAR CONVERSION) input:  " << str << std::endl;
	CONV_CHAR (c);
	CONV_INT  (static_cast<int>(c));
	CONV_DBL  (static_cast<double>(c), ".0");
	CONV_FLOAT(static_cast<float>(c), ".0");
}

void	ScalarConverter::convertInt(std::string const & str)
{
	int		i = atoi(str.c_str());
	bool	frac = (str.size() < 7);

	std::cout << "(INT CONVERSION) input:  " << str << std::endl;
	displayChar(i);
	CONV_INT   (i);
	if (frac) {
		CONV_FLOAT (static_cast<float>(i), ".0");
		CONV_DBL   (static_cast<double>(i), ".0");
	}
	else {
		CONV_FLOAT (static_cast<float>(i), "");
		CONV_DBL   (static_cast<double>(i), "");
	}
}

double	ScalarConverter::stringToD(std::string const & str)
{
	std::istringstream	stream(str);
	double				d;

	stream >> d;
	return (d);
}

void	ScalarConverter::convertDouble(std::string const & str)
{
	double	i = stringToD(str);
	bool	frac = (i == std::floor(i) && str.size() < 7);

	std::cout << "(DOUBLE CONVERSION) input:  " << str << std::endl;
	displayChar(static_cast<int>(i));
	if (i >= INT_MIN && i <= INT_MAX)
		CONV_INT   (PRECISION_ERR);
	else
		CONV_INT   (OUT_OF_RANGE);
	if (frac) {
		CONV_FLOAT (static_cast<float>(i), ".0");
		CONV_DBL   (i, ".0");
	}
	else {
		CONV_FLOAT (static_cast<float>(i), "");
		CONV_DBL   (i, "");
	}
}

void	ScalarConverter::convertFloat(std::string const & str)
{
	float	i = atof(str.c_str());
	bool	frac = (i == std::floor(i) && str.size() < 7);

	std::cout << "(FLOAT CONVERSION) input:  " << str << std::endl;
	displayChar(static_cast<int>(i));
	if (i >= FLOAT_TO_INT_MIN && i <= FLOAT_TO_INT_MAX)
		CONV_INT   (static_cast<int>(i));
	else if (i >= INT_MIN && i <= INT_MAX)
		CONV_INT   (PRECISION_ERR);
	else
		CONV_INT   (OUT_OF_RANGE);
	if (frac) {
		CONV_FLOAT (i,".0");
		CONV_DBL   (static_cast<double>(i), ".0");
	}
	else {
		CONV_FLOAT (i,"");
		CONV_DBL   (static_cast<double>(i), "");
	}
}

void	ScalarConverter::displayChar(const int& i)
{
	if (isDisplayableChar(i))
		CONV_CHAR(static_cast<char>(i));
	else if (isCharRange(i))
		NO_DISPLAY;
	else
		std::cout << "char  :  " << "impossible" << std::endl;	
}

void	ScalarConverter::convert(std::string const & str)
{
	_type		type = checkType(str);

	switch (type) {
		case (NONE):
			return (convertNone());
		case (PSEUDO):
			return (convertPseudo(str));
		case (CHAR):
			return (convertChar(str));
		case (INT):
			return (convertInt(str));
		case (DBL):
			return (convertDouble(str));
		case (FLOAT):
			return (convertFloat(str));
		default :
			return ;
	}
}
