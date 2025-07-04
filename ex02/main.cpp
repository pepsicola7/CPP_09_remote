/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:54:59 by peli              #+#    #+#             */
/*   Updated: 2025/07/04 20:39:59 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cerr << "Too little the argument" << std::endl;
        return (1);
    }
    try
    {
        PmergeMe    test;
        test.parser(argv, argc - 1);
        test.sortVector();
        test.sortDeque();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}