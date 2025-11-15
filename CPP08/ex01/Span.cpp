/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:09:30 by oalananz          #+#    #+#             */
/*   Updated: 2025/11/14 00:03:34 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(10) {}

Span::Span(unsigned int N) : N(N) {}

Span::~Span() {}

Span::Span(const Span &obj) : N(obj.N) , arr(obj.arr) {}

Span &Span::operator=(const Span &obj)
{
    if(this != &obj)
    {
        this->N = obj.N;
        this->arr = obj.arr;
    }
    return *this;
}

void Span::addNumber(unsigned int num)
{
    if (this->arr.size() < N)
        this->arr.push_back(num);
    else
        throw MaxSizeReached();
}

void Span::addNumber(std::list<int>::iterator begin, std::list<int>::iterator end)
{
    if(this->arr.size() + std::distance(begin,end) > N)
        throw std::overflow_error("Adding this range would exceed Span capacity");
    std::list<int>::iterator i = begin;
    for(i = begin ; i != end ; i++)
        addNumber(*i);
}


unsigned int Span::shortestSpan()
{
    int i = -1;
    int min = std::numeric_limits<int>::max();
    if(this->arr.size() <= 1)
        throw NoSpanCanBeFound();
    this->arr.sort();
    std::list<int>::iterator it;
    for(it = this->arr.begin(); it != this->arr.end() ; ++it)
    {
        if(i == -1)
            i = *it;
        else if(*it - i < min)
        {
            min = *it - i;
            i = *it;
        }
        i = *it;
    }
    return min;
}

unsigned int Span::longestSpan()
{
    if(this->arr.size() <= 1)
        throw NoSpanCanBeFound();
    this->arr.sort();
    return (this->arr.back() - this->arr.front());
}

const char * Span::NoSpanCanBeFound::what() const throw()
{
    return "No Span Can Be Found";
}

const char * Span::MaxSizeReached::what() const throw()
{
    return "Max Size Reached";
}


