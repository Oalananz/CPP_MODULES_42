/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:01:48 by oalananz          #+#    #+#             */
/*   Updated: 2025/11/13 17:40:14 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::cout << "=== Test with 5 numbers ===" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    
    std::cout << "\n=== Test with 10,000 numbers ===" << std::endl;
    Span sp2 = Span(10000);
    std::srand(std::time(0));
    
    for (int i = 0; i < 10000; ++i)
    {
        sp2.addNumber(i);
    }
    
    std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
    
    std::cout << "\n=== Test span ===" << std::endl;
    try
    {
        Span sp3 = Span(1);
        sp3.addNumber(5);
        sp3.shortestSpan();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test Size limit ===" << std::endl;
    try
    {
        Span sp4 = Span(1);
        sp4.addNumber(5);
        sp4.addNumber(4);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test addNumber with range ===" << std::endl;
    try
    {
        Span sp5 = Span(20);
        std::list<int> numbers;
        for (int i = 1; i <= 15; ++i)
            numbers.push_back(i * 10);
        
        sp5.addNumber(numbers.begin(), numbers.end());
        std::cout << "Added 15 numbers using range" << std::endl;
        std::cout << "Shortest Span: " << sp5.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp5.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test addNumber Exception ===" << std::endl;
    try
    {
        Span sp5 = Span(10);
        std::list<int> numbers;
        for (int i = 1; i <= 15; ++i)
            numbers.push_back(i * 10);
        
        sp5.addNumber(numbers.begin(), numbers.end());
        std::cout << "Added 15 numbers using range" << std::endl;
        std::cout << "Shortest Span: " << sp5.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp5.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}