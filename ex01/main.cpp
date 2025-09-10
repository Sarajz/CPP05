/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:27:40 by sarajime          #+#    #+#             */
/*   Updated: 2025/08/13 18:57:49 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Form.hpp>
#include <Bureaucrat.hpp>

int main()
{
    try
    {
        Bureaucrat boss("Boss", 1);

        Form formA("Form A", 10, 20);

        std::cout << boss << std::endl;
        std::cout << formA << std::endl;

        formA.beSigned(boss);

        std::cout << formA << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "------------------------------" << std::endl;

    try
    {
        Bureaucrat minion("Minion", 151);

        Form formB("Form B", 1, 1);

        std::cout << minion << std::endl;
        std::cout << formB << std::endl;

        formB.beSigned(minion);

        std::cout << formB << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
