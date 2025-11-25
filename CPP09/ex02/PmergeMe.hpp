/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:15:22 by oalananz          #+#    #+#             */
/*   Updated: 2025/11/24 16:01:05 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <sys/time.h>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <time.h>

class PmergeMe {
private:
    std::list<int> listData;
    std::deque<int> dequeData;
    double listTime;
    double dequeTime;
    void mergeInsertSortList(std::list<int>& arr);
    void insertionSortList(std::list<int>& arr);
    void mergeInsertSortDeque(std::deque<int>& arr);
    void insertionSortDeque(std::deque<int>& arr, int left, int right);
    double getTime();


public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    bool parseInput(int argc, char** argv);
    void sortWithList();
    void sortWithDeque();
    void displayBefore() const;
    void displayAfter() const;
    void displayTimes() const;
};

#endif