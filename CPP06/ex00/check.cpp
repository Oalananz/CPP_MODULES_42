/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:07:31 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/26 13:07:47 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isPseudoLiteral(const std::string& s)
{
    return (s == "nan" || s == "nanf" ||
            s == "+inf" || s == "-inf" ||
            s == "+inff" || s == "-inff" ||
            s == "inf" || s == "inff");
}

bool isValidNumber(const std::string& s)
{
    if (s.empty())
        return false;
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    bool hasDigit = false;
    bool hasDot = false;
    while (i < s.length() && s[i] != 'f') {
        if (std::isdigit(s[i]))
            hasDigit = true;
        else if (s[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else
            return false;
        i++;
    }
    
    if (i < s.length() && s[i] == 'f')
        i++;
    
    return hasDigit && i == s.length();
}

bool isCharLiteral(const std::string& s)
{
    return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}
