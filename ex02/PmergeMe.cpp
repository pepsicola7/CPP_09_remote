/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:58:05 by peli              #+#    #+#             */
/*   Updated: 2025/07/05 12:39:55 by peli             ###   ########.fr       */
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
};

std::vector<std::vector<int> > PmergeMe::make_pair(std::vector<int> vec)
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

std::vector<size_t> PmergeMe::jacobsthal_sequence(size_t n)
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

void    PmergeMe::binary_insert(std::vector<int>& sorted, int value)
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

std::vector<int> PmergeMe::merge_sort(std::vector<int> b1)
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

    std::cout << "Before of vector: ";
    for (size_t i = 0; i < vecgroups.size(); i++)
        std::cout << vecgroups[i] << " ";
    std::cout <<std::endl;

    vecgroups = merge_sort(vecgroups);

    std::cout << "After of vector: ";
    for (size_t i = 0; i < vecgroups.size(); i++)
        std::cout << vecgroups[i] << " ";
    std::cout << std::endl;

    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    long total_microseconds = seconds * 1000000 + microseconds;

    std::cout << "Time to process a range of " << how_many_chiffre << " elements with std::vector: " << total_microseconds << " us" << std::endl;
};

std::deque<std::deque<int> > PmergeMe::make_pair(std::deque<int> vec)
{
    std::deque<std::deque<int> > temps;
    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        std::deque<int> element;
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
        std::deque<int> last_pair;
        last_pair.push_back(vec.back());
        temps.push_back(last_pair);
    }
    return temps;
}

std::deque<size_t> PmergeMe::jacobsthal_sequence_d(size_t n)
{
    std::deque<size_t> seq;
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

    std::deque<size_t> result;
    std::vector<bool> added(n, false);  // keep as vector for indexing
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

void PmergeMe::binary_insert_d(std::deque<int>& sorted, int value)
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
}

std::deque<int> PmergeMe::merge_sort_d(const std::deque<int>& b1)
{
    if (b1.size() <= 1)
        return b1;

    std::deque<std::deque<int> > temps = make_pair(b1);
    std::deque<int> b2;
    std::deque<int> smalls;

    for (size_t i = 0; i < temps.size(); i++)
    {
        if (temps[i].size() == 2)
        {
            b2.push_back(std::max(temps[i][0], temps[i][1]));
            smalls.push_back(std::min(temps[i][0], temps[i][1]));
        }
        else
        {
            b2.push_back(temps[i][0]);  // Unpaired last element
        }
    }

    std::deque<int> big_sort = merge_sort_d(b2);
    std::deque<size_t> insertion_order = jacobsthal_sequence_d(smalls.size());

    for (size_t j = 0; j < insertion_order.size(); j++)
    {
        size_t index = insertion_order[j];
        if (index < smalls.size())
            binary_insert_d(big_sort, smalls[index]);
    }

    return big_sort;
}

void PmergeMe::sortDeque()
{
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    std::cout << "Before of deque: ";
    for (size_t i = 0; i < deqgroups.size(); ++i)
        std::cout << deqgroups[i] << " ";
    std::cout << std::endl;

    std::deque<int> sorted = merge_sort_d(deqgroups);

    std::cout << "After of deque: ";
    for (size_t i = 0; i < sorted.size(); ++i)
        std::cout << sorted[i] << " ";
    std::cout << std::endl;

    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    long total_microseconds = seconds * 1000000 + microseconds;

    std::cout << "Time to process a range of " << how_many_chiffre
              << " elements with std::deque : " << total_microseconds << " us" << std::endl;
};
