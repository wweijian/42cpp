#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	
	/* equip way too many */
		// tmp = src->createMateria("cure");
		// me->equip(tmp);
		// tmp = src->createMateria("cure");
		// me->equip(tmp);
		// tmp = src->createMateria("cure");
		// me->equip(tmp);

	/* unequipping */
		// tmp = (static_cast<Character *>(me))->getMateria(0);
		// me->unequip(0);
		// me->unequip(3); // item not given
		// delete tmp;

	/* using unequipped */
		// me->use(2, *bob);

	/* NULL materia */
		// std::cout << "HERE"<< std::endl;
		// src->learnMateria(NULL);
		// tmp = src->createMateria("hello");


	delete bob;
	delete me;
	delete src;
	return 0;
}