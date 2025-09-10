/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:41:24 by sarajime          #+#    #+#             */
/*   Updated: 2025/08/18 14:57:35 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AForm.hpp>

AForm::AForm() : name("Default AForm"), isSigned(false), signGrade(150), executeGrade(150)
{}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade)
{}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm()
{}

const std::string &AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getSignGrade() const
{
	return signGrade;
}

int AForm::getExecuteGrade() const
{
	return executeGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << "AForm Name: " << AForm.getName() << ", Signed: " << (AForm.getIsSigned() ? "Yes" : "No")
		<< ", Sign Grade: " << AForm.getSignGrade() << ", Execute Grade: " << AForm.getExecuteGrade();
	return out;
}

void AForm::canExecute(const Bureaucrat &executor) const
{
	if (isSigned == false)
		throw FormNotSignedException();
	if (executor.getGrade() > executeGrade)
		throw GradeTooLowException();
}

void AForm::execute(const Bureaucrat &executor) const
{
	canExecute(executor);
	runForm();
}