/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 22:38:01 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/01 19:35:04 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Default Animal")
{
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal& object) : type(object.type)
{
    std::cout << "Animal Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& obj) {
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &obj) {
        this->type = obj.type;
    }
    return *this;
}

Animal::Animal(const std::string& type) : type(type)
{
    std::cout << "Animal Parameterized constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal Sound" <<std::endl;
}

void Animal::setType(const std::string& type) {
    this->type = type;
}

std::string Animal::getType() const {
    return this->type;
}
