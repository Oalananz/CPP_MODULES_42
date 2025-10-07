/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:16:45 by oalananz          #+#    #+#             */
/*   Updated: 2025/06/27 21:19:49 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout<<"The memory address of brain = " <<&brain<<std::endl;
    std::cout<<"The memory address of stringPTR = " <<stringPTR<<std::endl;
    std::cout<<"The memory address of stringREF = " <<&stringREF<<std::endl;
    std::cout<<std::endl;
    std::cout<<"The value of the string brain = " <<brain<<std::endl;
    std::cout<<"The value pointed to by stringPTR = " <<*stringPTR<<std::endl;
    std::cout<<"The value pointed to by stringREF = " <<stringREF<<std::endl;
    
    return 0;
}
