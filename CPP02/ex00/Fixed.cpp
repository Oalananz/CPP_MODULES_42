/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:17:05 by oalananz          #+#    #+#             */
/*   Updated: 2025/08/05 17:23:16 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(const Fixed& object): fixed(object.fixed) 
{
    std::cout << "Copy constructor called" << std::endl;
}
    
Fixed::Fixed() : fixed(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj) {
        fixed = obj.fixed;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout<<"getRawBits member function called"<<std::endl;
    return fixed;
}

void Fixed::setRawBits(int const raw) 
{
    fixed = raw;
}