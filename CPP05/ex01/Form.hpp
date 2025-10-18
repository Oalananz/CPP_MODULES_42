/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:23:32 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/15 00:28:37 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool sign;
        const int gradeToSign;
        const int gradeToExc;
    public:
        Form(const std::string name,const int gradeToSign,const int gradeToExc);
        Form();
        Form(const Form &obj);
        Form &operator=(const Form &obj);
        ~Form();
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
        void beSigned(const Bureaucrat &bureaucrat);
        std::string getName() const;
        bool getSign() const;
        int getGradeToSign() const;
        int getGradeToExc() const;
    
};
std::ostream& operator<<(std::ostream &out, const Form &obj);

#endif