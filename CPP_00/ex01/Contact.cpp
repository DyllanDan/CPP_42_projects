/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:37:09 by dydaniel          #+#    #+#             */
/*   Updated: 2025/08/21 16:37:12 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_infos(std::string first_name, std::string last_name, \
    std::string nickname, std::string phone_number, std::string secret)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nick_name = nickname;
    this->phone_number = phone_number;
    this->darkest_secret = secret;
};

std::string Contact::get_first_name(void)
{
    return (first_name);
}

std::string Contact::get_last_name(void)
{
    return (last_name);
}
std::string Contact::get_nickname(void)
{
    return (nick_name);
}

std::string Contact::get_phone_number(void)
{
    return (phone_number);
}

std::string Contact::get_secret(void)
{
    return (darkest_secret);
}
