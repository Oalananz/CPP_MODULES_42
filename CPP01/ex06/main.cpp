/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:38:38 by oalananz          #+#    #+#             */
/*   Updated: 2025/07/02 14:44:22 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout<<"Invalid Arguments"<<std::endl;
        return (0);
    }
    Harl pointer;

    pointer.complain(av[1]);
    return (0);
}