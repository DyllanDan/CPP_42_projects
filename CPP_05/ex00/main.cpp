/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:38:56 by dydaniel          #+#    #+#             */
/*   Updated: 2026/02/28 16:04:35 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat* bureau1 = new Bureaucrat();
        bureau1->setGrade(-1);
    }
    catch (const std::exception& exception)
    {
        std::cout << "Excepition Caught: " << exception.what() << std::endl;
    }
    try
    {
        Bureaucrat* bureau3 = new Bureaucrat("Leão", 20);
        std::cout << *bureau3 << std::endl;
        bureau3->gradeIncrement();
        std::cout << *bureau3 << std::endl;
        bureau3->gradeDecrement();
        std::cout << *bureau3 << std::endl;
    }
    catch (const std::exception& exception)
    {
        std::cout << "Excepition Caught: " << exception.what() << std::endl;
    }
    try
    {
        Bureaucrat* bureau2 = new Bureaucrat("Napo", 20);
        std::cout << "Name: " << bureau2->getName() << "\nGrade: " << bureau2->getGrade() << std::endl;
        std::cout << "Setting grade to 1" << std::endl;
        bureau2->setGrade(150);
        bureau2->gradeDecrement();
    }
    catch (const std::exception& exception)
    {
        std::cout << "Excepition Caught: " << exception.what() << std::endl;
    }
    return (0);
}