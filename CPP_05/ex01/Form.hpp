/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:16:41 by dydaniel          #+#    #+#             */
/*   Updated: 2026/02/28 16:28:49 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

class Form
{
    private:
        const std::string name;
        bool assigned;
        int grade_to_sign;
        int grade_to_execute;

    public:
        Form();
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);
        void beSigned(Bureaucrat buerau);
        
        
}

#endif