/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:19:24 by dydaniel          #+#    #+#             */
/*   Updated: 2025/08/23 13:19:26 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void add_command(PhoneBook& phone_book)
{
    std::string entry;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string secret;

    std::cout << "Type the contact first name" << std::endl;
    while (1)
    {
        std::getline(std::cin, entry);
        if (entry == "EXIT")
            exit(0);
        else if (!str_is_alpha(entry))
        {
            first_name = entry;
            break ;
        }
        else
        {
            std::cout << "Invalid first name." << std::endl;
        }
    }
    std::cout << "Type the contact last name" << std::endl;
    while (1)
    {
        std::getline(std::cin, entry);
        if (entry == "EXIT")
            exit(0);
        else if(!str_is_alpha(entry))
        {
            last_name = entry;
            break ;
        }
        else
        {
            std::cout << "Invalid last name." << std::endl;
        }
    }
    std::cout << "Type the contact nickname" << std::endl;
    while (1)
    {
        std::getline(std::cin, entry);
        if (entry == "EXIT")
            exit(0);
        else if(!str_is_alpha(entry))
        {
            nickname = entry;
            break ;
        }
        else
        {
            std::cout << "Invalid nickname." << std::endl;
        }
    }
    std::cout << "Type the phone number" << std::endl;
    while (1)
    {
        std::getline(std::cin, entry);
        if (entry == "EXIT")
            exit(0);
        else if(!str_is_numeric(entry))
        {
            phone_number = entry;
            break ;
        }
        else
        {
            std::cout << "Invalid number." << std::endl;
        }
    }
    std::cout << "Type the darkest secrect" << std::endl;
    while (1)
    {
        std::getline(std::cin, entry);
        if (entry == "EXIT")
            exit(0);
        else if(!str_is_alpha(entry))
        {
            secret = entry;
            break ;
        }
        else
        {
            std::cout << "Invalid alphabetic name." << std::endl;
        }
    }
    phone_book.add_contact(first_name, last_name, nickname, phone_number, secret);
}

void search_command(PhoneBook phone_book)
{
    std::string entry;
    int number;

    phone_book.display_list();
    std::cout << "Insert and id to retrieve contact informations" << std::endl;
    while (1)
    {
        std::getline(std::cin, entry);
        if (str_is_numeric(entry))
        {
            std::cout << "Invalid number." << std::endl;
            return ;
        }
        else
        {
            std::stringstream ss(entry);

            if (ss >> number && ss.eof())
            {
                phone_book.display_contact(number);
                break ;
            }
            else 
            {
                std::cout << "Entrada inválida: não é um número inteiro puro." << std::endl;
            }
        }    
    }
}


int main(void)
{
    std::string entry;
    PhoneBook phone_book;

    phone_book = PhoneBook();
    std::cout << "Wellcome to you PhoneBook." << std::endl;
    while(1)
    {
        std::cout << "Type [ADD], to add a new contact. [SEARCH] to retrive contact information. [EXIT] to end the program" << std::endl;
        std::getline(std::cin, entry);
        if (entry == "EXIT")
            break ;
        else if (entry == "ADD")
            add_command(phone_book);
        else if (entry == "SEARCH")
            search_command(phone_book);    
    }
    return (0);
}
