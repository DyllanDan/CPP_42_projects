/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:12:30 by dydaniel          #+#    #+#             */
/*   Updated: 2026/04/27 20:26:09 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array() : array(NULL), size(0) {}

template<typename T>
Array<T>::~Array()
{
    delete [] array;
}

template<typename T>
Array<T>::Array(const Array& other) : array(NULL), size(0)
{
    *this = other;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete [] array;
        unsigned int len = other.size();
        array = new T[len]();
        for (int i = 0; i < len; i++)
        {
            array[i] = other.array[i];
        }
    }
    return (*this);
}

template<typename T>
Array<T>::Array(unsigned int i) : size(i)
{
    array = new T[i];
}

template<typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= size)
        throw OutOfRange();
    return array[i];
}

template<typename T>
T const & Array<T>::operator[](unsigned int i) const
{
    if (i >= size)
        throw OutOfRange();
    return array[i];
}

template<typename T>
unsigned int Array<T>::size() const
{
    return size;
}

template<typename T>
const char* Array<T>::OutOfRange::what() const throw()
{
    return ("Index out of range.");
}
        
