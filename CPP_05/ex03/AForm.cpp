/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:29:49 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/28 13:34:05 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("defaultForm"), grade_to_sign(1), grade_to_execute(1) 
{
    assigned = false;
}

AForm::~AForm(){}

AForm::AForm(const AForm& other) : name(other.getName()), grade_to_sign(other.getGradeToSign()),
grade_to_execute(other.getGradeToExec())
{
    this->assigned = other.getAssigned();
}

AForm& AForm::operator=(const AForm& other)
{
    if(this != &other)
    {
        this->assigned = other.getAssigned();
    }
    return(*this);
}

AForm::AForm(std::string name, bool sign, int gradeSign, int gradeExec) : name(name), assigned(sign), grade_to_sign(gradeSign), grade_to_execute(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw AForm::GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw AForm::GradeTooLowException();
}

void AForm::setAssigned(bool sign)
{
    this->assigned = sign;
}

const std::string AForm::getName() const
{
    return name;
}

bool AForm::getAssigned() const
{
    return assigned;
}

int AForm::getGradeToSign() const
{
    return grade_to_sign;
}

int AForm::getGradeToExec() const
{
    return grade_to_execute;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << form.getName() << ", Form with grade to sign  " << form.getGradeToSign() << " and grade to execute " <<
    form.getGradeToExec() << std::endl;
    return os;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Form: Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Form: Grade is too low!");
}

const char* AForm::FormNotAssignedException::what() const throw()
{
    return ("Form: Not assigned!");
}