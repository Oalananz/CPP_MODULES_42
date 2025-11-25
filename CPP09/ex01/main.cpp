/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:33:03 by oalananz          #+#    #+#             */
/*   Updated: 2025/11/19 09:07:41 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if(ac == 2)
    {
        RPN a;
        a.calculate(av[1]);
        return 0;
    }
    std::cout << "Error" << std::endl;
    return 1;
}