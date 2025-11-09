/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:54:50 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/26 13:08:42 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& object);
        ScalarConverter& operator=(const ScalarConverter& obj);
        ~ScalarConverter();
    public:
        static void convert(std::string input);
};

void printInvalid();
void printDouble(double value);
void printFloat(double value);
void printInt(double value);
void printChar(double value);
bool isCharLiteral(const std::string& s);
bool isValidNumber(const std::string& s);
bool isPseudoLiteral(const std::string& s);

#endif