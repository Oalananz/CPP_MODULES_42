/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:56:09 by oalananz          #+#    #+#             */
/*   Updated: 2025/09/28 22:51:16 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name() , hitPoints(10) , attackDamage(0) , energyPoints(10)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& object)
    : name(object.name), hitPoints(object.hitPoints), attackDamage(object.attackDamage), energyPoints(object.energyPoints)
{
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj) {
        this->name = obj.name;
        this->hitPoints = obj.hitPoints;
        this->energyPoints = obj.energyPoints;
        this->attackDamage = obj.attackDamage;
    }
    return *this;
}

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), attackDamage(0), energyPoints(10)
{
    std::cout << "Parameterized constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
    if(this->energyPoints != 0 && this->hitPoints != 0)
    {
        std::cout<<"ClapTrap " << this->name << " attacks " <<target <<", causing "<< this->attackDamage << " points of damage!"<< std::endl;
        this->energyPoints--;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->energyPoints != 0 && this->hitPoints != 0)
    {
        this->energyPoints--;
        this->hitPoints += amount;
        std::cout << "ClapTrap " << this->name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->hitPoints != 0)
    {
        if (amount >= this->hitPoints)
            this->hitPoints = 0;
        else
            this->hitPoints -= amount;
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
    }
}