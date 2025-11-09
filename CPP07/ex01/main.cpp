/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:18:11 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/22 12:49:31 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <iostream>


int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    std::string strArray[] = {"Hello", "osamah", "World", "!", "!??"};
    std::cout << "-------------int---------------" << std::endl;
    iter<int>(intArray, 5, printData<int>);
    std::cout << "------------float--------------" << std::endl;
    iter<float>(floatArray, 5, printData<float>);
    std::cout << "------------string-------------" << std::endl;
    iter<std::string>(strArray, 5, printData<std::string>);
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Increment ints:\n";
    iter<int>(intArray, 5, increment<int>);
    iter<int>(intArray, 5, printData<int>);
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Decrement floats:\n";
    iter<float>(floatArray, 5, decrement<float>);
    iter<float>(floatArray, 5, printData<float>);
    return 0;
}