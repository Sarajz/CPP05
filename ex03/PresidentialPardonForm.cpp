/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:04:21 by sarajime          #+#    #+#             */
/*   Updated: 2025/09/03 20:12:00 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("Default PresidentialPardonForm", 25, 5), target("Default")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) 
	: AForm("PresidentialPardonForm", 25, 5), target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
	: AForm(other), target(other.target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::runForm() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}