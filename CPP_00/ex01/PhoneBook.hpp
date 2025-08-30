/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:36:59 by dydaniel          #+#    #+#             */
/*   Updated: 2025/08/21 16:37:01 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
    private:
        int id;
        int number_of_contacts;
        Contact contact_list[8];
    
    public:
        PhoneBook();
        void add_contact(std::string first_name, std::string last_name, \
            std::string nickname, std::string phone_number, std::string secret);
        void display_list(void);
        void display_string(std::string);
        void display_contact(int id);
};

int str_is_name(std::string string);
int str_is_numeric(std::string string);
int ft_strlen(std::string string);
std::string first_letter(std::string string);

#endif
