/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 03:20:53 by oalananz          #+#    #+#             */
/*   Updated: 2025/06/22 23:54:09 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

void phoneBook::addContact() {
    phoneBook::Contact contact;
    std::cout << "Enter contact The First name: ";
    std::getline(std::cin,  contact.firstName);
    if (contact.firstName.empty() || std::isdigit(contact.firstName[0])) {
        std::cout << "First name cannot be empty or start with a digit." << std::endl;
        return;
    }
    std::cout << "Enter contact last name: ";
    std::getline(std::cin, contact.lastName);
    if (contact.lastName.empty() || std::isdigit(contact.lastName[0])) {
        std::cout << "Last name cannot be empty or start with a digit." << std::endl;
        return;
    }
    std::cout << "Enter contact nickname: ";
    std::getline(std::cin, contact.nickname);
    if (contact.nickname.empty() || std::isdigit(contact.nickname[0])) {
        std::cout << "Nickname cannot be empty or start with a digit." << std::endl;
        return;
    }
    std::cout << "Enter contact phone number: ";
    std::getline(std::cin, contact.phoneNumber);
    if(checkValidPhoneNumber(contact.phoneNumber))
    {
        std::cout << "Invalid phone number." << std::endl;
        return;
    }
    std::cout << "Enter contact darkest secret: ";
    std::getline(std::cin, contact.darkestSecret);
    if (contact.darkestSecret.empty() || std::isdigit(contact.darkestSecret[0])) {
        std::cout << "Darkest secret cannot be empty or start with a digit." << std::endl;
        return;
    }
    if (contactCount >= 8) {
        std::cout << "Phone book is full. Overwriting the oldest contact." << std::endl;
        contacts[0] = contact;
        return;
    }
    contacts[contactCount] = contact;
    contactCount++;
}

void phoneBook::findContact() {
    if (contactCount == 0) {
        std::cout << "No contacts available." << std::endl;
        return;
    }
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < contactCount; ++i) {
        std::cout << std::setw(10) << i << "|"
                  << formatField(contacts[i].firstName) << "|"
                  << formatField(contacts[i].lastName) << "|"
                  << formatField(contacts[i].nickname) << std::endl;
    }
    std::cout << "Enter the index of the contact to display: ";
    std::string input;
    std::getline(std::cin, input);
    if (input.empty() || input.find_first_not_of("0123456789") != std::string::npos) {
        std::cout << "Invalid index input." << std::endl;
        return;
    }
    int idx = -1;
    std::istringstream iss(input);
    iss >> idx;
    if (iss.fail() || idx < 0 || idx >= contactCount) {
        std::cout << "Index out of range." << std::endl;
        return;
    }
    std::cout << "First Name: " << contacts[idx].firstName << std::endl;
    std::cout << "Last Name: " << contacts[idx].lastName << std::endl;
    std::cout << "Nickname: " << contacts[idx].nickname << std::endl;
    std::cout << "Phone Number: " << contacts[idx].phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << contacts[idx].darkestSecret << std::endl;
}
