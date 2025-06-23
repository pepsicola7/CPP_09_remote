/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:30:59 by peli              #+#    #+#             */
/*   Updated: 2025/06/23 20:44:08 by peli             ###   ########.fr       */
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
        database[date] = atof(exchange_rate.c_str());
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
        return (false);
    return (true);
}

bool    BitcoinExchange::rate_valide(std::string& line)
{
    char* endptr = NULL;
    double value = std::strtod(line.c_str(), &endptr);
    if (endptr == line.c_str())  // rien n'a été lu
        return false;
    while (*endptr != '\0')
    {
        if (!std::isspace(*endptr))
            return false;
        ++endptr;
    }
    if (value < 0.0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > __INT_MAX__)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

void    BitcoinExchange::calcule(std::string date, std::string value)
{
    std::map<std::string, float>::iterator it;

    it = database.lower_bound(date);
    if (it->first == date)
    {
        double resultat = atof(value.c_str()) * it->second;
        std::cout << resultat << std::endl;
    }
    else
    {
        it = database.lower_bound(date);
        if (it == database.begin())
        {
            std::cerr << "Error: no earlier date found for " << std::endl;
            return ;
        }
        --it;
        double resultat = atof(value.c_str()) * it->second;
        std::cout << resultat << std::endl;
    }
};

void    BitcoinExchange::load_inputfile(char *file)
{
    std::ifstream    myfile;
    std::string      line;
    std::string      date;
    std::string      value;
    myfile.open(file);
    if (myfile.is_open())
    {
        std::getline(myfile, line);
        if (line != "date | value")
            throw std::runtime_error("Format of the date and value is not correct.");
        while (std::getline(myfile, line))
        {
            std::istringstream  iss(line);
            std::getline(iss, date, ' ');
            if (data_valide(date) == false)
            {
                std::cerr << "Error: bad input  => " << date << std::endl;
                date.clear();
                continue;
            }
            value = line.substr(13,line.size());
            if (rate_valide(value) == false)
            {
                value.clear();
                continue;
            }
            if (!date.empty() && !value.empty())
            {
                std::cout << date << " => " << value << " = ";
                calcule(date, value);
            }
        }
    }
    else
        throw std::runtime_error("could not open file.");
    myfile.close();
};
