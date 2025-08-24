/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 17:45:19 by weijian           #+#    #+#             */
/*   Updated: 2025/08/24 09:55:53 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream> 
#include <sstream>

/* 
	streams have to be passed by reference because all stream types in C++ are
	not copyable. therefore we are not copying the stream we are referencing it 

	files destructors are also automatically called on program completion
	which will close the files automatically

	std::string::npos = not found
*/

void	substituteString(std::string &buffer, const std::string &s1, const std::string &s2)
{
	std::size_t idx(0);
	while ((idx = buffer.find(s1, idx)) != std::string::npos) {
		buffer.erase(idx, s1.length());
		buffer.insert(idx, s2);
		idx += s2.length();
	}
}

std::string	createBufferString(std::ifstream &infile)
{
	std::stringstream	bufferStream;
	std::string			bufferString;
	bufferStream << infile.rdbuf();
	bufferString = bufferStream.str();
	infile.close();
	return (bufferString);
}

int	main (int ac, char **av)
{
	if (ac != 4)
		return (1);

	std::ifstream infile(av[1]);
	if (!infile.is_open())
		return (1);
	std::ofstream outfile(std::string(av[1]).append(".replace"));	
	if (!outfile.is_open())
		return (1);

	std::string		s1(av[2]);
	std::string		s2(av[3]);
	std::string		buffer(createBufferString(infile));
	
	if (buffer.empty())
		return (0);
	substituteString(buffer, s1, s2);
	outfile << buffer;
	return (0);
}
