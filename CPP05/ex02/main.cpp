/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:20:44 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/16 13:16:12 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    // PresidentialPardonForm
    std::cout << "==============================================" << std::endl;
    try
    {
        Bureaucrat b1("b1", 10);
        PresidentialPardonForm f1("f1");
        b1.signForm(f1);
        b1.executeForm(f1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // ShrubberyCreationForm
    std::cout << "==============================================" << std::endl;
    try
    {
        Bureaucrat b1("b1", 3);
        ShrubberyCreationForm f1("f1");
        b1.signForm(f1);
        b1.executeForm(f1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // RobotomyRequestForm
    std::cout << "==============================================" << std::endl;
    try
    {
        Bureaucrat b1("b1", 3);
        RobotomyRequestForm f1("f1");
        b1.signForm(f1);
        b1.executeForm(f1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}