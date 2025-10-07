/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:56:12 by oalananz          #+#    #+#             */
/*   Updated: 2025/09/28 22:41:39 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
int main() {
    ClapTrap clap1;
    ClapTrap clap2("osamah");
    ClapTrap clap3(clap2);
    clap1 = clap3;
    clap1.attack("Enemy1");
    clap2.attack("Enemy2");
    clap3.beRepaired(5);
    clap2.takeDamage(3);
    clap1.takeDamage(15);
    
    return 0;
}
