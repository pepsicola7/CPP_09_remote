/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:57:53 by peli              #+#    #+#             */
/*   Updated: 2025/07/02 10:24:17 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <ctime>
#include <sys/time.h>

class PmergeMe
{
private:
    std::vector<int> vector;
    std::deque<int>  deque;
    int how_many_chiffre;
public:
    PmergeMe(/* args */);
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe operator = (const PmergeMe& other);

    void    parser(char** argv, int argc);
    void    sortVector();
    void    sortDeque();
    void    display(); 
};

