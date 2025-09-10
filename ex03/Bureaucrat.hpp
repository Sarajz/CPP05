/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:49:35 by sarajime          #+#    #+#             */
/*   Updated: 2025/09/04 18:31:01 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <AForm.hpp>

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
		
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		const std::string &getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form) const;
		void executeForm(AForm &form) const;
		

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Grade too high";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Grade too low";
				}
		};
		
	};
	std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
	
#endif