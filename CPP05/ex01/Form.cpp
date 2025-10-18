/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:22:58 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/16 12:53:10 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default") , gradeToSign(50) ,gradeToExc(50)
{
    std::cout << "Form Default Constructor called" << std::endl;
    this->sign = false;
}

Form::Form(const std::string name ,const int gradeToSign,const int gradeToExc) : name(name) , gradeToSign(gradeToSign) ,gradeToExc(gradeToExc)
{
    if(gradeToSign < 1 || gradeToExc < 1)
        throw Form::GradeTooHighException();
    else if(gradeToSign > 150 || gradeToExc > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form " << this->name << " Constructor called" << std::endl;
    this->sign = false;
}

Form::Form(const Form &obj) : name(obj.name), gradeToSign(obj.gradeToSign), gradeToExc(obj.gradeToExc)
{
    std::cout << "Form copy constructor called" << std::endl;
    this->sign = obj.sign;
}

Form &Form::operator=(const Form &obj)
{
    std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &obj)
        this->sign = obj.sign;
    return (*this);
}

Form::~Form()
{
    std::cout << "Form " << this->name << " Destructor called" << std::endl;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() < this->gradeToSign)
        this->sign = true;
    else
        throw GradeTooLowException();
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getSign() const
{
    return this->sign;
}

int Form::getGradeToSign() const
{
    return this->gradeToSign;
}

int Form::getGradeToExc() const
{
    return this->gradeToExc;
}

std::ostream& operator<<(std::ostream &out, const Form &obj)
{
    out << "Form name is " << obj.getName() << ", it's grade to sign " << obj.getGradeToSign()
    << ", it's grade to execute " << obj.getGradeToExc() << ", signed : " << (obj.getSign()? "Yes" : "No") << std::endl;
    return out;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form Grade too low";
}