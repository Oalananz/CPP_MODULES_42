/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:17:05 by oalananz          #+#    #+#             */
/*   Updated: 2025/08/06 17:02:46 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(const Fixed& object): fixed(object.fixed) {}

Fixed::Fixed(const int num)
{
    fixed = num << bits;
}

int Fixed::toInt() const
{
    return fixed >> bits;
}

Fixed::Fixed(const float numb)
{
    fixed = roundf(numb * (1 << bits));
}

float Fixed::toFloat() const
{
    return static_cast<float>(fixed) / (1 << bits);
}

Fixed::Fixed() : fixed(0) {}

Fixed& Fixed::operator=(const Fixed& obj) {
    if (this != &obj) {
        fixed = obj.fixed;
    }
    return *this;
}

Fixed::~Fixed() {}

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


bool Fixed::operator>(const Fixed& fixed) const
{
    return this->fixed > fixed.fixed;   
}

bool Fixed::operator<(const Fixed& fixed) const
{
    return this->fixed < fixed.fixed;
}

bool Fixed::operator>=(const Fixed& fixed) const
{
    return this->fixed >= fixed.fixed;
}

bool Fixed::operator<=(const Fixed& fixed) const
{
    return this->fixed <= fixed.fixed;
}

bool Fixed::operator==(const Fixed& fixed) const
{
    return this->fixed == fixed.fixed;
}

bool Fixed::operator!=(const Fixed& fixed) const
{
    return this->fixed != fixed.fixed;
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
    return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed& Fixed::operator++()
{
    ++fixed;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--()
{
    --fixed;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --(*this);
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

