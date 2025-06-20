/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:30:59 by peli              #+#    #+#             */
/*   Updated: 2025/06/20 19:44:03 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    load_database("data.csv");
};

BitcoinExchange::~BitcoinExchange()
{  
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
};

BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange& other)
{
    if (this != &other)
    {
    }
    return(*this);
};

void    BitcoinExchange::load_database(const std::string& database_file)
{
    std::ifstream    myfile;
    std::string      line;
    std::string     date;
    std::string     exchange_rate;
    
    myfile.open (database_file);
    if (myfile.is_open())
    {
        std::getline(myfile, line);
        std::istringstream    iss(line);
        std::getline(iss, date, ',');
        if (data_valide(date) == false)
            throw std::runtime_error("Error of the date in file of data");
        std::getline(iss, exchange_rate, '\n');
        if (rate_valide(exchange_rate) == false)
            throw std::runtime_error("Error of the Exchange rate in file of data");
    }
    else
        throw std::runtime_error("could not open file.");
    myfile.close();
};

bool    BitcoinExchange::data_valide(std::string& line)
{
    
}

bool    BitcoinExchange::rate_valide(std::string& line)
{
    
}

void    BitcoinExchange::load_inputfile(char *file)
{
    std::ifstream    myfile;
    std::string      line;
    myfile.open(file);
    if (myfile.is_open())
    {
        getline(myfile, line);
        if (line != "date | value")
            throw std::runtime_error("Format of the date and value is not correct.");
        while (getline(myfile, line))
        {
            
        }
    }
    else
        throw std::runtime_error("could not open file.");
    myfile.close();
};

// 0. Load BTC price database (data.csv)
//   0.1. Vérifier si le fichier existe //ok
//   0.2. Parser chaque ligne : "YYYY-MM-DD,price", si price est un float;
//   0.3. Stocker dans std::map<std::string, double>