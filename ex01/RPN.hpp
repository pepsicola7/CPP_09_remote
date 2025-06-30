/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:16:31 by peli              #+#    #+#             */
/*   Updated: 2025/06/30 16:41:00 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <iterator>
#include <sstream>

class RPN
{
private:
    std::string Input;
    std::stack<int> Stack;
public:
    RPN(std::string number);
    ~RPN();
    RPN(const RPN& other);
    RPN&    operator = (const RPN& other);

    void    parser(const std::string &input);
};

