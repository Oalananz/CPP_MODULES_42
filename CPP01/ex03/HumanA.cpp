/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:43:08 by oalananz          #+#    #+#             */
/*   Updated: 2025/06/27 22:06:53 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void    HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;   
}

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}
