/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:51:40 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/25 21:07:59 by dydaniel         ###   ########.fr       */
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
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const AForm& other);
        ShrubberyCreationForm& operator=(const AForm& other);
        void beSigned(const Bureaucrat& bureau);
        void execute(Bureaucrat const & bureau);
        void writeTree(const Bureaucrat& bureau) const;
        std::string asciiTree() const;
};

#endif