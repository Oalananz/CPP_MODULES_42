/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:55:55 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/16 15:13:39 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac ,char **av)
{
    if(ac != 2)
    {
        std::cout << "Usage : \n./convert [value]" << std::endl;
        return -1;
    }
    ScalarConverter::convert(std::string(av[1]));
    return 0;
}