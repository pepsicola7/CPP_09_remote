/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:57:53 by peli              #+#    #+#             */
/*   Updated: 2025/07/04 20:03:07 by peli             ###   ########.fr       */
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
    std::vector<std::vector<int> >   vecgroups;
    std::deque<std::deque<int> >   deqgroups;
    int how_many_chiffre;
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe operator = (const PmergeMe& other);

    void    parser(char** argv, int argc);
    void    sortVector();
    void    sortDeque();
    void    display(); 
};

