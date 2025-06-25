/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:50:41 by peli              #+#    #+#             */
/*   Updated: 2025/06/25 16:52:21 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Warlock
{
private:
    std::string name;
    std::string title;
public:
    Warlock(const std::string &Name, const std::string &Title);
    ~Warlock();
    // Warlock(const Warlock& other);
    // Warlock operator = (const Warlock& other);
    
    const std::string& getName()const;
    const std::string& getTitle()const;
    void    setTitle(const std::string);
    void    introduce() const;
};
