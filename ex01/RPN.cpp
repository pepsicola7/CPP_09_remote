/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:16:17 by peli              #+#    #+#             */
/*   Updated: 2025/06/24 15:48:15 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string number)
{
    parser(number);
    for(int i = 0; number[i]; i++)
    {
        if (number[i] != ' ')
            Number.push_front(number[i]);
    }
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

void    RPN::parser(std::string number)
{
    int i = 0;
    while (number[i])
    {
        if (!std::isdigit(number[i]) && number[i] == '+' && number[i] == '-' && number[i] == '*' && number[i] == '/' && number[i] == ' ')
        {
            std::cerr << "Error" << std::endl;
            return ;   
        }
        i++;
    }
};

void    RPN::calcul()
{
    int resultat;
    int chiffre_wait;

    resultat = Number.at(0) - '0';
    Number.pop_front();
    while (Number.at(0))
    {
        if (isdigit(Number.at(0)))
            chiffre_wait = Number.at(0) - '0';
        if (Number.at(0) == '+')
            resultat = chiffre_wait + resultat;
        if (Number.at(0) == '-')
            resultat = resultat - chiffre_wait;
        if (Number.at(0) == '*')
            resultat = resultat * chiffre_wait;
        if (Number.at(0) == '/')
        if (Number.at(0) == '-')
            resultat = resultat / chiffre_wait;
    }
    
};