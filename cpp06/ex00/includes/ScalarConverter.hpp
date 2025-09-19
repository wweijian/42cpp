/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:15:43 by weijian           #+#    #+#             */
/*   Updated: 2025/09/19 13:03:18 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

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
	/* conversion */
		static void		convertToChar(std::string const & str);
		static void		convertToInt(std::string const & str);
		static void		convertToFloat(std::string const & str);
		static void		convertToDouble(std::string const & str);
	
	/* booleans */
		static bool		isChar(std::string const & str);
		static bool		isCharRange(int const & i);
		static bool		isDisplayableChar(int const & i);
		static bool		isPseudoLiteral(std::string const & str);
} ;
