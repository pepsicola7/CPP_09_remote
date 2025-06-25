/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:15:01 by peli              #+#    #+#             */
/*   Updated: 2025/06/25 19:40:53 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ATarget.hpp"

class ASpell
{
protected:
    std::string name;
    std::string effects;
public:
    ASpell(std::string Name, std::string Effects);
    virtual ~ASpell();
    ASpell(const ASpell& other);
    ASpell& operator = (const ASpell& other);
    
    const std::string& getName();
    const std::string& getEffects();
    virtual ASpell* clone() const = 0;
    void launch(const ATarget& src)const;
};


