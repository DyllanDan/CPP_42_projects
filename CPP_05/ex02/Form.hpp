/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:16:41 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/14 14:42:56 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool assigned;
        const int grade_to_sign;
        const int grade_to_execute;

    public:
        Form();
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);

        Form(const std::string name, bool sign, int grade_to_sign, int grade_to_execute);
        void beSigned(const Bureaucrat& bureau);
        void setAssigned(bool sign);
        const std::string getName() const;
        bool getAssigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
friend std::ostream& operator<<(std::ostream& os, const Form& form);
};

#endif