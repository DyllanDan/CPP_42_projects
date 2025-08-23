/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phone.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:36:52 by dydaniel          #+#    #+#             */
/*   Updated: 2025/08/21 16:36:53 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    id = -1;
    number_of_contacts = 0;
}

void PhoneBook::add_contact(std::string first_name, std::string last_name, \
            std::string nickname, std::string phone_number, std::string secret)
{
    id++;
    if (number_of_contacts < 8)
        number_of_contacts++;
    if (id >= 8)
        id = id % 8;
    contact_list[id].set_infos(first_name, last_name, nickname, phone_number, secret);
}

void PhoneBook::display_string(std::string string)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(string);
    if (len < 9)
    {
        while(i + len <= 9)
        {
            std::cout << " ";
            i++;
        }
        i = 0;
        while (i <= len)
        {
            std::cout << string[i];
            i++;
        }

    }
    else
    {
        while(string[i] && i < 10)
        {
            std::cout << string[i];
            i++;
        }
    }
}

void PhoneBook::display_list(void)
{
    int i;
    char c;
    char d;
    Contact aux;

    i = 0;
    c = '1';
    std::cout << "|INDEX     |FIRST NAME|LAST NAME |NICKNAME  |" << std::endl;
    while(i < number_of_contacts + 1)
    {
        aux = contact_list[i];
        d = c + i;
        std::cout << "|         " << d << "|";
        display_string(aux.get_first_name());
        std::cout << "|";
        display_string(aux.get_last_name());
        std::cout << "|";
        display_string(aux.get_nickname());
        std::cout << "|";
        std::cout << std::endl;
        i++;
    }
}
void PhoneBook::display_contact(int num)
{
    num = num - 1;
    if (num > id || num < 0)
    {
        std::cout << "Invalid ID number" << std::endl;
    }
    else
    {
        std::cout << "First name: " << contact_list[num].get_first_name() << std::endl;
        std::cout << "Last name: " << contact_list[num].get_last_name() << std::endl;
        std::cout << "Nickname: " << contact_list[num].get_nickname() << std::endl;
        std::cout << "Phone number: " << contact_list[num].get_phone_number() << std::endl;
        std::cout << "Darkest secret: " << contact_list[num].get_secret() << std::endl;
    }
}
