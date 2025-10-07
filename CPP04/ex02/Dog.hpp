/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:20:28 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/03 23:54:39 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *dogBrain;
    public:
        Dog();
        Dog(const Dog& object);
        Dog& operator=(const Dog& obj);
        ~Dog();
        void makeSound() const;
        void setBrain(const Brain& brain);
        Brain* getBrain() const;
};

#endif