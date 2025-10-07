/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:36:27 by oalananz          #+#    #+#             */
/*   Updated: 2025/07/02 14:55:14 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug()
{
    std::cout<<CYAN"[DEBUG] \'I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\'"RESET<<std::endl;
}

void Harl::info()
{
    std::cout<<GREEN"[INFO] \'I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\'"RESET<<std::endl;
}

void Harl::warning()
{
    std::cout<<MAGENTA"[WARNING] \'I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\'"RESET<<std::endl;
}

void Harl::error()
{
    std::cout<<RED"[ERROR] \'This is unacceptable! I want to speak to the manager now.\'"RESET<<std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*pointer[4]) () = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for(int i = 0; i < 4; i++)
    {
        if (level == levels[i]) {
                (this->*pointer[i])();
                return;
            }
    }
    std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
}