/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:42:10 by peli              #+#    #+#             */
/*   Updated: 2025/06/23 20:12:33 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
#include <stdexcept>
#include <sstream>
#include <stdlib.h>
#include <ctype.h>
#include <ctime>
#include <iomanip>
#include <sstream>


class BitcoinExchange
{
private:
    std::map<std::string, float>  database;
public:
    //Orthodox Canonical Form
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator = (const BitcoinExchange& other);
    
    //Load BTC price database
    void    load_database(const std::string& database_file);
    void    load_inputfile(char *file);
    bool    data_valide(std::string& line);
    bool    rate_valide(std::string& line);
    void    calcule(std::string date, std::string value);
};


// 0. Load BTC price database (data.csv)
//   0.1. Vérifier si le fichier existe
//   0.2. Parser chaque ligne : "YYYY-MM-DD,price", si price est un float;
//   0.3. Stocker dans std::map<std::string, double>

// 1.2 Pour chaque ligne :
//   - Vérifier qu’elle contient "date | value"
//   - Séparer en 2 parties : date et valeur
//   - Vérifier que la date est correcte (année, mois, jour valides)  // mktime
//   - Vérifier que la valeur est un float ou entier positif entre 0 et 1000


// 2.2. Chercher le prix du bitcoin pour la date
//   - Si la date existe : utiliser directement
//   - Sinon : chercher la date la plus proche antérieure
// 2.3. Afficher : "date => value = résultat"


//1.Read input file
// 1.1parser input;
// 1.1.0 input exist or not

//2.Output the resultat
// 2.1.0 Le format:La date: Year-Month-Day
// 2.1.1 parser la date
// "Error: bad input => 2001-42-42"
// 2.1.2 A valid value must be either a float or a positive integer, between 0 and 1000.
    // ": not a positive number."
    // "Error: too large a number."
// 2.1.3 Each line in this file must use the following format: "date | value".
// 
