/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:25:34 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/16 13:46:47 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &obj)
{
    (void) obj;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &obj)
{
    std::cout << "Intern copy assignment operator called" << std::endl;
    (void) obj;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called" << std::endl;
}

const char *Intern::WrongTypeException::what() const throw()
{
    return "Wrong Form type \ntry one of these : (\"presidential request\", \"robotomy request\", \"shrubbery request\")";
}

AForm *Intern::makeForm(std::string type , std::string target)
{
    if(type == "presidential request")
        return new PresidentialPardonForm(target);
    else if(type == "robotomy request")
        return new RobotomyRequestForm(target);
    else if(type == "shrubbery request")
        return new ShrubberyCreationForm(target);
    else
        throw WrongTypeException();
}
