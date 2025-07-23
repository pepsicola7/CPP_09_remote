/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:43:05 by peli              #+#    #+#             */
/*   Updated: 2025/07/23 18:06:18 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

class bigint
{
private:
    std::string num;
public:
    bigint();
    bigint(size_t n);
    bigint(const std::string& n);
    bigint(const bigint& other);
    ~bigint();

    void remove_zero();
    
    // operateur de comparaison
    bool operator<(const bigint& other) const;
    bool operator>(const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>=(const bigint& other) const;
    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;

    //opérateurs arithmétiques
    bigint  operator+(const bigint& other) const;
    bigint&  operator+=(const bigint &other);
    bigint  operator-(const bigint &other) const;

    //operateur de deplacement de chiffres
    bigint operator<<(size_t shift) const;
    bigint& operator<<=(size_t shift);
    bigint operator>>(size_t shift) const;
    bigint& operator>>=(size_t shift);

    //operateur de increment
    bigint& operator++();
    bigint operator++(int);

    friend std::ostream& operator<<(std::ostream&os, const bigint& b)
    {
        return (os << b.num);
    }
};
