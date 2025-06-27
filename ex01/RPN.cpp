/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:16:17 by peli              #+#    #+#             */
/*   Updated: 2025/06/27 17:34:16 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string number)
{
    parser(number);
    for(int i = 0; number[i]; i++)
    {
        if (number[i] != ' ')
            Number.push_back(number[i]);
    }
    // std::cout << "Constructeur is called" << std::endl;
}

RPN::~RPN()
{
}

RPN::RPN(const RPN& other)
{
    this->Number = other.Number;
};

RPN&    RPN::operator = (const RPN& other)
{
    if (this != &other)
    {
        this->Number = other.Number;
    }
    return (*this);
};

void RPN::printDeque() {
    for (std::deque<char>::const_iterator it = Number.begin(); it != Number.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void    RPN::parser(std::string number)
{
    int i = 0;
    while (number[i])
    {
        if (!std::isdigit(number[i]) && number[i] != '+' && number[i] != '-' && number[i] != '*' && number[i] != '/' && number[i] != ' ')
        {
            throw std::runtime_error("Invalid character in input");
            return ;   
        }
        i++;
    }
    if (i == 1)
        throw std::runtime_error("too little the character");
};

void    RPN::calcul()
{
    int resultat;

    resultat = Number.at(0) - '0';
    Number.pop_front();
    while (Number.size() >= 2)
    {
        if(isdigit(Number.at(0)))
        {
            int i = 0;
            while( Number.at(i) != '+' && Number.at(i) != '-' && Number.at(i) != '*' && Number.at(i) != '/')
            { 
                i++;     
            } 
            std::cout << "Before: ";
            printDeque();
            if (Number.at(i) == '+')
            resultat +=Number.at(0) - '0';
            if (Number.at(i) == '-')
            resultat -= Number.at(0) - '0';
            if (Number.at(i) == '*')
            resultat *= Number.at(0) - '0';
            if (Number.at(i) == '/')
            resultat /= Number.at(0) - '0';

            Number.pop_front();
            if (i < (int)Number.size()) {
                std::deque<char>::iterator it = Number.begin();
                std::advance(it, i);
                Number.erase(it);
            }
        }
        Number.pop_front();
        std::cout << "After: ";
        printDeque();
    }
    if (Number.size() >= 1)
        std::cerr << "Error" << std::endl;
    else
        std::cout << resultat << std::endl;
};