/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:46:01 by sarajime          #+#    #+#             */
/*   Updated: 2025/08/29 11:46:35 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("Default ShrubberyCreationForm", 145, 137), target("Default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
	: AForm(other), target(other.target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::runForm() const
{
	std::ofstream file((target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cerr << "Error opening file: " << target << "_shrubbery" << std::endl;
		return;
	}

	file << "       _-_" << std::endl;
	file << "    /~~   ~~\\" << std::endl;
	file << " /~~         ~~\\" << std::endl;
	file << "{               }" << std::endl;
	file << " \\  _-     -_  /" << std::endl;
	file << "   ~  \\\\ //  ~" << std::endl;
	file << "_- -   | | _- _" << std::endl;
	file << "  _ -  | |   -_" << std::endl;
	file << "      // \\\\" << std::endl;

	file.close();
}