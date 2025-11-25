/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:29:41 by oalananz          #+#    #+#             */
/*   Updated: 2025/11/18 15:55:20 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac , char **av)
{
    if(ac == 2)
    {
        bitcoinExchange a(av[1]);
        a.calculatePrice();       
        return (1);
    }
    std::cout << "Error: could not open file." << std::endl;
    return (0);
}