/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:47:50 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/21 17:44:25 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::ShrubberyCreationForm() : name("Robotomy"), assigned(false), grade_to_execute(45), grade_to_sign(72)

RobotomyRequestForm::~ShrubberyCreationForm();

RobotomyRequestForm& RobotomyRequestForm::operator=(const Form& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

RobotomyRequestForm::ShrubberyCreationForm(const Form& other) : name(other.getName()), grade_to_sign(other.getGradeToSign()),
grade_to_execute(other.getGradeToExec())
{
    this->assigned = other.getAssigned();
};

void RobotomyRequestForm::beSigned(const Bureaucrat& bureau)
{
    int buerauGrade = bureau.getGrade();

    if (this->grade_to_sign < buerauGrade)
    {
        std::cout << bureau.getName() << " não conseguiu assinar " << this->getName() <<
        " porque não tem ranque suficiente!" << std::endl;
        throw Form::GradeTooLowException();
    }
    else
    {
        assigned = true;
        std::cout << bureau.getName() << " assinou " << this->getName() << std::endl;
    }
}

void RobotomyRequestForm::execute(Bureaucrat const & bureau)
{
    int buerauGrade = bureau.getGrade();

    if (this->grade_to_execute < buerauGrade)
    {
        std::cout << bureau.getName() << " não conseguiu executar " << this->getName() <<
        " porque não tem ranque suficiente!" << std::endl;
        throw Form::GradeTooLowException();
    }
    else if (!this->assigned)
    {
        throw Form::FormNotAssignedException();
    }
    else
        robotomy(buerau, true);
}

void RobotomyRequestForm::robotomy(const Bureaucrat& bureau, bool success)
{
    std::string name = buerau.getName();

    std::cout << "POWN! CRACK! crank crank crank.... TRAAAA!" << std::endl;
    if (sucess)
        std::cout << name <<" foi robotomizado com sucesso." << std::endl;
    else
        std::cout << name <<" 50robotomia falhou." << std::endl;

}