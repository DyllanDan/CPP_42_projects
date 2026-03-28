/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:38:56 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/28 14:18:35 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
    std::cout << "==== TEST 1: Create valid form (shrubbery) ====" << std::endl;
    try
    {
        Intern intern;
        AForm* f = intern.makeForm("Shrubbery Form", "home");

        delete f;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 2: Create invalid form ====" << std::endl;
    try
    {
        Intern intern;
        AForm* f = intern.makeForm("unknown form", "target");

        if (f)
            delete f;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 3: Intern + Bureaucrat sign & execute ====" << std::endl;
    try
    {
        Intern intern;
        Bureaucrat b("Alice", 1);

        AForm* f = intern.makeForm("Presidential Pardon", "Criminal");

        b.signForm(*f);
        b.executeForm(*f);

        delete f;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 4: Robotomy via Intern (random) ====" << std::endl;
    try
    {
        Intern intern;
        Bureaucrat b("Bob", 1);

        AForm* f = intern.makeForm("Robotomy Request", "Bender");

        b.signForm(*f);
        for (int i = 0; i < 3; i++)
            b.executeForm(*f);

        delete f;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 5: Low grade cannot execute Intern form ====" << std::endl;
    try
    {
        Intern intern;
        Bureaucrat b("LowGuy", 150);

        AForm* f = intern.makeForm("Shrubbery Form", "garden");

        b.signForm(*f);      // pode ou não assinar dependendo do grade
        b.executeForm(*f);   // deve falhar

        delete f;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}