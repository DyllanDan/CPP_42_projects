/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:38:56 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/21 14:06:37 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat bureau = Bureaucrat("Bastilho", 20);
        Form fall = Form("Queda", false, 30, 40);
        bureau.signForm(fall);
    }
    catch (const std::exception& exception)
    {
        std::cout << "Excepition Caught: " << exception.what() << std::endl;
    }
    try
    {
        Bureaucrat bureau = Bureaucrat("Bastilho", 20);
        Form fall = Form();
        bureau.signForm(fall);
    }
    catch (const std::exception& exception)
    {
        std::cout << "Excepition Caught: " << exception.what() << std::endl;
    }
    return (0);
}