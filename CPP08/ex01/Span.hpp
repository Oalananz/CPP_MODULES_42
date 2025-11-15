/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:32:30 by oalananz          #+#    #+#             */
/*   Updated: 2025/11/13 17:37:46 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
#include <limits>

class Span
{
    private:
        unsigned int N;
        std::list<int> arr;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &obj);
        Span &operator=(const Span &obj);
        ~Span();
        unsigned int shortestSpan();
        unsigned int longestSpan();
        void addNumber(unsigned int);
        void addNumber(std::list<int>::iterator begin, std::list<int>::iterator end);
        class NoSpanCanBeFound : public std::exception
        {
            public:
                const char * what() const throw();
        };
        class MaxSizeReached : public std::exception
        {
            public:
                const char * what() const throw();
        };
        
};


#endif