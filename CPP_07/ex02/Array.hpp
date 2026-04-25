/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:49:15 by dydaniel          #+#    #+#             */
/*   Updated: 2026/04/25 15:12:05 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>

class Array
{
    private:
        T *array;
        unsigned int size;
    
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

#endif