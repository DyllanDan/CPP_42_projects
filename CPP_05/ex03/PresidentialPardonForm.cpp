/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:53:41 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/28 13:06:51 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", false, 25, 5), target("default"){};
PresidentialPardonForm::~PresidentialPardonForm(){};

PresidentialPardonForm& PresidentialPardonForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const AForm& other) : AForm((other.getName()), other.getAssigned(), other.getGradeToSign(),
other.getGradeToExec())
{};

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", false, 25, 5), target(target){};

void PresidentialPardonForm::beSigned(const Bureaucrat& bureau)
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

void PresidentialPardonForm::execute(Bureaucrat const & bureau)
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
        pardon(bureau);
}


void PresidentialPardonForm::pardon(const Bureaucrat& bureau)
{
    std::string name = bureau.getName();

    std::cout << name <<" foi perdoado por Zaphod Beeblebrox." << std::endl;

}