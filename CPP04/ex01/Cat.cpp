/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 22:59:44 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/01 20:44:11 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"

Cat::Cat() {
    this->catBrain = new Brain();
    this->type = "Cat";
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat& object) : Animal(object) {
    this->catBrain = new Brain(*object.catBrain);
    this->type = object.type;
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& obj) {
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &obj) {
        this->type = obj.type;
        delete this->catBrain;
        this->catBrain = new Brain(*obj.catBrain);
    }
    return *this;
}

Cat::~Cat() {
    delete this->catBrain;
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow Meow" << std::endl;
}

Brain* Cat::getBrain() const {
    return this->catBrain;
}

void Cat::setBrain(const Brain& brain) {
    *this->catBrain = brain;
}
