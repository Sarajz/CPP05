/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:19:29 by sarajime          #+#    #+#             */
/*   Updated: 2025/09/09 19:52:04 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Intern.hpp>

Intern::Intern()
{}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{}

AForm* shrubberyCreate(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm* robotomyCreate(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm* presidentialCreate(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
	std::string formNames[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	
	AForm* (*formCreators[3])(const std::string &target) = 
	{
		&shrubberyCreate,
		&robotomyCreate,
		&presidentialCreate
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}
	throw std::runtime_error ("Form name " + formName + " not recognized");
}