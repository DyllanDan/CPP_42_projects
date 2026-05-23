/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:45:37 by dydaniel          #+#    #+#             */
/*   Updated: 2026/05/23 14:16:17 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    (void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
    (void)other;
}

//_________________Vector________________________________
void fordJohnsonVector(std::vector<int>& v)
{
    
}
void insertionSortVector(std::vector<int>& chain, const std::vector<int>& pending)
{
    
}

int  binarySearchVector(const std::vector<int>& v, int target, int hi) const
{
    
}
    
//_________________Deque________________________________
void fordJohnsonDeque(std::deque<int>& d);
void insertionSortDeque(std::deque<int>& chain, const std::deque<int>& pending);
int  binarySearchDeque(const std::deque<int>& d, int target, int hi) const;


static long getTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000L + tv.tv_usec;
}

void run(int argc, char* argv)
{
    std::vector<int> vec;
    std::deque<int>  deq;

    for(int i = 0; i < argc; i++)
    {
        std::istringstream iss(argv[i]);
        int val;
        if (!(iss >> val) || val <= 0)
            throw std::runtime_error("Error");
        vec.push_back(val);
        deq.push_back(val);

        if (vec.empty() || deq.empty())
            throw std::runtime_error("Error");

        std::cout << "Before:";
        for (int i = 0; i < static_cast<int>(vec.size()); ++i)
            std::cout << " " << vec[i];
        std::cout << std::endl;

        long begin_vec = getTime();
        fordJohnsonVector(vec);
        long end_vec = getTime();

        long begin_deq = getTime();
        fordJohnsonDeque(deq);
        long end_deq = getTime();

        int n = static_cast<int>(vec.size());
    std::cout << "Time to process a range of " << n
              << " elements with std::vector : "
              << (end_vec - begin_vec) << " us" << std::endl;
    std::cout << "Time to process a range of " << n
              << " elements with std::deque  : "
              << (end_deq - begin_vec) << " us" << std::endl;
    }
}
