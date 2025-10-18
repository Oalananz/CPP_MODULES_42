/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:20:44 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/15 00:15:29 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

    // increment ,no exception
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
    
    // grade to sign is high
    std::cout << "==============================================" << std::endl;
    try
    {
        Form f1("Form1", 0, 10);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    // grade to sign is low
    std::cout << "==============================================" << std::endl;
    try
    {
        Form f2("Form2", 151, 10);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    // Bureaucrat can't sign it
    std::cout << "==============================================" << std::endl;
    try
    {
        Bureaucrat signer("signer", 100);
        Form formA("FormA", 50, 50);
        std::cout << formA;
        signer.signForm(formA);
        std::cout << formA;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    // Bureaucrat sign it
    std::cout << "==============================================" << std::endl;
    try
    {
        Bureaucrat signer2("signer2", 1);
        Form formB("FormB", 50, 50);
        std::cout << formB;
        signer2.signForm(formB);
        std::cout << formB;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}