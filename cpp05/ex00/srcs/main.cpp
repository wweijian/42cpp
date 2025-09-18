#include "Bureaucrat.hpp"

void	basic()
{
	Bureaucrat	sally;
	Bureaucrat	bob("bob", 1);
	Bureaucrat	bobby(bob);
	Bureaucrat	dude = bob;

	std::cout << sally << std::endl;
	std::cout << bob << std::endl;
	std::cout << bobby << std::endl;
	std::cout << dude << std::endl;
}

void	invalid()
{
	try {
		Bureaucrat	guy("guy", 151);
	} catch (const std::exception &err) {
		std::cerr << "[ERROR] " << err.what() << std::endl;
	}
}

int main()
{
	basic();
	invalid();
}