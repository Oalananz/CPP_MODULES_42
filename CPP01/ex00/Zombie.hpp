/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:18:24 by oalananz          #+#    #+#             */
/*   Updated: 2025/06/27 19:01:25 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    private:
        std::string name; 
    public:
        void announce(void);
        Zombie(std::string name);
        ~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
    
#endif