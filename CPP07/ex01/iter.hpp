/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:03:24 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/22 12:46:13 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void printData(T data)
{
    std::cout << data << std::endl;
}

template <typename T>
void increment(T &data)
{
    data++;
}

template <typename T>
void decrement(T &data)
{
    data--;
}

template <typename T, typename F>
void iter(T* address, const size_t length, F fun)
{
    for (size_t i = 0; i < length; ++i)
        fun(address[i]);
}


#endif