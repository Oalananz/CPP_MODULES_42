/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:51:16 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/16 13:02:47 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm" , 72 , 45) , target("Default")
{
    std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target , 72 , 45) , target(target)
{
    std::cout << "RobotomyRequestForm " << this->target << " Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : target(obj.target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    if(this != &obj)
        this->target = obj.target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm " << this->target << " Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSign())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExc())
        throw GradeTooLowException();
    std::srand(time(NULL));
    if (!(std::rand() % 2))
        throw RobotomyFailedException();
    std::cout << this->target <<" has been robotomized successfully" << std::endl;
}