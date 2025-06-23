/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:30:59 by peli              #+#    #+#             */
/*   Updated: 2025/06/23 16:34:50 by peli             ###   ########.fr       */
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
    (void)other;
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
    
    myfile.open (database_file.c_str());
    if (!myfile.is_open())
        throw std::runtime_error("could not open file.");
    std::getline(myfile, line);
    while (std::getline(myfile, line))
    {
        std::istringstream    iss(line);
        std::getline(iss, date, ',');
        if (data_valide(date) == false)
            throw std::runtime_error("Error of the date in file of data");
        std::getline(iss, exchange_rate, '\n');
        if (rate_valide(exchange_rate) == false)
            throw std::runtime_error("Error of the Exchange rate in file of data");
    }
    myfile.close();
};

bool    BitcoinExchange::data_valide(std::string& line)
{
    if (line.size() != 10 || line[4] != '-' || line[7] != '-')
        return false;
    std::string year = line.substr(0, 4);
    std::string month = line.substr(5, 2);
    std::string day = line.substr(8, 2);
    std::tm tm;
    std::memset(&tm, 0, sizeof(tm));
    tm.tm_year = std::atoi(year.c_str());
    tm.tm_mon  = std::atoi(month.c_str());
    tm.tm_mday = std::atoi(day.c_str());
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    tm.tm_isdst = -1; // Laisser mktime gérer l’heure d’été
    std::time_t t = std::mktime(&tm);
    if (t == -1)
        return (false);
    std::tm local = *std::localtime(&t);
    if (local.tm_year != std::atoi(year.c_str()) || local.tm_mon != std::atoi(month.c_str()) || local.tm_mday != std::atoi(day.c_str()))
    {
        // std::cout << "aaa" << std::endl;
        return (false);
    }
    return (true);
}

bool    BitcoinExchange::rate_valide(std::string& line)
{
    (void) line;
    return (true);
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