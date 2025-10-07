/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:30:00 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/01 20:44:32 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    this->dogBrain = new Brain();
    this->type = "Dog";
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog& object) : Animal(object) {
    this->dogBrain = new Brain(*object.dogBrain);
    this->type = object.type;
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& obj) {
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &obj) {
        this->type = obj.type;
        delete this->dogBrain;
        this->dogBrain = new Brain(*obj.dogBrain);
    }
    return *this;
}

Dog::~Dog() {
    delete this->dogBrain;
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Bark 3o 3o" << std::endl;
}

Brain* Dog::getBrain() const {
    return this->dogBrain;
}

void Dog::setBrain(const Brain& brain) {
    *this->dogBrain = brain;
}
