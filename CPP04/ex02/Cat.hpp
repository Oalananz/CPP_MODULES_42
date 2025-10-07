/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 22:58:20 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/03 23:54:36 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *catBrain;
    public:
        Cat();
        Cat(const Cat& object);
        Cat& operator=(const Cat& obj);
        ~Cat();
        void makeSound() const;
        void setBrain(const Brain& brain);
        Brain* getBrain() const;
};

#endif