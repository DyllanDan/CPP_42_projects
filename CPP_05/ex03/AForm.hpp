/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:16:41 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/28 13:44:35 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool assigned;
        const int grade_to_sign;
        const int grade_to_execute;

    public:
        AForm();
        virtual ~AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

        AForm(const std::string name, bool sign, int grade_to_sign, int grade_to_execute);
        
        void setAssigned(bool sign);
        const std::string getName() const;
        bool getAssigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        
        virtual void beSigned(const Bureaucrat& bureau) = 0;
        virtual void execute(Bureaucrat const & executor) = 0;
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
        class FormNotAssignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif