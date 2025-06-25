/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:02:46 by peli              #+#    #+#             */
/*   Updated: 2025/06/25 19:33:37 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ASpell.hpp>

class ASpell;

class ATarget
{
protected:
    std::string type;
public:
    ATarget();
    ~ATarget();
    ATarget(const ATarget& other);
    const ATarget& operator = (const ATarget& other) const;

    const std::string& getType()const;
    void getHitBySpell(ASpell& src)const;
};

