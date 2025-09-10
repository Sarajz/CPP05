/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:12:41 by sarajime          #+#    #+#             */
/*   Updated: 2025/09/03 20:15:42 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

int main()
{
	try
	{
		Bureaucrat jess("Jess", 1);
		Bureaucrat jane("Jane", 150);

		ShrubberyCreationForm shrubbery("Home");
		RobotomyRequestForm robotomy("Bender");
		PresidentialPardonForm pardon("Alice");

		std::cout << jess << std::endl;
		std::cout << jane << std::endl;

		jess.signForm(shrubbery);
		jess.executeForm(shrubbery);

		jane.signForm(robotomy);
		jane.executeForm(robotomy);

		jess.signForm(robotomy);
		jess.executeForm(robotomy);

		jess.signForm(pardon);
		jess.executeForm(pardon);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}