/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:10:12 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/22 11:51:45 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>

Base * generate(void)
{
    srand((unsigned)time(0)); 
    int i;
    i = (rand()%3)+1;
    if(i == 1)
        return (new A());
    else if(i == 2)
        return (new B());
    return (new C());
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p) != NULL)
        std::cout << "The Derived Class type is A" << std::endl;
    else if(dynamic_cast<B*>(p) != NULL)
        std::cout << "The Derived Class type is B" << std::endl;
    else if(dynamic_cast<C*>(p) != NULL)
        std::cout << "The Derived Class type is C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "The Derived Class type is A" << std::endl;
    }
    catch(const std::exception& e) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "The Derived Class type is B" << std::endl;
    }
    catch(const std::exception& e) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "The Derived Class type is C" << std::endl;
    }
    catch(const std::exception& e) {}
    
}

int main()
{
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
}
