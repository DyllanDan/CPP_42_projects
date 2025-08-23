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

int str_is_alpha(std::string string)
{
    int i;

    i = 0;
    while (string[i])
    {
        if ((string[i] >= 65  && string[i] <= 90) || \
        (string[i] >= 97 && string[i] <= 122))
            i++;
        else
            return (1);
    }
    return (0);
}
