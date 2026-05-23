/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:45:32 by dydaniel          #+#    #+#             */
/*   Updated: 2026/05/23 13:39:37 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <sys/time.h>
# include <vector>
# include <deque>
# include <string>

class PmergeMe
{
    
    private:
    //Vector
    void fordJohnsonVector(std::vector<int>& v);
    void insertionSortVector(std::vector<int>& chain, const std::vector<int>& pending);
    int  binarySearchVector(const std::vector<int>& v, int target, int hi) const;
    
    //Deque
    void fordJohnsonDeque(std::deque<int>& d);
    void insertionSortDeque(std::deque<int>& chain, const std::deque<int>& pending);
    int  binarySearchDeque(const std::deque<int>& d, int target, int hi) const;
    static std::vector<int> jacobsthalSequence(int n);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& src);
        ~PmergeMe();
        void run(int argc, char* argv[]);
};
#endif