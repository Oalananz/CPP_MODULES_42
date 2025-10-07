/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:36:32 by oalananz          #+#    #+#             */
/*   Updated: 2025/06/22 23:53:58 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

std::string formatField(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}

int checkValidPhoneNumber(const std::string &phoneNumber) {
    if (phoneNumber.empty() || phoneNumber.length() != 10) {
        return 1;
    }
    int length = phoneNumber.length();
    for (int i = 0; i < length; i++) {
        if (!std::isdigit(phoneNumber[i])) {
            return 1;
        }
    }
    return 0;
}

int main() {
    phoneBook phoneBook;
    phoneBook.contactCount = 0;
    while (1)
    {
        std::string operation;
        std::cout << "Please enter an operation (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, operation);
        
        if(operation == "ADD") {
            phoneBook.addContact();
        }
        else if(operation == "SEARCH") {
            phoneBook.findContact();
        }
        else if(operation == "EXIT") {
            break;
        }
        else {
            std::cout << "Invalid operation. Please enter ADD, SEARCH, or EXIT." << std::endl;
        } 
    }
    return 0;
}

