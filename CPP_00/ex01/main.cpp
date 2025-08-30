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

bool add_command(PhoneBook& phone_book)
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
        if (!std::getline(std::cin, entry))
        {
            return false;
        }
        if (!str_is_name(entry))
        {
            first_name = first_letter(entry);
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
        if (!std::getline(std::cin, entry))
        {
            return false;
        }
        if(!str_is_name(entry))
        {
            last_name = first_letter(entry);
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
        if (!std::getline(std::cin, entry))
        {
            return false;
        }
        if(!str_is_name(entry))
        {
            nickname = first_letter(entry);
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
        if (!std::getline(std::cin, entry))
        {
            return false;
        }
        if(!str_is_numeric(entry))
        {
            phone_number = first_letter(entry);
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
        if (!std::getline(std::cin, entry))
        {
            return false;
        }
        if(!str_is_name(entry))
        {
            secret = first_letter(entry);
            break ;
        }
        else
        {
            std::cout << "Invalid alphabetic name." << std::endl;
        }
    }
    phone_book.add_contact(first_name, last_name, nickname, phone_number, secret);
    return true;
}

bool search_command(PhoneBook phone_book)
{
    std::string entry;
    int number;

    phone_book.display_list();
    std::cout << "Insert and id to retrieve contact informations" << std::endl;
    while (1)
    {
        if (!std::getline(std::cin, entry))
        {
            return false;
        }
        else if (str_is_numeric(entry))
        {
            std::cout << "Invalid number." << std::endl;
            break ;
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
    return true;
}


int main(void)
{
    std::string entry;
    PhoneBook phone_book;
    bool exit;

    phone_book = PhoneBook();
    std::cout << "Wellcome to you PhoneBook." << std::endl;
    while(1)
    {
        std::cout << "Type [ADD], to add a new contact. [SEARCH] to retrive contact information. [EXIT] to end the program" << std::endl;
        if (!std::getline(std::cin, entry))
        {
            std::cout << "Impossible to get input. Terminating PhoneBook." << std::endl;
            return (0);
        }
        else if (entry == "EXIT")
            break ;
        else if (entry == "ADD")
        {
            exit = add_command(phone_book);
            if (!exit)
            {
                std::cout << "Impossible to get input. Terminating PhoneBook." << std::endl;
                return (0); 
            }
        }
        else if (entry == "SEARCH")
        {
            exit = search_command(phone_book);
            if (!exit)
            {
                std::cout << "Impossible to get input. Terminating PhoneBook." << std::endl;
                return (0); 
            }
        }

    }
    return (0);
}
