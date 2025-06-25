/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:11:51 by peli              #+#    #+#             */
/*   Updated: 2025/06/25 19:33:28 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget(/* args */)
{
};

ATarget::~ATarget()
{
};

const ATarget& ATarget::operator= (const ATarget& other) const
{
    
};

const std::string& ATarget::getType()const
{
    return (this->type);
};

void ATarget::getHitBySpell(ASpell &src)const
{
    std::cout << getType() << " has been " << src.getEffects() << std::endl;
};
