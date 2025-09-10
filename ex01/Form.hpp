/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:41:37 by sarajime          #+#    #+#             */
/*   Updated: 2025/08/13 18:54:11 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <Bureaucrat.hpp>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;
	
	public:
		Form();
		Form(const std::string &name, int signGrade, int executeGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		const std::string &getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(const Bureaucrat &bureaucrat);

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

};
	std::ostream &operator<<(std::ostream &out, const Form &b);

#endif