/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:50:24 by oalananz          #+#    #+#             */
/*   Updated: 2025/11/14 00:08:44 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
        
        MutantStack():std::stack<T> () {};
        MutantStack &operator=(const MutantStack &obj)
        {
            std::stack<T>::operator=(obj);
            return *this;   
        }
        MutantStack(const MutantStack &obj) : std::stack<T> (obj) {}
        ~MutantStack() {};

        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }

        const_iterator cbegin() const
        {
            return this->c.begin();
        }
        const_iterator cend() const
        {
            return this->c.end();
        }

        reverse_iterator rbegin()
        {
            return this->c.rbegin();
        }
        reverse_iterator rend()
        {
            return this->c.rend();
        }

        const_reverse_iterator crbegin() const
        {
            return this->c.rbegin();
        }
        const_reverse_iterator crend() const
        {
            return this->c.rend();
        }
};






#endif