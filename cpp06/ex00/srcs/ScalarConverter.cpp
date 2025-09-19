/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:25:03 by weijian           #+#    #+#             */
/*   Updated: 2025/09/19 13:07:23 by weijian          ###   ########.fr       */
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
	return (str.size() == 3 && str.front() == '\'' && str.back() == '\'');
}

bool	ScalarConverter::isCharRange(int const & i)
{
	return (i >= 0 && i <= 126);
}

bool	ScalarConverter::isDisplayableChar(int const & i)
{
	return (i >= 32 && i <= 126);
}

bool	ScalarConverter::isPseudoLiteral(std::string const & str)
{
	return (str == "-inf" || str == "+inf" || str == "nan");
}

void	ScalarConverter::convert(std::string const & str)
{
	convertToChar(str);
	convertToInt(str);
	convertToFloat(str);
	convertToDouble(str);
}

void	ScalarConverter::convertToChar(std::string const & str)
{
	int	var;

	std::cout << "char  :  " << std::flush;
	if (isChar(str)) {
		std::cout << str << std::endl;
		return ;
	}
	if (isPseudoLiteral(str)) {
		std::cout << "impossible" << std::endl;
		return ;
	}
	try {
		var = std::stoi(str);
		if (isDisplayableChar(var))
			std::cout << "'" << static_cast<char>(var) << "'" << std::endl;
		else if (isCharRange(var)) 
			std::cout << "not displayable" << std::endl;
		else
			std::cout << "impossible" << std::endl;
	} catch (std::exception &err) {
		std::cerr << err.what() << std::endl;
	}
}

void	ScalarConverter::convertToInt(std::string const & str)
{
	int	var;

	std::cout << "int   :  " << std::flush;
	if (isChar(str)) {
		std::cout << static_cast<int>(str[1]) << std::endl;
		return ;
	}
	if (isPseudoLiteral(str)) {
		std::cout << "impossible" << std::endl;
		return ;
	}
	try {
		var = std::stoi(str);
		std::cout << var << std::endl;
	} catch (std::exception &err) {
		std::cerr << err.what() << std::endl;
	}
}

void	ScalarConverter::convertToFloat(std::string const & str)
{
	float	var;

	std::cout << "float :  " << std::flush;
	if (isChar(str)) {
		std::cout << static_cast<float>(str[1]) << ".0f" << std::endl;
		return ;
	}
	if (isPseudoLiteral(str)) {
		std::cout << str << std::endl;
		return ;
	}
	try {
		var = std::stof(str);
		std::cout << var << "f" << std::endl;
	} catch (std::exception &err) {
		std::cerr << err.what() << std::endl;
	}
}

void	ScalarConverter::convertToDouble(std::string const & str)
{
	double	var;

	std::cout << "double:  " << std::flush;
	if (isChar(str)) {
		std::cout << static_cast<double>(str[1]) << std::endl;
		return ;
	}
	if (isPseudoLiteral(str)) {
		std::cout << str << std::endl;
		return ;
	}
	try {
		var = std::stod(str);
		std::cout << var << std::endl;
	} catch (std::exception &err) {
		std::cerr << err.what() << std::endl;
	}
}
