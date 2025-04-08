#include "Intern.hpp"

// Orthodox Canonical Form
Intern::Intern()
{
	std::cout << BOLD GREEN "Intern instance constructed." RESET << std::endl;
}

Intern::Intern(Intern const &src)
{
	std::cout << BOLD GREEN "Intern instance copy-constructed." RESET << std::endl;
	*this = src;
}

Intern &Intern::operator=(Intern const &src)
{
	(void)src;
	return *this;
}

Intern::~Intern()
{
	std::cout << BOLD MAGENTA "Intern instance destroyed." RESET << std::endl;
}

// Methods
AForm *Intern::createShrubberyForm(const std::string &target)
{
	std::cout << "Intern created Shrubbery Creation Form" << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomyRequestForm(const std::string &target)
{
	std::cout << "Intern created Robotomy Request Form" << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidentialPardonForm(const std::string &target)
{
	std::cout << "Intern created Presidential Pardon Form" << std::endl;
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm *(Intern::*formCreators[])(const std::string &) = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};
	for (int i = 0; i < 3; i++)
	{
		if (formNames[i].compare(formName) == 0)
			return (this->*formCreators[i])(target);
	}
	throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return BOLD RED "Error: Form not found." RESET;
}
