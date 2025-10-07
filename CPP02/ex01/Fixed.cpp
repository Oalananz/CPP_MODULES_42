/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:17:05 by oalananz          #+#    #+#             */
/*   Updated: 2025/08/05 17:56:53 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(const Fixed& object): fixed(object.fixed) 
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
    std::cout<<"Float constructor called"<<std::endl;
    fixed = num << bits;
}

int Fixed::toInt() const
{
    return fixed >> bits;
}

Fixed::Fixed(const float numb)
{
    std::cout<<"Int constructor called"<<std::endl;
    fixed = roundf(numb * (1 << bits));
}

float Fixed::toFloat() const
{
    return static_cast<float>(fixed) / (1 << bits);
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
    return fixed;
}

void Fixed::setRawBits(int const raw) 
{
    fixed = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
