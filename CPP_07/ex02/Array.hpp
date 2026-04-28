/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:49:15 by dydaniel          #+#    #+#             */
/*   Updated: 2026/04/27 21:03:37 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template<typename T>

class Array
{
    private:
        T *array;
        unsigned int _size;
    
    public:
        Array();
        ~Array();
        Array(const Array& other);
        Array& operator=(const Array& other);

        Array(unsigned int i);
        T& operator[](unsigned int i);
        T const & operator[](unsigned int i) const;
        unsigned int size() const;
        
        class OutOfRange : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#include "Array.tpp"

#endif