/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:58:05 by peli              #+#    #+#             */
/*   Updated: 2025/07/02 10:59:40 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(/* args */)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
};

PmergeMe PmergeMe::operator = (const PmergeMe& other)
{
};

void    PmergeMe::parser(char** argv, int argc)
{
    how_many_chiffre = argc;
    for (int i = 0; i < argc; i++)
    {
        std::string token = argv[i];
        for (int j = 0; j < token.size(); j++)
        {
            if (!isdigit(token[j]))
            {
                throw std::runtime_error("Invalid character");
            }
        }
        int value = std::atoi(argv[i]);
        if (value < 0 )
            throw std::runtime_error("Negative number");
        vector.push_back(value);
        deque.push_back(value); 
    }
    std::cout << "Before: " << std::endl;
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << std::endl;
    }
};

void    PmergeMe::sortVector()
{    
    struct timeval start, end;
    gettimeofday(&start, NULL);
    

    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    long total_microseconds = seconds * 1000000 + microseconds;
    std::cout << "Time to process a range of " << how_many_chiffre << "elements with std::Vector : " << total_microseconds << " us" << std::endl;
    return ;
};

void    PmergeMe::sortDeque()
{
    struct timeval start, end;
    gettimeofday(&start, NULL);
    

    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    long total_microseconds = seconds * 1000000 + microseconds;
    std::cout << "Time to process a range of " << how_many_chiffre << "elements with std::Vector : " << total_microseconds << " us" << std::endl;
    return ;
};

void    PmergeMe::display()
{
    std::cout << "After: " << std::endl;
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << std::endl;
    }
}; 
