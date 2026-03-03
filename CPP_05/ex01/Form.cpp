/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:29:49 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/02 20:52:59 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
{
    name = "defaultForm";
    assigned = false;
    grade_to_sign = 1;
    grade_to_execute = 1;
}

Form::~Form(){}

Form::Form(const Form& other)
{
    this->name = other->getName();
    this->assigned = other->getAssigned();
    this->grade_to_sign = other->getGradeToSign();
    this->grade_to_execute = other->getGradeToExec();
}

Form& Form::operator=(const Form& other)
{
    if(this != &other)
    {
        this->assigned = other->getAssigned();
        this->grade_to_sign = other->getGradeToSign();
        this->grade_to_execute = other->getAssigned();
    }
    return(*this);
}

Form::Form(std::string name, bool sign, int gradeSign, int gradeExec) : name(name), assigned(sign), \
grade_to_sign(gradeSign), grade_to_execute(gradeExec)
{
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw Form::GradeTooHighException();
    else if (grade_to_sign > 150 || grade_to_execute > 150)
        throw Form::GradeTooLowException();
    else
        this->grade = grade;
}

void Form::setGradeToSign(int grade)
{
    this->grade_to_sign = grade;
}

void Form::setGradeToExec(int grade)
{
    this->grade_to_execute = grade;
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

void Form::beSigned(Bureaucrat bureau)
{
    int buerauGrade = buerau.getGrade();

    if (this.grade_to_sign < buerauGrade)
    {
        std::cout << buerau.getName() << " não conseguiu assinar " << this.getName() <<
        "porque não tem ranque suficiente!" << std::endl;
        throw Form::GradeTooLowException();
    }
    else
    {
        assigned = true;
        std::cout << buerau.getName() << " assinou " << this.getName() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << form.getName() << ", Form with grade to sign  " << form.getGradeToSign() << " and grade to execute " <<
    form.getGradeToExec() << std::endl;
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}