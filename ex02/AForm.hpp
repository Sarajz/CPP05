/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:41:37 by sarajime          #+#    #+#             */
/*   Updated: 2025/08/27 20:02:12 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <Bureaucrat.hpp>

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;
	
	public:
		AForm();
		AForm(const std::string &name, int signGrade, int executeGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();

		const std::string &getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(const Bureaucrat &bureaucrat);

		void canExecute(const Bureaucrat &executor) const;
		void execute(const Bureaucrat &executor) const;
		virtual void runForm() const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Grade too high for form";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Grade too low for form";
				}
		};

		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Form is not signed";
				}
		};

};
	std::ostream &operator<<(std::ostream &out, const AForm &b);

#endif