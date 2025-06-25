/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:16:20 by peli              #+#    #+#             */
/*   Updated: 2025/06/25 19:41:10 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell(std::string Name, std::string Effects): name (Name), effects(Effects)
{
};

ASpell::~ASpell()
{
};

ASpell::ASpell(const ASpell& other): name(other.name), effects(other.effects)
{
};

ASpell& ASpell::operator = (const ASpell& other)
{
    if (this != &other)
    {
        name = other.name;
        effects = other.effects;
    } 
    return (*this);
};
    
const std::string& ASpell::getName()
{
    return (this->name);
};
const std::string& ASpell::getEffects()
{
    return (this->effects);
};

void    ASpell::launch(const ATarget &src)const
{
    src.getHitBySpell(*this);
};
