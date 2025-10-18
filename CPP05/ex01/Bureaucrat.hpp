/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:27:40 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/15 00:25:27 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat &operator=(const Bureaucrat &obj);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
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
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &form);
};
std::ostream& operator<<(std::ostream &out, const Bureaucrat &obj);

#endif 