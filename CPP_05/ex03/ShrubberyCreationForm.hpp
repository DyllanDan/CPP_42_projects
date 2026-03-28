/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:51:40 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/28 13:07:46 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const AForm& other);
        ShrubberyCreationForm& operator=(const AForm& other);
        ShrubberyCreationForm(std::string target);
        void beSigned(const Bureaucrat& bureau);
        void execute(Bureaucrat const & bureau);
        void writeTree(const Bureaucrat& bureau) const;
        std::string asciiTree() const;
};

#endif