/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:07:11 by sarajime          #+#    #+#             */
/*   Updated: 2025/08/11 20:48:58 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat() : name("Default Bureaucrat")
{
	grade = 150;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	grade = other.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

const std::string &Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{	
	try
	{
		if (grade <= 1)
			throw GradeTooHighException();
		grade--;
	}
	catch (const GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		if (grade >= 150)
			throw GradeTooLowException();
		grade++;
	}
	catch (const GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}