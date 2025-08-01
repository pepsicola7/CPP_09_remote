/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:40:11 by peli              #+#    #+#             */
/*   Updated: 2025/06/30 16:30:15 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cerr << "Error of argument" << std::endl;
    return (1);
  }
  try
  {
    RPN test(argv[1]);
  }
  catch(const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << '\n';
  }
}

