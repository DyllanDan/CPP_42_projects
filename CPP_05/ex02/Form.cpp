/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:29:49 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/14 14:50:35 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("defaultForm"), grade_to_sign(1), grade_to_execute(1) 
{
    assigned = false;
}

Form::~Form(){}

Form::Form(const Form& other) : name(other.getName()), grade_to_sign(other.getGradeToSign()),
grade_to_execute(other.getGradeToExec())
{
    this->assigned = other.getAssigned();
}

Form& Form::operator=(const Form& other)
{
    if(this != &other)
    {
        this->assigned = other.getAssigned();
    }
    return(*this);
}

Form::Form(std::string name, bool sign, int gradeSign, int gradeExec) : name(name), assigned(sign), grade_to_sign(gradeSign), grade_to_execute(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw Form::GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw Form::GradeTooLowException();
}

void Form::setAssigned(bool sign)
{
    this->assigned = sign;
}

const std::string Form::getName() const
{
    return name;
}

bool Form::getAssigned() const
{
    return assigned;
}

int Form::getGradeToSign() const
{
    return grade_to_sign;
}

int Form::getGradeToExec() const
{
    return grade_to_execute;
}

void Form::beSigned(const Bureaucrat& bureau)
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

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << form.getName() << ", Form with grade to sign  " << form.getGradeToSign() << " and grade to execute " <<
    form.getGradeToExec() << std::endl;
    return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form: Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form: Grade is too low!");
}