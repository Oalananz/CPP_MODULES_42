/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:32:11 by oalananz          #+#    #+#             */
/*   Updated: 2025/06/27 21:48:42 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>


class Weapon {
    private:
        std::string type;
    public:
        std::string getType();
        Weapon(std::string type);
        void  setType(std::string type);
};

#endif