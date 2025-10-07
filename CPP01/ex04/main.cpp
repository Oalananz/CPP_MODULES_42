/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 22:22:34 by oalananz          #+#    #+#             */
/*   Updated: 2025/07/02 17:16:48 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main (int ac, char **av)
{
    if(ac != 4)
    {
        std::cout<<"./Replace filename String1 String2"<<std::endl;
        return 1;
    }
    std::string filename = std::string(av[1]) + ".replace";
    std::ifstream file(av[1]);
    if (!file.is_open()) {
        std::cout << "Failed to open file."<<std::endl;;
        return 1;
    }
    std::ofstream fileR(filename.c_str());
    if (!fileR.is_open()) {
        std::cout << "Failed to open." << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(file, line)) {
        for(int i = 0; line[i] ; i++)
        {
            std::size_t found = line.find(av[2],i);
            if(static_cast<int>(found) == i)
            {
                for(int j = 0;av[3][j]; j++)
                {
                    fileR << av[3][j];
                }
                std::string cppstr(av[2]);
                i +=  cppstr.length() - 1;
            }
            else
                fileR << line[i];
        }
        fileR << std::endl;
    }
    fileR.close();
    file.close();
}
