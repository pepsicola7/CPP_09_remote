/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:58:05 by peli              #+#    #+#             */
/*   Updated: 2025/07/04 20:39:26 by peli             ###   ########.fr       */
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
    // int a;
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
        vecgroups.push_back(value);
        deqgroups.push_back(value);
    }
    std::cout << "Before: ";
    for (size_t i = 0; i < vecgroups.size(); i++)
    {

            std::cout << vecgroups[i] << " ";
    }
    std::cout <<std::endl;
};

std::vector<std::vector<int> > make_pair(std::vector<int> vec)
{
    std::vector<std::vector<int> > temps;
    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        std::vector<int> element;
        if (vec[i] > vec[i + 1])
        {
            element.push_back(vec[i]);
            element.push_back(vec[i + 1]);
        }
        else
        {
            element.push_back(vec[i + 1]);
            element.push_back(vec[i]);
        }
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
    std::vector<size_t> seq;
    if (n == 0) 
        return seq;

    seq.push_back(1);
    size_t j0 = 0;
    size_t j1 = 1;
    while (seq.size() < n) {
        size_t jn = j1 + 2 * j0;
        seq.push_back(jn);
        j0 = j1;
        j1 = jn;
    }

    std::vector<size_t> result;
    std::vector<bool> added(n, false);
    for (size_t i = 0; i < seq.size(); ++i) {
        if (seq[i] < n && !added[seq[i]]) {
            result.push_back(seq[i]);
            added[seq[i]] = true;
        }
    }

    for (size_t i = 0; i < n; ++i)
        if (!added[i])
            result.push_back(i);

    return result;
}


void    binary_insert(std::vector<int>& sorted, int value)
{
    size_t left = 0;
    size_t right = sorted.size();
    while (left < right)
    {
        size_t middle = (left + right) / 2;
        if (sorted[middle] > value)
            right = middle;
        else
            left = middle + 1;
    }
    sorted.insert(sorted.begin() + left, value);
};

std::vector<int> merge_sort(std::vector<int> b1)
{
    if (b1.size() <= 1)
        return b1;

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
    std::vector<size_t> insertion_ordre = jacobsthal_sequence(smalls.size());

    for (size_t j = 0; j < insertion_ordre.size(); j++)
    {
        size_t index = insertion_ordre[j];
        if (index < smalls.size())
            binary_insert(big_sort, smalls[index]);
    }
    if (smalls.size() < b1.size() / 2)
        binary_insert(big_sort, temps.back()[0]);
    return big_sort;
}


void PmergeMe::sortVector() 
{
    struct timeval start, end;
    gettimeofday(&start, NULL);

    vecgroups = merge_sort(vecgroups);

    std::cout << "After: ";
    for (size_t i = 0; i < vecgroups.size(); i++)
    {
        std::cout << vecgroups[i] << " ";
    }
    std::cout << std::endl;
    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    long total_microseconds = seconds * 1000000 + microseconds;

    std::cout << "Time to process a range of " << how_many_chiffre
              << " elements with std::vector: " << total_microseconds << " us" << std::endl;
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

// void    PmergeMe::display()
// {
//     std::cout << "After: ";
//     for (size_t i = 0; i < vecgroups.size(); i++)
//     {
//         std::cout << vecgroups[i] << " ";
//     }
//     std::cout << std::endl;
// }; 

// {
//     if (b1.size() <= 1)
//         return (b1);
//     std::vector<std::vector<int> > temps = make_pair(b1);

//     std::vector<int> b2;
//     std::vector<int> smalls;
//     for (size_t i = 0; i < temps.size(); i++)
//     {
//         if (temps[i].size() == 2)
//         {
//             b2.push_back(std::max(temps[i][0], temps[i][1]));
//             smalls.push_back(std::min(temps[i][0], temps[i][1]));
//         }
//         else
//         b2.push_back(temps[i][0]);
//     }
//     for (size_t i = 0; i < b2.size(); i++)
//         std::cout << "b2"<< b2[i];
//     std::cout << "-----------" << std::endl;
//     for (size_t i = 0;i < smalls.size(); i++)
//         std::cout << "small" << smalls[i];
//     std::cout << "-----------" << std::endl;
    
//     std::vector<int> big_sort = merge_sort(b2);
    
    
//     std::vector<size_t>  insertion_ordre = jacobsthal_sequence(b2.size());
//     for (size_t j = 0; j < insertion_ordre.size(); j++)
//     {
//         size_t index = insertion_ordre[j];
//         std::cout << "index is : " << index << "temsp.size if : " << temps.size() << std::endl;
//         if (index < big_sort.size() && temps[index].size() != 1)
//         {
//             std::cout << "The value to insert" << temps[index].back() << std::endl;
//             binary_insert(big_sort, smalls[index]);
//         }
//     }
//     if (temps.back().size() == 1)
//     binary_insert(big_sort, b2.back());
//     for (size_t i = 0; i < big_sort.size(); i++)
//         std::cout << "big_sorted"<< big_sort[i] << std::endl;
//     std::cout << "-----------" << std::endl;
//     for (size_t i = 0; i < b2.size(); i++)
//         std::cout << b2[i] << std::endl;
//     std::cout << std::endl << "-----------" << std::endl;
//     for (size_t i = 0;i < smalls.size(); i++)
//         std::cout<< "small" << smalls[i] << std::endl;
//     std::cout << "-----------" << std::endl;
//     return (big_sort);
// };