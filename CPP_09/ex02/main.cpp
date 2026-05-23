/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:27:08 by dydaniel          #+#    #+#             */
/*   Updated: 2026/05/23 13:50:10 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"


vector<int> PopulateVec(const std::string& numbers)
{
    std::stringstream ss(input);
    std::string token;
    vector<int> vec;
    while(ss >> token)
    {
        int num = std::atoi(token.c_str()) 
        v.
    }
}

list<int> PopulateDeque(const std::string& numbers)
{
    
}


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Not enough arguments" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe pm;
        pm.run(argc, argv);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
}