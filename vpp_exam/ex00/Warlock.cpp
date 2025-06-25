/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:59:15 by peli              #+#    #+#             */
/*   Updated: 2025/06/25 17:09:11 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(const std::string &Name, const std::string &Title)
{
    name = Name;
    title = Title;
    std::cout << name<< ": This looks like another boring day." << std::endl;
};

Warlock::~Warlock()
{    
    std::cout << name << ": My job here is done!" << std::endl;
};
    
const std::string& Warlock::getName()const
{
    return (this->name);
};

const std::string& Warlock::getTitle()const
{
    return (this->title);
};

void    Warlock::setTitle(const std::string Title)
{
    this->title = Title;
};

void    Warlock::introduce() const
{
    std::cout << getName() << ": I am " << getName() << ", " << getTitle() << std::endl;
};


