/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:51:15 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/26 16:24:15 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& object)
{
    (void) object;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
    (void) obj;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string input)
{
    double value = 0.0;
    bool isValid = true;
    
    if (isPseudoLiteral(input))
        value = std::atof(input.c_str());
    else if (isCharLiteral(input))
        value = static_cast<double>(input[1]);
    else if (input.length() == 1 && !std::isdigit(input[0]))
        value = static_cast<double>(input[0]);
    else if (isValidNumber(input))
        value = std::atof(input.c_str());
    else
        isValid = false;

    if(!isValid)
    {
        printInvalid();
        return ;
    }
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
