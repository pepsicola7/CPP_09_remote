/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:16:31 by peli              #+#    #+#             */
/*   Updated: 2025/06/27 16:50:29 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>
#include <iterator>
#include <sstream>

class RPN
{
private:
    std::deque<char> Number; 
public:
    RPN(std::string number);
    ~RPN();
    RPN(const RPN& other);
    RPN&    operator = (const RPN& other);

    void    calcul();
    void    parser(std::string number);
    void    printDeque();
};

