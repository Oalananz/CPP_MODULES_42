/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:18:24 by oalananz          #+#    #+#             */
/*   Updated: 2025/06/27 20:58:40 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <sstream>
#include <string>

class Zombie {
    private:
        std::string name; 
    public:
        void announce(void);
        ~Zombie();
        void setName(std::string name) {
            this->name = name;
        }
};

Zombie* zombieHorde( int N, std::string name );
    
#endif