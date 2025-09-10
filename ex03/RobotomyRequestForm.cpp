/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:33:03 by sarajime          #+#    #+#             */
/*   Updated: 2025/09/04 18:33:16 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("Default RobotomyRequestForm", 72, 45), target("Default")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
	: AForm(other), target(other.target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::runForm() const
{
	std::cout << "Bzzzz... Dzzzz..." << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy on " << target << " has failed." << std::endl;
}