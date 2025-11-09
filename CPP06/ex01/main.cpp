/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:55:55 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/22 11:49:49 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data data;
    data.value = 42;
    data.name = "good morning <3";
    
    std::cout << "Original Data address: " << &data << std::endl;
    std::cout << "Original Data value: " << data.value << " ,name: " << data.name << std::endl;
    std::cout << std::endl;
    
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized Data (uintptr_t): " << raw << std::endl;
    std::cout << std::endl;
    
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data address: " << deserializedData << std::endl;
    std::cout << "Deserialized Data value: " << deserializedData->value << " ,name: " << deserializedData->name << std::endl;
    std::cout << std::endl;
     
    return 0;
}