/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:53:41 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/21 17:44:08 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : name("Presidential"), assigned(false), grade_to_execute(45), grade_to_sign(72)

PresidentialPardonForm::~PresidentialPardonForm();

PresidentialPardonForm& PresidentialPardonForm::operator=(const Form& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

PresidentialPardonForm::ShrubberyCreationForm(const Form& other) : name(other.getName()), grade_to_sign(other.getGradeToSign()),
grade_to_execute(other.getGradeToExec())
{
    this->assigned = other.getAssigned();
};

void PresidentialPardonForm::beSigned(const Bureaucrat& bureau)
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

void PresidentialPardonForm::execute(Bureaucrat const & bureau)
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
        pardon(buerau, true);
}


void PresidentialPardonForm::pardon(const Bureaucrat& bureau)
{
    std::string name = buerau.getName();

    std::cout << name <<" foi perdoado por Zaphod Beeblebrox." << std::endl;

}