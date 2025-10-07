/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:17:01 by oalananz          #+#    #+#             */
/*   Updated: 2025/08/05 17:21:26 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int fixed;
    static const int bits = 8;
    
public:
    Fixed();
    Fixed(const Fixed& object);
    Fixed& operator=(const Fixed& obj);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif