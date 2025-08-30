/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_alpha.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:06:16 by dydaniel          #+#    #+#             */
/*   Updated: 2025/08/23 11:06:17 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int is_alpha(char c)
{
    if ((c >= 65  && c <= 90) || (c >= 97 && c <= 122))
        return (0);
    return (1);
}

int str_is_name(std::string string)
{
    int i;
    int has_char;

    i = 0;
    has_char = 0;
    while (string[i])
    {
        if (!is_alpha(string[i]))
        {
            i++;
            has_char++;
        }
        else if(string[i] == ' ')
            i++;
        else
            return (1);
    }
    if (has_char == 0)
        return (1);
    return (0);
}

std::string first_letter(std::string string)
{
    int i;
    std::string first_letter;

    i = 0;
    while (string[i] == ' ')
        i++;
    while (string[i])
    {
        first_letter += string[i];
        i++;
    }
    return (first_letter);
}