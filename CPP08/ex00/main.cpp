/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:01:48 by oalananz          #+#    #+#             */
/*   Updated: 2025/11/14 00:00:48 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    try
    {
        std::list<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(5);
        std::list<int>::iterator i = ::easyfind(v1,2);
        std::cout << "List -> found = " << *i << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Not Found" << std::endl;
    }
    
    try
    {
        std::vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(5);
        std::vector<int>::iterator i =  ::easyfind(v1,4);
        std::cout << "Vector -> found = " << *i << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Not Found" << std::endl;
    }
}