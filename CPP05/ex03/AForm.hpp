/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:23:32 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/15 00:23:57 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string name;
        bool sign;
        const int gradeToSign;
        const int gradeToExc;
    public:
        AForm(const std::string name,const int gradeToSign,const int gradeToExc);
        AForm();
        AForm(const AForm &obj);
        AForm &operator=(const AForm &obj);
        virtual ~AForm();
        class GradeTooHighException : public std::exception
        {
          public:
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
          public:
            const char* what() const throw();
        };
        class FormNotSignedException : public std::exception
        {
          public:
            const char* what() const throw();
        };
        class CannotOpenFileException : public std::exception
        {
          public:
            const char* what() const throw();
        };
        class RobotomyFailedException : public std::exception
        {
          public:
            const char* what() const throw();
        };
  
        void beSigned(const Bureaucrat &bureaucrat);
        std::string getName() const;
        bool getSign() const;
        int getGradeToSign() const;
        int getGradeToExc() const;
        virtual void execute(Bureaucrat const & executor) const = 0;
        void checkExecution(Bureaucrat const& executor) const;
    
};
std::ostream& operator<<(std::ostream &out, const AForm &obj);

#endif