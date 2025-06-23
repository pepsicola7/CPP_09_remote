/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:30:59 by peli              #+#    #+#             */
/*   Updated: 2025/06/23 17:25:08 by peli             ###   ########.fr       */
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
    
    int y = std::atoi(year.c_str());
    int m = std::atoi(month.c_str());
    int d = std::atoi(day.c_str());
    std::tm tm;
    std::memset(&tm, 0, sizeof(tm));
    tm.tm_year = y - 1900;
    tm.tm_mon  = m - 1;
    tm.tm_mday = d;
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    tm.tm_isdst = -1; // Laisser mktime gérer l’heure d’été
    std::time_t t = std::mktime(&tm);
    if (t == -1)
        return (false);
    std::tm local = *std::localtime(&t);
    if (local.tm_year != y -1900 || local.tm_mon != m - 1 || local.tm_mday != d)
    {
        // std::cout << local.tm_year << '-' << local.tm_mon  << '-' << local.tm_mday << std::endl;
        // std::cout << std::atoi(year.c_str()) << std::atoi(month.c_str()) << std::atoi(day.c_str()) << std::endl;
        return (false);
    }
    return (true);
}

bool    BitcoinExchange::rate_valide(std::string& line)
{
    char* endptr = NULL;
    double value = std::strtod(line.c_str(), &endptr);
    if (endptr == line.c_str())  // rien n'a été lu
        return false;
    while (*endptr != '\0') {
        if (!std::isspace(*endptr))
            return false;
        ++endptr;
    }
    if (value < 0.0) // Par exemple, refuser les valeurs négatives
        return false;
    return true;
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