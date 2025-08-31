/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 10:31:17 by weijian           #+#    #+#             */
/*   Updated: 2025/08/25 13:57:30 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/* constructors */

Harl::Harl()
{};

Harl::~Harl()
{}

/* functions */

void	Harl::complain(std::string level)
{	
	if (level == DEBUG || level == INFO || level == WARNING || level == ERROR)
	{
		switch(level.at(0)) {
			case 'D':
				debug();
			case 'I':
				info();
			case 'W':
				warning();
			case 'E':
				error();
		}
	}
	else
		gibberish();
}

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
	std::cout << std::endl;
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";	
	std::cout << std::endl;
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.";
	std::cout << std::endl;
}

void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";	
	std::cout << std::endl;
}

void	Harl::gibberish()
{
	std::cout << "[ Probably complaining about insignificant problems ]";
	std::cout << std::endl;
}

