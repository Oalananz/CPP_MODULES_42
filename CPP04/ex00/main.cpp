/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:22:36 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/21 18:25:29 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* o = new Cat();
    const WrongAnimal* i = new WrongCat();
   
    std::cout << meta->getType() << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << o->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    o->makeSound();
    meta->makeSound();
    
    delete meta;
    delete o;
    delete i;
    delete j;
    return (0);
}