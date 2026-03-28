/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:53:44 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/28 13:05:11 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fcntl.h>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Form", false, 145, 137), target("default"){};
ShrubberyCreationForm::~ShrubberyCreationForm(){};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const AForm& other) : AForm((other.getName()), other.getAssigned(), other.getGradeToSign(),
other.getGradeToExec())
{};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Form", false, 145, 137), target(target){};


void ShrubberyCreationForm::beSigned(const Bureaucrat& bureau)
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

void ShrubberyCreationForm::execute(Bureaucrat const & bureau)
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
        writeTree(bureau);
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

void ShrubberyCreationForm::writeTree(const Bureaucrat& bureau) const
{
    std::string name = bureau.getName();
    std::string filename = name + "_shrubbery";
    std::string tree = asciiTree();

    int fd = open(filename.c_str(), O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1)
    {
        std::cerr << "Erro ao criar/abrir o arquivo" << std::endl;
        return;
    }

    if (write(fd, tree.c_str(), tree.size()) == -1)
    {
        std::cerr << "Erro ao escrever no arquivo" << std::endl;
        close(fd);
        return;
    }
    close(fd);
}