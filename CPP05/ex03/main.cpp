/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:20:44 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/16 13:43:57 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    // PresidentialPardonForm
    std::cout << "==============================================" << std::endl;
    try
    {
        Bureaucrat b1("b1", 5);
        Intern a;
        AForm *f1 = a.makeForm("presidential request","f1");
        b1.signForm(*f1);
        b1.executeForm(*f1);
        delete f1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // ShrubberyCreationForm
    std::cout << "==============================================" << std::endl;
    try
    {
        Bureaucrat b1("b1", 20);
        Intern a;
        AForm *f1 = a.makeForm("shrubbery request","f1");
        b1.signForm(*f1);
        b1.executeForm(*f1);
        delete f1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // RobotomyRequestForm
    std::cout << "==============================================" << std::endl;
    try
    {
        Bureaucrat b1("b1", 50);
        Intern a;
        AForm *f1 = a.makeForm("robotomy request","f1");
        b1.signForm(*f1);
        b1.executeForm(*f1);
        delete f1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Wrong type
    std::cout << "==============================================" << std::endl;
    try
    {
        Bureaucrat b1("b1", 50);
        Intern a;
        AForm *f1 = a.makeForm("abuYahya","f1");
        b1.signForm(*f1);
        b1.executeForm(*f1);
        delete f1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}