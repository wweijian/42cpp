/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:42:19 by weijian           #+#    #+#             */
/*   Updated: 2025/09/22 12:41:55 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

void characters()
{
	std::string input("");
	
	std::cout << "----- CHARS -----" << std::endl;
	ScalarConverter::convert("'a'");
	ScalarConverter::convert("'Z'");
	ScalarConverter::convert("'/'");
	ScalarConverter::convert("' '");
	
	/* invalid input*/
	// ScalarConverter::convert("");
	// ScalarConverter::convert("a");
}

void integers() 
{
	std::string input("");

	std::cout << "----- INT -----" << std::endl;
	ScalarConverter::convert("0");
	ScalarConverter::convert("2147483647");
	ScalarConverter::convert("+2147483647");
	ScalarConverter::convert("+2147483647");
	ScalarConverter::convert("-2147483648");
	ScalarConverter::convert("+48");
	ScalarConverter::convert("+2"); // char can't be displayed
}

void invalidInts()
{
	/* invalid input */
	std::cout << "-----INVALID INT -----" << std::endl;
	ScalarConverter::convert("-2147483649");
	ScalarConverter::convert("2147483648");
	ScalarConverter::convert("21-47483648");
	ScalarConverter::convert("++2147483648");
}


void floats()
{
	std::cout << "----- FLOAT -----" << std::endl;
	ScalarConverter::convert("0.0f");
	ScalarConverter::convert("16777216.0f");	// just within precision limits
	ScalarConverter::convert("1.67772e+7f");	// just within precision limits
	ScalarConverter::convert("2147483647.0f");	// int precision error
	ScalarConverter::convert("2.147483e+10f");	// int precision error
	ScalarConverter::convert("2147483648.1f");	// int out of bounds
	ScalarConverter::convert("16777216.0f");
	ScalarConverter::convert("+42.0f");
}

void invalidFloats()
{
	/* invalid inputs */
	std::cout << "-----INVALID FLOAT -----" << std::endl;
	ScalarConverter::convert("21.47483e+10f");	// malformed (too big)
	ScalarConverter::convert("3.40283e+38f");	// float max + 0.000001
	ScalarConverter::convert("-3.40283e+38f");	// float min -
	ScalarConverter::convert("340282f");		// no decimal
	ScalarConverter::convert("340282.f");		// no numbers after decimal
}

void invalidDoubles()
{
	/* invalid inputs */
	std::cout << "-----INVALID DOUBLE -----" << std::endl;
	ScalarConverter::convert("21.47483e+10");	// malformed (too big)
	ScalarConverter::convert("2.22507e-308");	// too big
	ScalarConverter::convert("1.79769e+309");	// too big
	ScalarConverter::convert("2.22507e-309");	// ttoo small
	ScalarConverter::convert("-1.79769e+309");	// double lowest
	ScalarConverter::convert("340282.");		// no numbers after decimal
}

void doubles()
{
	std::cout << "----- DOUBLE -----" << std::endl;
	ScalarConverter::convert("0.0");
	ScalarConverter::convert("2147483647.0");
	ScalarConverter::convert("2147483647.99999");	// truncation
	ScalarConverter::convert("2147483648.0");
	ScalarConverter::convert("2.22507e-300");		//double min ish
	ScalarConverter::convert("1.79769e+308");		//double max
	ScalarConverter::convert("2.22507e-300");		//double min ish
	ScalarConverter::convert("-1.79769e+308");		//double lowest
	ScalarConverter::convert("16777216.0");
	ScalarConverter::convert("+42.0");
}

void pseudo()
{
	std::cout << "----- PSEUDO -----" << std::endl;
	ScalarConverter::convert("nan");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("-inff");
}

void tests()
{
	// characters();
	// integers();
	// invalidInts();
	// floats();
	// invalidFloats();
	// doubles();
	// invalidDoubles();
	pseudo();
}

int main(int ac, char **av)
{
	if (ac > 2) {
		std::cout << "usage: ./convert <string>" << std::endl;
		return (1);
	}
	std::cout << std::setprecision(10);
	if (ac == 2)
		ScalarConverter::convert(av[1]);
	else 
		tests();
	// ScalarConverter thing; // cannot be initialized
}
