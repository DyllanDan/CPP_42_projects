/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:47:50 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/28 13:06:25 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", false, 72, 45), target("default"){};
RobotomyRequestForm::~RobotomyRequestForm(){};

RobotomyRequestForm& RobotomyRequestForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const AForm& other) : AForm((other.getName()), other.getAssigned(), other.getGradeToSign(),
other.getGradeToExec())
{};

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", false, 72, 45), target(target){};


void RobotomyRequestForm::beSigned(const Bureaucrat& bureau)
{
    int buerauGrade = bureau.getGrade();
    int grade_to_sign = this->getGradeToSign();

    if (grade_to_sign < buerauGrade)
    {
        std::cout << bureau.getName() << " não conseguiu assinar " << this->getName() <<
        " porque não tem ranque suficiente!" << std::endl;
        throw AForm::GradeTooLowException();
    }
    else
    {
        setAssigned(true);
        std::cout << bureau.getName() << " assinou " << this->getName() << std::endl;
    }
}

void RobotomyRequestForm::execute(Bureaucrat const & bureau)
{
    int buerauGrade = bureau.getGrade();
    bool assigned = this->getAssigned();
    int grade_to_execute = this->getGradeToExec();

    if (grade_to_execute < buerauGrade)
    {
        std::cout << bureau.getName() << " não conseguiu executar " << this->getName() <<
        " porque não tem ranque suficiente!" << std::endl;
        throw AForm::GradeTooLowException();
    }
    else if (!assigned)
    {
        throw AForm::FormNotAssignedException();
    }
    else
        robotomy(bureau, true);
}

void RobotomyRequestForm::robotomy(const Bureaucrat& bureau, bool success)
{
    std::string name = bureau.getName();

    std::cout << "POWN! CRACK! crank crank crank.... TRAAAA!" << std::endl;
    if (success)
        std::cout << name <<" foi robotomizado com sucesso." << std::endl;
    else
        std::cout << name <<" 50robotomia falhou." << std::endl;

}