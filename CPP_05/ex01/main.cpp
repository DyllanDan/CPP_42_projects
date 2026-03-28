/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:38:56 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/28 12:52:12 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "==== TEST 1: Successful signing ====" << std::endl;
    try
    {
        Bureaucrat b("Alice", 10);
        Form f("Contract", false, 20, 30);
        b.signForm(f); // deve conseguir assinar
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 2: Grade too low to sign ====" << std::endl;
    try
    {
        Bureaucrat b("Bob", 50);
        Form f("TopSecret", false, 10, 20);
        b.signForm(f); // não deve conseguir
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 3: Form already signed ====" << std::endl;
    try
    {
        Bureaucrat b("Carlos", 5);
        Form f("Permit", false, 10, 20);
        b.signForm(f);
        b.signForm(f); // tentar assinar de novo
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 4: Invalid form grade (too high) ====" << std::endl;
    try
    {
        Form f("InvalidHigh", false, 0, 20); // inválido
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 5: Invalid form grade (too low) ====" << std::endl;
    try
    {
        Form f("InvalidLow", false, 151, 20); // inválido
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 6: Bureaucrat grade too high ====" << std::endl;
    try
    {
        Bureaucrat b("HighGuy", 0); // inválido
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 7: Bureaucrat grade too low ====" << std::endl;
    try
    {
        Bureaucrat b("LowGuy", 151); // inválido
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 8: Boundary grades ====" << std::endl;
    try
    {
        Bureaucrat b1("Top", 1);
        Bureaucrat b2("Bottom", 150);

        Form f1("Easy", false, 150, 150);
        Form f2("Hard", false, 1, 1);

        b1.signForm(f2); // deve conseguir
        b2.signForm(f1); // deve conseguir
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== TEST 9: Increment/Decrement ====" << std::endl;
    try
    {
        Bureaucrat b("Worker", 2);
        b.gradeIncrement(); // vira 1
        std::cout << b << std::endl;

        b.gradeIncrement(); // deve lançar exceção
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Worker", 149);
        b.gradeDecrement(); // vira 150
        std::cout << b << std::endl;

        b.gradeDecrement(); // deve lançar exceção
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}