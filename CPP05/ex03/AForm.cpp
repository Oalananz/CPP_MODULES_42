/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:22:58 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/16 13:35:09 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default") , gradeToSign(50) ,gradeToExc(50)
{
    std::cout << "AForm Default Constructor called" << std::endl;
    this->sign = false;
}

AForm::AForm(const std::string name ,const int gradeToSign,const int gradeToExc) : name(name) , gradeToSign(gradeToSign) ,gradeToExc(gradeToExc)
{
    if(gradeToSign < 1 || gradeToExc < 1)
        throw AForm::GradeTooHighException();
    else if(gradeToSign > 150 || gradeToExc > 150)
        throw AForm::GradeTooLowException();
    std::cout << "AForm " << this->name << " Constructor called" << std::endl;
    this->sign = false;
}

AForm::AForm(const AForm &obj) : name(obj.name), gradeToSign(obj.gradeToSign), gradeToExc(obj.gradeToExc)
{
    std::cout << "AForm copy constructor called" << std::endl;
    this->sign = obj.sign;
}

AForm &AForm::operator=(const AForm &obj)
{
    std::cout << "AForm copy assignment operator called" << std::endl;
    this->sign = obj.sign;
    return (*this);
}

AForm::~AForm()
{
    std::cout << "AForm " << this->name << " Destructor called" << std::endl;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() < this->gradeToSign)
        this->sign = true;
    else
        throw GradeTooLowException();
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getSign() const
{
    return this->sign;
}

int AForm::getGradeToSign() const
{
    return this->gradeToSign;
}

int AForm::getGradeToExc() const
{
    return this->gradeToExc;
}

std::ostream& operator<<(std::ostream &out, const AForm &obj)
{
    out << "AForm name is " << obj.getName() << ", it's grade to sign " << obj.getGradeToSign()
    << ", it's grade to execute " << obj.getGradeToExc() << ", signed : " << (obj.getSign()? "Yes" : "No") << std::endl;
    return out;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm Grade too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form Not signed";
}

const char *AForm::CannotOpenFileException::what() const throw()
{
    return "Cannot open file";
}

const char *AForm::RobotomyFailedException::what() const throw()
{
    return "Robotomy failed";
}

void AForm::checkExecution(Bureaucrat const& executor) const {
    if (!this->getSign())
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExc)
        throw GradeTooLowException();
}
