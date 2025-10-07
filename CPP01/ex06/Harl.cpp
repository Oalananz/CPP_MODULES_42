/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:36:27 by oalananz          #+#    #+#             */
/*   Updated: 2025/07/02 14:53:12 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug()
{
    std::cout<<CYAN"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"RESET<<std::endl;
}

void Harl::info()
{
    std::cout<<GREEN"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"RESET<<std::endl;
}

void Harl::warning()
{
    std::cout<<MAGENTA"I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."RESET<<std::endl;
}

void Harl::error()
{
    std::cout<<RED"This is unacceptable! I want to speak to the manager now."RESET<<std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*pointer[4]) () = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for(int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
                std::cout<<"[ " + level + " ]"<<std::endl;
                switch (i)
                {
                    case 0:
                        (this->*pointer[0])();
                    case 1:
                        (this->*pointer[1])();
                    case 2:
                        (this->*pointer[2])();
                    case 3:
                        (this->*pointer[3])();
                        break;
                }
                return;
        }
    }
    std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
}