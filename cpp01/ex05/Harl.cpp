/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 10:31:17 by weijian           #+#    #+#             */
/*   Updated: 2025/08/24 14:42:36 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/* constructors */

Harl::Harl()
{};

Harl::~Harl()
{}

const Harl::t_complaints Harl::_complaints[4] = {{DEBUG, &Harl::debug},
												{INFO, &Harl::info},
												{WARNING, &Harl::warning},
												{ERROR, &Harl::error}};

/* functions */

void	Harl::complain(std::string level)
{	
	for (int i = 0; i < 4; i++)
	{
		if (level == _complaints[i].level) {
			(this->*_complaints[i].f)();
			std::cout << std::endl;
			return ;
		}
	}
	confusion();
	std::cout << std::endl;
	return ;
}

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";	
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.";
}

void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";	
}

void	Harl::confusion()
{
	std::cout << "What am I supposed to be complaining about? I don't get it.";	
}

