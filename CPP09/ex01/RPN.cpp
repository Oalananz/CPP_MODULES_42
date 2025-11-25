/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:38:30 by oalananz          #+#    #+#             */
/*   Updated: 2025/11/24 15:57:47 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN&obj)
{
    (void) obj;
    return *this;
}

RPN::RPN(const RPN&obj)
{
    (void) obj;
}

bool validateInput(std::string data)
{
    for(int i = 0;data[i];i++)
    {
        if(data[i] == '(' || data[i] == ')')
        {
            std::cout << "Error: Paranthesis not allowed" << std::endl;
            return false;
        }
        else if(isalpha(data[i]))
        {
            std::cout << "Error: Alphabetic characters not allowed" << std::endl;
            return false;
        }
    }
    return true;
}

void RPN::calculate(std::string data)
{
    if(data.empty())
    {
        std::cout << "Error: Empty String" << std::endl;
        return ;
    }
    if(validateInput(data) == true)
    {
        
        for(int i = 0;data[i];i++)
        {
            if(isdigit(data[i]))
                this->nums.push(data[i] - '0');
            else if(data[i] == '+' || data[i] == '-'
                || data[i] == '/' || data[i] == '*')
            {
                if(this->nums.empty() || this->nums.size() == 1)
                {
                    std::cout << "Error: Not enough operands" << std::endl;
                    return ;
                }
                int x = this->nums.top();
                this->nums.pop();
                int y = this->nums.top();
                this->nums.pop();
                if(data[i] == '+')            
                    this->nums.push(y + x);
                else if(data[i] == '-')
                    this->nums.push(y - x);
                else if(data[i] == '*')
                    this->nums.push(y * x);
                else if(data[i] == '/' && x != 0)
                    this->nums.push(y / x);
                else
                {
                    std::cout << "Error: Division by zero" << std::endl;
                    return ;
                }
            }
        }
        if(this->nums.size() > 1)
        {
            std::cout << "Error: Too many operands" << std::endl;
            return ; 
        }
        std::cout << this->nums.top() << std::endl;
    }
    
}


