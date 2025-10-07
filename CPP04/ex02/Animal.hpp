/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:15:40 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/04 12:32:23 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>


class Animal
{
    protected:
       std::string type; 
    public:
        Animal();
        Animal(const std::string& type);
        Animal(const Animal& object);
        Animal& operator=(const Animal& obj);
        virtual ~Animal();
        void setType(const std::string& type);
        std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif