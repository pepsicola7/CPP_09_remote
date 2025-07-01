/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:57:53 by peli              #+#    #+#             */
/*   Updated: 2025/07/01 16:09:14 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <iostream>
#include <string>

class PmergeMe
{
private:
    std::vector<int> vector;
    std::deque<int>  deque;
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

