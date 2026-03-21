/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:53:44 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/21 17:44:37 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fcntl.h>

ShrubberyCreationForm::ShrubberyCreationForm() : name("Shrub"), assigned(false), grade_to_execute(137), grade_to_sign(145)

ShrubberyCreationForm::~ShrubberyCreationForm();

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const Form& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const Form& other) : name(other.getName()), grade_to_sign(other.getGradeToSign()),
grade_to_execute(other.getGradeToExec())
{
    this->assigned = other.getAssigned();
};

void ShrubberyCreationForm::beSigned(const Bureaucrat& bureau)
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

void ShrubberyCreationForm::execute(Bureaucrat const & bureau)
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
        writeTree(buerau);
}

std::string ShrubberyCreationForm::asciiTree() const
{
    return ("      &&& &&  & &&\n"
           "  && &\\/&\\|& ()|/ @, &&\n"
           "  &\\/(/&/&||/& /_/)_&/_&\n"
           " &() &\\/&|()|/&\\/ % & ()\n"
           " &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
           "&&   && & &| &| /& & % ()& /&&\n"
           " ()&_---()&\\&\\|&&-&&--%---()~\n"
           "     &&     \\|||\n"
           "             |||\n"
           "             |||\n"
           "             |||\n"
           "             |||");
}

void ShrubberyCreationForm::writeTree(const Bureaucrat& bureau)
{
    std::string name = buerau.getName();
    std::string tree;
    int fd;
    
    fd = open(name + "_shrubbery", O_CREAT | O_WRONLY, 0644);
    if (fd == -1)
    {
        std::cout << "Erro ao criar/ler o arquivo" << std::endl; 
    }
    tree = asciiTree();
    write(fd, tree.c_str(), tree.size());
    close(fd);
}