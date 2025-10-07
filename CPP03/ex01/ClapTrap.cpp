/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 22:38:01 by oalananz          #+#    #+#             */
/*   Updated: 2025/09/28 23:00:50 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name() , hitPoints(10) , attackDamage(0) , energyPoints(10)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& object)
    : name(object.name), hitPoints(object.hitPoints), attackDamage(object.attackDamage), energyPoints(object.energyPoints)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
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
    std::cout << "ClapTrap Parameterized constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
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

void ClapTrap::setName(const std::string& name) {
    this->name = name;
}

std::string ClapTrap::getName() const {
    return this->name;
}

unsigned int ClapTrap::getHitPoints() const {
    return this->hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
    return this->energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
    return this->attackDamage;
}

void ClapTrap::setHitPoints(unsigned int hitPoints) {
    this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
    this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
    this->attackDamage = attackDamage;
}