/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:15:14 by oalananz          #+#    #+#             */
/*   Updated: 2025/11/24 17:17:43 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : listTime(0), dequeTime(0) {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
    *this = obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
    if (this != &obj) {
        listData = obj.listData;
        dequeData = obj.dequeData;
        listTime = obj.listTime;
        dequeTime = obj.dequeTime;
    }
    return *this;
}

double PmergeMe::getTime()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000000.0 + ts.tv_nsec / 1000.0;
}

bool PmergeMe::parseInput(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Error: Missing arguments" << std::endl;
        return false;
    }

    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        
        if (arg.empty()) {
            std::cout << "Error: Empty argument" << std::endl;
            return false;
        }

        for (size_t j = 0; j < arg.length(); j++)
        {
            if (!isdigit(arg[j]))
            {
                std::cout << "Error: Invalid character in argument" << std::endl;
                return false;
            }
        }

        std::istringstream iss(arg);
        long num;
        iss >> num;

        if (num < 0 || num > 2147483647)
        {
            std::cout << "Error: Out of range" << std::endl;
            return false;
        }

        listData.push_back(num);
        dequeData.push_back(num);
    }

    return true;
}

void PmergeMe::displayBefore() const
{
    std::cout << "Before: ";
    
    for (std::list<int>::const_iterator it = listData.begin(); it != listData.end(); ++it)
    {
        if (it != listData.begin())
            std::cout << " ";
        std::cout << *it;
    }
    std::cout << std::endl;
}

void PmergeMe::displayAfter() const
{
    std::cout << "After:  ";
    
    for (std::list<int>::const_iterator it = listData.begin(); it != listData.end(); ++it)
    {
        if (it != listData.begin())
            std::cout << " ";
        std::cout << *it;
    }
    std::cout << std::endl;
}

void PmergeMe::displayTimes() const
{
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << listData.size() 
              << " elements with std::list : " << listTime << " us" << std::endl;
    std::cout << "Time to process a range of " << dequeData.size() 
              << " elements with std::deque : " << dequeTime << " us" << std::endl;
}

void PmergeMe::insertionSortList(std::list<int>& arr)
{
    if (arr.size() <= 1)
        return;
    
    for (std::list<int>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        std::list<int>::iterator key_it = it;
        int key = *key_it;
        std::list<int>::iterator j = key_it;
        
        while (j != arr.begin())
        {
            std::list<int>::iterator prev = j;
            --prev;
            if (*prev <= key)
                break;
            j = prev;
        }
        
        if (j != key_it)
        {
            arr.erase(key_it);
            arr.insert(j, key);
        }
    }
}

void PmergeMe::mergeInsertSortList(std::list<int>& arr)
{
    size_t n = arr.size();
    
    if (n <= 1)
        return;

    std::list<int> larger;
    std::list<int> smaller;
    int straggler = -1;
    bool hasStraggler = false;

    std::list<int>::iterator it = arr.begin();
    while (it != arr.end())
    {
        std::list<int>::iterator first = it++;
        if (it == arr.end())
        {
            straggler = *first;
            hasStraggler = true;
            break;
        }
        std::list<int>::iterator second = it++;
        
        if (*first > *second)
        {
            larger.push_back(*first);
            smaller.push_back(*second);
        }
        else
        {
            larger.push_back(*second);
            smaller.push_back(*first);
        }
    }

    if (!larger.empty())
    {
        mergeInsertSortList(larger);
    }

    std::list<int> result = larger;
    
    if (smaller.empty())
    {
        arr = result;
        return;
    }
    
    std::list<int>::iterator first_elem = smaller.begin();
    int first_value = *first_elem;
    std::list<int>::iterator pos_it = result.begin();
    while (pos_it != result.end() && *pos_it < first_value)
        ++pos_it;
    result.insert(pos_it, first_value);
    
    std::deque<size_t> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    size_t jacob_size = 1;
    while (jacob_size < smaller.size())
    {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
        jacob_size = next;
    }
    
    std::deque<size_t> insertion_order;
    for (size_t i = 2; i < jacobsthal.size(); i++)
    {
        size_t current = jacobsthal[i];
        if (current > smaller.size())
            current = smaller.size();
        
        for (size_t j = current; j > jacobsthal[i - 1] && j > 0; j--)
        {
            if (j - 1 > 0)
                insertion_order.push_back(j - 1);
        }
        
        if (current >= smaller.size())
            break;
    }
    
    for (size_t i = 0; i < insertion_order.size(); i++)
    {
        size_t idx = insertion_order[i];
        if (idx >= smaller.size())
            continue;
        
        std::list<int>::iterator small_it = smaller.begin();
        std::advance(small_it, idx);
        int value = *small_it;

        std::list<int>::iterator pos_it2 = result.begin();
        while (pos_it2 != result.end() && *pos_it2 < value)
            ++pos_it2;
        result.insert(pos_it2, value);
    }

    if (hasStraggler)
    {
        std::list<int>::iterator pos_it = result.begin();
        while (pos_it != result.end() && *pos_it < straggler)
            ++pos_it;
        result.insert(pos_it, straggler);
    }

    arr = result;
}

void PmergeMe::sortWithList()
{
    double start = getTime();
    mergeInsertSortList(listData);
    double end = getTime();
    listTime = end - start;
}


void PmergeMe::insertionSortDeque(std::deque<int>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr)
{
    int n = arr.size();
    
    if (n <= 10)
    {
        insertionSortDeque(arr, 0, n - 1);
        return;
    }

    std::deque<int> larger;
    std::deque<int> smaller;
    int straggler = -1;
    bool hasStraggler = false;

    for (int i = 0; i < n - 1; i += 2)
    {
        if (arr[i] > arr[i + 1])
        {
            larger.push_back(arr[i]);
            smaller.push_back(arr[i + 1]);
        }
        else
        {
            larger.push_back(arr[i + 1]);
            smaller.push_back(arr[i]);
        }
    }

    if (n % 2 != 0)
    {
        straggler = arr[n - 1];
        hasStraggler = true;
    }

    if (!larger.empty())
        mergeInsertSortDeque(larger);

    std::deque<int> result = larger;
    if (smaller.empty())
    {
        arr = result;
        return;
    }
    
    int first_value = smaller[0];
    int left = 0;
    int right = result.size();
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (result[mid] < first_value)
            left = mid + 1;
        else
            right = mid;
    }
    result.insert(result.begin() + left, first_value);
    
    std::deque<size_t> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    size_t jacob_size = 1;
    while (jacob_size < smaller.size())
    {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
        jacob_size = next;
    }
    
    std::deque<size_t> insertion_order;
    for (size_t i = 2; i < jacobsthal.size(); i++)
    {
        size_t current = jacobsthal[i];
        if (current > smaller.size())
            current = smaller.size();
        
        for (size_t j = current; j > jacobsthal[i - 1] && j > 0; j--)
        {
            if (j - 1 > 0)
                insertion_order.push_back(j - 1);
        }
        
        if (current >= smaller.size())
            break;
    }
    
    for (size_t i = 0; i < insertion_order.size(); i++)
    {
        size_t idx = insertion_order[i];
        if (idx >= smaller.size())
            continue;
            
        int value = smaller[idx];
        int left2 = 0;
        int right2 = result.size();
        while (left2 < right2)
        {
            int mid = left2 + (right2 - left2) / 2;
            if (result[mid] < value)
                left2 = mid + 1;
            else
                right2 = mid;
        }
        result.insert(result.begin() + left2, value);
    }

    if (hasStraggler)
    {
        int left = 0;
        int right = result.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (result[mid] < straggler)
                left = mid + 1;
            else
                right = mid;
        }
        result.insert(result.begin() + left, straggler);
    }

    arr = result;
}

void PmergeMe::sortWithDeque()
{
    double start = getTime();
    mergeInsertSortDeque(dequeData);
    double end = getTime();
    dequeTime = end - start;
}