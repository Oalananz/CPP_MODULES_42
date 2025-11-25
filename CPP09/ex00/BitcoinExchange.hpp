/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:30:56 by oalananz          #+#    #+#             */
/*   Updated: 2025/11/18 16:58:12 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <sstream>
#include <limits>


class bitcoinExchange
{
    private:
        std::string infile;
        std::string data;
        std::vector<std::string> lines;
        std::vector<std::pair<std::string, float> > splitedInput;
        std::map<std::string , float> splitedData;
        void readData(std::string); 
        void parseData();
        void parseInput();
        bool validateInput(int);
        
    public:
        bitcoinExchange();
        ~bitcoinExchange();
        bitcoinExchange(std::string);
        bitcoinExchange &operator=(const bitcoinExchange&);
        bitcoinExchange(const bitcoinExchange&);  
        void calculatePrice();
};

#endif