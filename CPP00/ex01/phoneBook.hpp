/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:38:17 by oalananz          #+#    #+#             */
/*   Updated: 2025/06/22 23:53:37 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class phoneBook {
public:
    int contactCount;
    phoneBook() : contactCount(0) {}
    ~phoneBook() {}
    void addContact();
    void findContact();
    
    private:
    struct Contact {
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
    };
    Contact contacts[8];
};

std::string formatField(const std::string& str);
int checkValidPhoneNumber(const std::string &phoneNumber);

#endif