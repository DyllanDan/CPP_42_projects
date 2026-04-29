/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:12:30 by dydaniel          #+#    #+#             */
/*   Updated: 2026/04/29 20:08:18 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array() : array(NULL), _size(0) {}

template<typename T>
Array<T>::~Array()
{
    delete [] array;
}

template<typename T>
Array<T>::Array(const Array<T>& other) : array(NULL), _size(0)
{
    *this = other;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        delete [] array;
        _size = other.size();
        array = new T[_size]();
        for (unsigned int i = 0; i < _size; i++)
        {
            array[i] = other.array[i];
        }
    }
    return (*this);
}

template<typename T>
Array<T>::Array(unsigned int i) : _size(i)
{
    array = new T[i];
}

template<typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw OutOfRange();
    return array[i];
}

template<typename T>
T const & Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw OutOfRange();
    return array[i];
}

template<typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template<typename T>
const char* Array<T>::OutOfRange::what() const throw()
{
    return ("Index out of range.");
}
        
