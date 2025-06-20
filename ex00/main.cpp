/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:40:11 by peli              #+#    #+#             */
/*   Updated: 2025/06/20 16:50:07 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
  try
  {
    if (argc != 2)
      throw std::runtime_error("could not open file.");
    BitcoinExchange btc;
    btc.load_inputfile(argv[1]);
  }
  catch(const std::exception& e)
  {
    std::cerr  << "Error: " << e.what() << '\n';
  }
  
  return (0);
}

