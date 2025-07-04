/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:57:53 by peli              #+#    #+#             */
/*   Updated: 2025/07/04 21:00:33 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <ctime>
#include <sys/time.h>
#include <cstdlib>
#include <algorithm>

class PmergeMe
{
private:
    std::vector<int>   vecgroups;
    std::deque<int>   deqgroups;
    int how_many_chiffre;
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe operator = (const PmergeMe& other);

    void                            parser(char** argv, int argc);
    void                            sortVector();
    std::vector<int>                merge_sort(std::vector<int> b1);
    void                            binary_insert(std::vector<int>& sorted, int value);
    std::vector<size_t>             jacobsthal_sequence(size_t n);
    std::vector<std::vector<int> >  make_pair(std::vector<int> vec);
    void                            sortDeque();
    std::deque<int>                 merge_sort_d(const std::deque<int>& b1);
    void                            binary_insert_d(std::deque<int>& sorted, int value);
    std::deque<size_t>              jacobsthal_sequence_d(size_t n);
    std::deque<std::deque<int> >    make_pair(std::deque<int> vec);
};

