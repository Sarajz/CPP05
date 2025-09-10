/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:10:01 by sarajime          #+#    #+#             */
/*   Updated: 2025/08/13 17:12:43 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

int main()
{
	try
	{
		Bureaucrat b1("Alice", 1);
		std::cout << b1 << std::endl;

		Bureaucrat b2("Bob", 150);
		std::cout << b2 << std::endl;

		b1.incrementGrade();
		std::cout << "After incrementing Alice's grade: " << b1 << std::endl;

		b2.decrementGrade();
		std::cout << "After decrementing Bob's grade: " << b2 << std::endl;

		Bureaucrat b3("Charlie", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}