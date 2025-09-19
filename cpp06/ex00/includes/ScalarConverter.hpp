/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:15:43 by weijian           #+#    #+#             */
/*   Updated: 2025/09/19 18:14:36 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <limits>

#define	CONV_CHAR(os)			std::cout << "char  :  '" << os << "'" << std::endl
#define	CONV_INT(os)			std::cout << "int   :  " << os << std::endl
#define	CONV_DBL(os, frac)		std::cout << "double:  " << os << frac << "\n" << std::endl
#define	CONV_FLOAT(os, frac)	std::cout << "float :  " << os << frac << "f" << std::endl
#define NO_DISPLAY				std::cout << "char  :  " << "non-displayable"<< std::endl
#define OUT_OF_RANGE			"out of range"
#define PRECISION_ERR			"precision error"
#define FLOAT_TO_INT_MAX		16777216
#define FLOAT_TO_INT_MIN		-16777216


class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& sc);
		ScalarConverter& operator=(const ScalarConverter& sc);
		~ScalarConverter();

		static void		convert(std::string const & str);
		virtual void	dummy() = 0;
	
	private:
	/* enum */
		typedef enum e_type {
			NONE,
			PSEUDO,
			CHAR,
			INT,
			DBL,
			FLOAT,
			TYPE_TOTAL
		} _type;
	
	/* functions */
		static enum e_type	checkType(std::string const & str);
		static void			convertNone();
		static void			convertPseudo(std::string const & str);
		static void			convertChar(std::string const & str);
		static void			convertInt(std::string const & str);
		static void			convertDouble(std::string const & str);
		static void			convertFloat(std::string const & str);
		static void			displayChar(const int& i);

	/* booleans */
		static bool			isChar(std::string const & str);
		static bool			isInt(std::string const & str);
		static _type		isFloatOrDouble(std::string const & str);
		
		static bool			isDigit(int const & i);
		static bool			isSign(int const & i);
		static bool			isCharRange(int const & i);
		static bool			isDisplayableChar(int const & i);
		static bool			isPseudoLiteral(std::string const & str);

} ;
