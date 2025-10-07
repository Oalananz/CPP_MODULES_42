/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 22:59:44 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/01 18:06:40 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type()
{
    std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& object) : type(object.type)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) {
    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    if (this != &obj) {
        this->type = obj.type;
    }
    return *this;
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type)
{
    std::cout << "WrongAnimal Parameterized constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" <<std::endl;
}


void WrongAnimal::setType(const std::string& type) {
    this->type = type;
}

std::string WrongAnimal::getType() const {
    return this->type;
}