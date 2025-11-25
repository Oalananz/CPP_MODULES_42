/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:09:04 by oalananz          #+#    #+#             */
/*   Updated: 2025/11/24 15:53:28 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <ctime>

bitcoinExchange::bitcoinExchange() : infile("") , data("data.csv") {}

bitcoinExchange::~bitcoinExchange() {}

bitcoinExchange::bitcoinExchange(std::string file) : infile(file) , data("data.csv") {}

bitcoinExchange::bitcoinExchange(const bitcoinExchange& obj) : infile(obj.infile){}

bitcoinExchange& bitcoinExchange::operator=(const bitcoinExchange &obj) 
{
    if(this->infile != obj.infile)
        this->infile = obj.infile;    
    return *this;    
}

void bitcoinExchange::readData(std::string file)
{
    std::string line;
    std::ifstream inputFile(file.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: could not open file " << file << std::endl;
        return;
    }
    this->lines.clear();
    while (std::getline(inputFile, line))
        this->lines.push_back(line);
    inputFile.close();
}

void bitcoinExchange::parseData()
{
    bitcoinExchange::readData(this->data);
    
    if (this->lines.empty())
    {
        std::cerr << "Error: no data to parse" << std::endl;
        return ;
    }
    for(size_t i = 1; i < this->lines.size(); i++)
    {
        size_t commaPos = this->lines[i].find(',');
        if (commaPos != std::string::npos)
        {
            std::string date = this->lines[i].substr(0, commaPos);
            std::string value_str = this->lines[i].substr(commaPos + 1);
            float value;
            std::stringstream ss(value_str);
            if (ss >> value)
                this->splitedData[date] = value;
        }
    }
}

void bitcoinExchange::parseInput()
{
    bitcoinExchange::readData(this->infile);
    
    if (this->lines.empty())
    {
        std::cerr << "Error: no data to parse" << std::endl;
        return ;
    }
    for(size_t i = 1; i < this->lines.size(); i++)
    {
        size_t pipePos = this->lines[i].find('|');
        if (pipePos != std::string::npos)
        {
            std::string date = this->lines[i].substr(0, pipePos);
            std::string value_str = this->lines[i].substr(pipePos + 1);
            float value;
            std::stringstream ss(value_str);
            if (ss >> value)
                this->splitedInput.push_back(std::make_pair(date, value));
        }
        else
            this->splitedInput.push_back(std::make_pair(this->lines[i], 0));
    }
    
}

bool bitcoinExchange::validateInput(int index)
{
    std::string date = this->splitedInput[index].first;
    size_t start = date.find_first_not_of(" \t");
    size_t end = date.find_last_not_of(" \t");
    if (start != std::string::npos && end != std::string::npos)
        date = date.substr(start, end - start + 1);
    
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    int year, month, day;
    std::stringstream ss_year(date.substr(0, 4));
    std::stringstream ss_month(date.substr(5, 2));
    std::stringstream ss_day(date.substr(8, 2));
    
    if (!(ss_year >> year) || !(ss_month >> month) || !(ss_day >> day))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }
    
    if (month > 12 || month < 1 || year < 2009)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;
    
    if (day < 1 || day > daysInMonth[month - 1])
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    float num = this->splitedInput[index].second;
    if (num < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (num > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }   
    return true;
}


void bitcoinExchange::calculatePrice()
{
    parseData();
    parseInput();
    for (size_t i = 0; i < this->splitedInput.size(); i++)
    {
        if (validateInput(i) == false)
            continue;
        std::string inputDate = this->splitedInput[i].first.substr(0, 10);
        std::map<std::string, float>::iterator it = this->splitedData.upper_bound(inputDate);
        
        if (it == this->splitedData.begin())
        {
            std::cout << "Error: no earlier date found => " << inputDate << std::endl;
            continue;
        }
        --it;
        float price = it->second * this->splitedInput[i].second;
        std::cout << inputDate << " => " << this->splitedInput[i].second << " = " << price << std::endl;
    }
}




