/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 20:27:05 by dydaniel          #+#    #+#             */
/*   Updated: 2026/04/27 20:51:54 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

template<typename T>
void print_elements(const Array<T>& list)
{
    for(unsigned int i = 0; i < list.size(); i++)
    {
        std::cout << list[i] << std::endl;
    }
}

int main(void)
{
    std::cout << "______INT TEST_____" << std::endl;
    Array<int> num_list(3);
    num_list[0] = 10;
    num_list[1] = 20;
    num_list[2] = 30;

    std::cout << "num_list:" << std::endl;
    print_elements(num_list);

    Array<int> num_copy = num_list;

    Array<int> num_test(3);
    num_test = num_list;
    num_list[0] = 999;

    std::cout << "\nnum_list (modificado):" << std::endl;
    print_elements(num_list);

    std::cout << "\nnum_copy (deep copy):" << std::endl;
    print_elements(num_copy);

    std::cout << "\nnum_test (deep copy):" << std::endl;
    print_elements(num_test);

    std::cout << "\n______STR TEST_____" << std::endl;
    Array<std::string> word_list(3);
    word_list[0] = "Hello";
    word_list[1] = "World";
    word_list[2] = "42";

    Array<std::string> word_copy = word_list;

    word_list[1] = "Changed";

    std::cout << "\nword_list:" << std::endl;
    print_elements(word_list);

    std::cout << "\nword_copy (deep copy):" << std::endl;
    print_elements(word_copy);

    std::cout << "\n______CHAR TEST_____" << std::endl;
    Array<char> letter_list(3);
    letter_list[0] = 'a';
    letter_list[1] = 'b';
    letter_list[2] = 'c';

    Array<char> letter_test;
    letter_test = letter_list;
    letter_list[2] = 'z';

    std::cout << "\nletter_list:" << std::endl;
    print_elements(letter_list);

    std::cout << "\nletter_test (deep copy):" << std::endl;
    print_elements(letter_test);

    std::cout << "\n______CONST INT TEST_____" << std::endl;
    const Array<int> const_array = num_list;

    std::cout << "\nconst_array:" << std::endl;
    print_elements(const_array);

    // const_array[0] = 5; // erro de compilação

    std::cout << "\n______EXCEPTION TEST_____" << std::endl;
    try 
    {
        std::cout << "\nAccessing out of bounds:" << std::endl;
        std::cout << num_list[10] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}