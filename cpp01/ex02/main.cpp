/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 09:42:11 by weijian           #+#    #+#             */
/*   Updated: 2025/08/25 13:42:28 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*	
	std::string *stringPTR = &str
	
	stringPTR is a pointer to str.

	It stores the memory address of str.
	
	You’d use it like:
	
	std::cout << *stringPTR;   // dereference, PRINTS THE STRING
	std::cout << stringPTR;    // prints the address of str
	
	std::string &stringREF = str
	stringREF is a reference (an alias) to str.
	It’s not a new object; it’s just another name for the same variable.
	You can use it as if it is str:
	std::cout << stringREF;    // prints the string
	
	Key difference
	
	Pointer: you can change it to point somewhere else later.
	Reference: once bound, it cannot be changed to refer to another object
*/

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << &str << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	std::cout << str << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}