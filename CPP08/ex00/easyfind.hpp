/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:02:25 by oalananz          #+#    #+#             */
/*   Updated: 2025/11/13 14:28:30 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <list>
#include <vector>


template <typename T>
typename T::iterator easyfind(T& container , int num)
{
    typename T::iterator i;
    
    for(i = container.begin(); i != container.end(); ++i)
    {
        if(*i == num)
            return i;
    }
    throw std::exception();
}

#endif