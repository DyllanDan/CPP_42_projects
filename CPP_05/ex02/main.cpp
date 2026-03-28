/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:38:56 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/28 13:08:22 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::cout << "==== TEST 1: Execute without signing ====" << std::endl;
    try
    {
        Bureaucrat b("Alice", 1);
        PresidentialPardonForm f("Target");
        b.executeForm(f); // deve falhar (não assinado)
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 2: Grade too low to execute ====" << std::endl;
    try
    {
        Bureaucrat b("Bob", 50);
        PresidentialPardonForm f("Target");
        b.signForm(f);
        b.executeForm(f); // deve falhar (grade insuficiente)
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 3: Shrubbery creates file ====" << std::endl;
    try
    {
        Bureaucrat b("Carlos", 1);
        ShrubberyCreationForm f("home");
        b.signForm(f);
        b.executeForm(f); // deve criar arquivo "home_shrubbery"
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 4: Robotomy randomness ====" << std::endl;
    try
    {
        Bureaucrat b("Diana", 1);
        RobotomyRequestForm f("Bender");
        b.signForm(f);

        // executar várias vezes pra ver sucesso/falha (50%)
        for (int i = 0; i < 5; i++)
            b.executeForm(f);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 5: Form already signed ====" << std::endl;
    try
    {
        Bureaucrat b("Eva", 1);
        ShrubberyCreationForm f("garden");
        b.signForm(f);
        b.signForm(f); // tentativa duplicada
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 6: Low grade cannot sign ====" << std::endl;
    try
    {
        Bureaucrat b("Frank", 150);
        RobotomyRequestForm f("Target");
        b.signForm(f); // deve falhar
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 7: Boundary execution grades ====" << std::endl;
    try
    {
        Bureaucrat top("Top", 1);
        Bureaucrat low("Low", 150);

        PresidentialPardonForm f1("King");
        ShrubberyCreationForm f2("Park");

        top.signForm(f1);
        top.executeForm(f1); // OK

        top.signForm(f2);
        low.executeForm(f2); // deve falhar (exec grade)
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 8: Multiple forms sequence ====" << std::endl;
    try
    {
        Bureaucrat b("Multi", 1);

        ShrubberyCreationForm s("tree");
        RobotomyRequestForm r("robot");
        PresidentialPardonForm p("criminal");

        b.signForm(s);
        b.signForm(r);
        b.signForm(p);

        b.executeForm(s);
        b.executeForm(r);
        b.executeForm(p);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}