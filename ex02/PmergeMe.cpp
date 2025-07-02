/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:58:05 by peli              #+#    #+#             */
/*   Updated: 2025/07/02 17:42:23 by peli             ###   ########.fr       */
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
    (void)other;
};

PmergeMe PmergeMe::operator = (const PmergeMe& other)
{
    (void)other;
    return(*this);
};

void    PmergeMe::parser(char** argv, int argc)
{
    how_many_chiffre = argc;
    int a;
    for (int i = 1; i < argc; i++)
    {
        std::string token = argv[i];
        for (size_t j = 0; j < token.size(); j++)
        {
            if (!isdigit(token[j]))
            {
                throw std::runtime_error("Invalid character");
            }
        }
        int value = std::atoi(argv[i]);
        if (value < 0 )
            throw std::runtime_error("Negative number");
        if (i % 2 == 1)
            a = value;
        else
        {
            std::vector<int> element;
            element.push_back(a);
            element.push_back(value);
            vecgroups.push_back(element);

            std::deque<int> element_;
            element_.push_back(a);
            element_.push_back(value);
            deqgroups.push_back(element_);
        }
    }
    if (how_many_chiffre % 2 == 1)
    {
        std::vector<int> element;
        element.push_back(a);
        vecgroups.push_back(element);

        std::deque<int> element_;
        element_.push_back(a);
        deqgroups.push_back(element_);
    }
    std::cout << "Before: ";
    for (size_t i = 0; i < vecgroups.size(); i++)
    {
        for (size_t j = 0; j < vecgroups[i].size(); j++)
            std::cout << vecgroups[i][j] << " ";
    }
    std::cout <<std::endl;
};

std::vector<std::vector<int>> make_pair(std::vector<int> vec)
{
    std::vector<std::vector<int>> temps;
    for (int i = 0; i < vec.size(); i++)
    {
        std::vector<int> element;
        element.push_back(vec[i]);
        element.push_back(vec[i + 1]);
        temps.push_back(element);
    }
    return(temps);
}

void    PmergeMe::sortVector()
{    
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    std::vector<int> b1;
    std::vector<int> s1;
    
    for (int i = 0; i < vecgroups.size(); i++)
    {
        if (vecgroups[i][0] > vecgroups[i][1])
            b1.push_back(vecgroups[i][0]);
        else
            s1.push_back(vecgroups[i][1]);
    }
    std::vector<std::vector<int>> b1 = make_pair(b1);
    while (b1.size() > 1)
    {
        for (int i = 0; i < b1.size(); i++)
        {
            if (b1.[0] > b1.[1])
                b1.push_back(vecgroups[i][0]);
            else
                s1.push_back(vecgroups[i][1]);
        }
    }
    
    
    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    long total_microseconds = seconds * 1000000 + microseconds;
    std::cout << "Time to process a range of " << how_many_chiffre << " elements with std::vector : " << total_microseconds << " us" << std::endl;
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
    std::cout << "Time to process a range of " << how_many_chiffre << " elements with std::deque : " << total_microseconds << " us" << std::endl;
    return ;
};

void    PmergeMe::display()
{
    std::cout << "After: ";
    for (size_t i = 0; i < vecgroups.size(); i++)
    {
        for (size_t j = 0; j < vecgroups[i].size(); j++)
            std::cout << vecgroups[i][j] << " ";
    }
}; 
