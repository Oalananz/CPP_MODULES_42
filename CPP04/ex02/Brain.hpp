/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:52:38 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/01 20:37:10 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>


class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const std::string* ideas , int size);
        Brain(const Brain& object);
        Brain& operator=(const Brain& obj);
        ~Brain();
        std::string getIdea(int index) const;

};




#endif