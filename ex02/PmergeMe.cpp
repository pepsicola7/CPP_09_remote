/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:58:05 by peli              #+#    #+#             */
/*   Updated: 2025/07/03 18:00:09 by peli             ###   ########.fr       */
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
    for (int i = 1; i < argc + 1; i++)
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

std::vector<std::vector<int> > make_pair(std::vector<int> vec)
{
    std::vector<std::vector<int> > temps;
    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        std::vector<int> element;
        element.push_back(vec[i]);
        element.push_back(vec[i + 1]);
        temps.push_back(element);
    }

    if (vec.size() % 2 != 0)
    {
        std::vector<int> last_pair;
        last_pair.push_back(vec.back());
        temps.push_back(last_pair);
    }
    return(temps);
}

std::vector<size_t> jacobsthal_sequence(size_t n)
{
    std::vector<size_t> resultat;

    if (n == 0)
        return resultat;
    size_t j0 = 0;
    size_t j1 = 1;

    for (size_t i = 2; i < n; ++i)
    {
        size_t jn = j1 + 2 * j0;
        resultat.push_back(jn);
        std::cout << "jacobsthal : " << jn << std::endl;

        j0 = j1;
        j1 = jn;
    }

    return resultat;
}

std::vector<int>     merge_sort( std::vector<int> b1)
{
    for (size_t i = 0; i < b1.size(); i++)
        std::cout << b1[i] << " ";
    std::cout << std::endl;
    if (b1.size() <= 1)
        return (b1);
    std::vector<std::vector<int> > temps = make_pair(b1);
    
    std::vector<int> b2;
    std::vector<int> smalls;
    for (size_t i = 0; i < temps.size(); i++)
    {
        if (temps[i].size() == 2)
        {
            b2.push_back(std::max(temps[i][0], temps[i][1]));
            smalls.push_back(std::min(temps[i][0], temps[i][1]));
        }
        else
            b2.push_back(temps[i][0]);
    }
    std::vector<int> big_sort = merge_sort(b2);
    std::vector<size_t>  insertion_ordre = jacobsthal_sequence(b2.size());
    for (size_t j = 0; j < insertion_ordre.size(); j++)
    {
        size_t index = insertion_ordre[j];
        if (index >= smalls.size())
            break;
        
    }
    return (big_sort);
};

void    PmergeMe::sortVector()
{    
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    std::vector<int> b1;
    std::vector<int> s1;
    for (size_t i = 0; i < vecgroups.size(); i++)
    {
        if (vecgroups[i].size() == 2)
        {
            if (vecgroups[i][0] > vecgroups[i][1])
            {
                b1.push_back(vecgroups[i][0]);
                s1.push_back(vecgroups[i][1]);
            }
            else
            {
                b1.push_back(vecgroups[i][1]);
                s1.push_back(vecgroups[i][0]); 
            }
        }
        else
        {
            b1.push_back(vecgroups[i][0]);
        }
    }
    std::vector<int> sorted_big = merge_sort(b1);
    for (size_t i = 0; i < sorted_big.size(); i++)
        std::cout << "After recursif : " << sorted_big[i] << std::endl;
    
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
