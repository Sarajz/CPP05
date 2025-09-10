/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:24:37 by sarajime          #+#    #+#             */
/*   Updated: 2025/09/09 19:40:20 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <Intern.hpp>

int main()
{
	try 
	{
		Bureaucrat bob("Bob", 1);
		Intern someRandomIntern;

		std::cout << "\n--- Creando un formulario válido ---" << std::endl;
		AForm* form = someRandomIntern.makeForm("robotomy request", "Bender");

		if (form)
		{
			bob.signForm(*form);
			bob.executeForm(*form);
			delete form;
        }

		std::cout << "\n--- Intentando crear un formulario inválido ---" << std::endl;
		AForm* wrongForm = someRandomIntern.makeForm("pizza request", "Alice");

		if (wrongForm)
		{
			bob.signForm(*wrongForm);
			bob.executeForm(*wrongForm);
			delete wrongForm;
		}
		

    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}