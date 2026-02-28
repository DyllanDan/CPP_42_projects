/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:38:54 by dydaniel          #+#    #+#             */
/*   Updated: 2026/02/28 15:41:35 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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