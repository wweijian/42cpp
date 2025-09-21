/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:19:35 by weijian           #+#    #+#             */
/*   Updated: 2025/09/21 21:59:33 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN& other)
{
	(void) other;
}
RPN& RPN::operator=(const RPN& other)
{
	(void) other;
	return (*this);
}

RPN::~RPN()
{}

/* functions */

bool	RPN::isSign(char c)
{
	return (c == '*' || c == '+' || c == '/' || c == '-');
}

void	RPN::doOp(RPN::t_stack& stk, char c)
{
	if (stk.size() < 2)
		throw std::invalid_argument("insufficient operands at:  '" + std::string(1, c) + "'");
	int	n1 = stk.top();
	stk.pop();
	int n2 = stk.top();
	stk.pop();
	switch (c) {
		case ('*'): stk.push(n1 * n2); return;
		case ('/'): stk.push(n1 / n2); return;
		case ('+'): stk.push(n1 + n2); return;
		case ('-'): stk.push(n1 - n2); return;
	}
}

int	RPN::solve(std::string arg)
{
	t_stack stk;

	for (std::string::iterator it = arg.begin(); it != arg.end(); it++) {
		if (*it == ' ')
			continue ;
		else if (isdigit(*it)) {
			if (*(it + 1) != ' ' && it + 1 != arg.end())
				throw std::invalid_argument("unexpected token");
			stk.push(*it - '0');
		}
		else if (isSign(*it)) {
			doOp(stk, *it);
		}
		else
			throw std::invalid_argument("unexpected token");
	}
	if (stk.size() != 1)
		throw std::invalid_argument("too many operands");
	return (stk.top());
}