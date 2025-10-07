/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:15:25 by oalananz          #+#    #+#             */
/*   Updated: 2025/06/27 22:27:53 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if(N <= 0)
    {
        std::cout << "Error: Number of zombies must be greater than 0." << std::endl;
        return NULL;
    }
    Zombie* horde = new Zombie[N];
    for(int i = 0; i < N; ++i)
    {
        std::stringstream ss;
        ss << (i + 1);
        horde[i].setName(name + " " + ss.str());
        horde[i].announce();
    }
    return horde;
}