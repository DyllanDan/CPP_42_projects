/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:46:20 by dydaniel          #+#    #+#             */
/*   Updated: 2025/08/16 15:46:22 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int main(int argc, char** argv)
{
    int i;
    int j;
    char c;

    i = 1;
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        while(argv[i])
        {
            j = 0;
            while(argv[i][j])
            {
                c = argv[i][j];
                if (c >= 97 && c <= 122)
                {
                    c -= 32;
                    std::cout << c;
                }
                else
                    std::cout << c;
                j++;
            }
            std::cout << std::endl;
            i++;
        }
    }
}