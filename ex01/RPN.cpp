/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:16:17 by peli              #+#    #+#             */
/*   Updated: 2025/07/05 16:13:25 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string input)
{
    Input = input;
    parser(Input);
}

RPN::~RPN()
{
}

RPN::RPN(const RPN& other)
{
    this->Input = other.Input;
};

RPN&    RPN::operator = (const RPN& other)
{
    if (this != &other)
    {
        this->Input = other.Input;
    }
    return (*this);
};

void    RPN::parser(const std::string &input)
{
    std::istringstream  iss(input);
    std::string token;
    int resultat;
    while (iss >> token)
    {
        if (token.length() == 1 && std::isdigit(token[0]))
        {
            Stack.push(token[0] - '0');
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (Stack.size() < 2)
                throw std::runtime_error("Not enough operands");
            int b = Stack.top();
            Stack.pop();
            int a = Stack.top();
            Stack.pop();
            if (token == "+")
                resultat = a + b;
            if (token == "-")
                resultat = a - b;
            if (token == "*")
                resultat = a * b;
            if (token == "/")
            {
                if (b == 0)
                    throw std::runtime_error("Division by 0");
                resultat = a / b;
            }
            Stack.push(resultat);
        }
        else
        {
            throw std::runtime_error("Invalid character in input");
        }
    }
    if (Stack.size() != 1)
        throw std::runtime_error("Invalid expression: stack has leftover elements");
    std::cout << Stack.top() << std::endl;
};

// std::istringstream ignore les espaces automatiquement.
