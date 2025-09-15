/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 07:42:43 by weijian           #+#    #+#             */
/*   Updated: 2025/09/15 15:21:27 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "AMateria.hpp"

class IMateriaSource
{
	public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
} ;

class MateriaSource : public IMateriaSource
{
	public:
	MateriaSource();
	MateriaSource(MateriaSource &other);
	MateriaSource& operator=(MateriaSource &other);
	~MateriaSource();

	void 		learnMateria(AMateria* materia);
	AMateria*	createMateria(std::string const & type);
	
	private:
	AMateria*	_materiaSlot[4];
} ;