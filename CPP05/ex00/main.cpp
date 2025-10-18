/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:20:44 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/14 23:19:24 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    // grade between 1 and 150 , no exceptions
    try
    {
        Bureaucrat first("first", 10);
        std::cout << first;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }    
    
    // grade higher than 150 ,exception
    std::cout << "==============================================" << std::endl;
    try
    {
        Bureaucrat second("second", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    // grade lower than 1 ,exception
    std::cout << "==============================================" << std::endl;
    try
    {
        Bureaucrat third("third", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // decrement exception
    std::cout << "==============================================" << std::endl;
    try
    {
        Bureaucrat fourth("fourth", 150);
        fourth.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // increment exception
    std::cout << "==============================================" << std::endl;
    try
    {
        Bureaucrat fifth("fifth", 1);
        fifth.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "==============================================" << std::endl;
    try
    {
        Bureaucrat sixth("sixth", 3);
        std::cout << sixth;
        sixth.incrementGrade();
        std::cout << sixth;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}