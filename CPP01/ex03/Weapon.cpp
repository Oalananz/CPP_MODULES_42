/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:34:47 by oalananz          #+#    #+#             */
/*   Updated: 2025/06/27 22:05:55 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string Weapon::getType()
{
    return this->type;
}

Weapon::Weapon(std::string type) : type(type) {}

void   Weapon::setType(std::string type)
{
    this->type = type;
}
