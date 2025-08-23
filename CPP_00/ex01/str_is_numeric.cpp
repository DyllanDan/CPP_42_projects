/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_numeric.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:11:05 by dydaniel          #+#    #+#             */
/*   Updated: 2025/08/23 11:11:19 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int str_is_numeric(std::string string)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(string);
    if (len > 11)
        return (1);
    while (string[i])
    {
        if (string[i] >= 48  && string[i] <= 57)
            i++;
        else
            return (1);
    }
    return (0);
}
