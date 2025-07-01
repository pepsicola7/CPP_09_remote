/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:58:05 by peli              #+#    #+#             */
/*   Updated: 2025/07/01 16:25:16 by peli             ###   ########.fr       */
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
};

void    PmergeMe::sortVector()
{

};

void    PmergeMe::sortDeque()
{
    
};

void    PmergeMe::display()
{
    
}; 