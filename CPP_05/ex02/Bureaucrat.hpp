/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:38:54 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/21 13:56:17 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade; //150 (lower) - 1 (higher)
    
    public:
        //Canonical
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        //Methods
        Bureaucrat(const std::string name, int grade);
        const std::string& getName() const;
        int getGrade() const;
        void setGrade(int grade);
        void gradeIncrement();
        void gradeDecrement();
        void signForm(Form& form);
        void executeForm(AForm const & form) const;
        
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

friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureau);
};
#endif