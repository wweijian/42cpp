/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:19:33 by weijian           #+#    #+#             */
/*   Updated: 2025/09/21 21:35:28 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <stack>
#include <list>
#include <cctype>

#define	PRINT(os)	std::cout << os << std::endl;
#define	TRY(fn)		try {fn;} catch (std::exception &e) {PRINT(e.what());}

class RPN
{
	public:
	/* typedef */
		typedef std::stack<int, std::list<int> > t_stack;

	/* functions */
		static int	solve(std::string arg);
	
	private:
	/* functions */
		static bool		isSign(char c);
		static void		doOp(t_stack &stk, char c);

	/* useless constructors */
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
};
