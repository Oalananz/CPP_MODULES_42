/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:18:15 by oalananz          #+#    #+#             */
/*   Updated: 2025/06/27 21:06:56 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << name << " : Zombie killed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << " : Moar brainz!" << std::endl;
}
