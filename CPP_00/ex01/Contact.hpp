/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:37:21 by dydaniel          #+#    #+#             */
/*   Updated: 2025/08/21 16:37:23 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include<iostream>
#include <string>
#include <sstream>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string darkest_secret;
    
    public:
        void set_infos(std::string first_name, std::string last_name, \
            std::string nickname, std::string phone_number, std::string secret);
        std::string get_first_name();
        std::string get_last_name();
        std::string get_nickname();
        std::string get_phone_number(void);
        std::string get_secret(void);
};

#endif
