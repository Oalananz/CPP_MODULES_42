/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:20:28 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/01 18:00:38 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"

class WrongAnimal
{
    protected:
       std::string type; 
    public:
        WrongAnimal();
        WrongAnimal(const std::string& type);
        WrongAnimal(const WrongAnimal& object);
        WrongAnimal& operator=(const WrongAnimal& obj);
        ~WrongAnimal();
        void setType(const std::string& type);
        std::string getType() const;
        void makeSound() const ;
};

#endif