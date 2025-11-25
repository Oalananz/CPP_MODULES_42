/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:29:22 by oalananz          #+#    #+#             */
/*   Updated: 2025/11/18 18:12:01 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<int> nums; 
    public:
        RPN();
        ~RPN();
        RPN &operator=(const RPN&);
        RPN(const RPN&);
        void calculate(std::string);
};



#endif