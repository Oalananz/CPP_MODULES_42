#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "=== Test 1: Basic MutantStack operations ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "\n=== Iterating through MutantStack ===" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::cout << "\n=== Test 2: Copy constructor ===" << std::endl;
    std::stack<int> s(mstack);
    std::cout << "Copied stack size: " << s.size() << std::endl;
    std::cout << "Copied stack top: " << s.top() << std::endl;
    
    std::cout << "\n=== Test 3: Comparison with std::list ===" << std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    
    std::cout << "List contents:" << std::endl;
    for (std::list<int>::iterator lit = list.begin(); lit != list.end(); ++lit)
    {
        std::cout << *lit << std::endl;
    }
    
    std::cout << "\n=== Test 4: Reverse iteration ===" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    std::cout << "Reverse order:" << std::endl;
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
    
    std::cout << "\n=== Test 5: String MutantStack ===" << std::endl;
    MutantStack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.push("42");
    strStack.push("School");
    
    std::cout << "String stack contents:" << std::endl;
    for (MutantStack<std::string>::iterator sit = strStack.begin(); 
         sit != strStack.end(); ++sit)
    {
        std::cout << *sit << std::endl;
    }
    
    std::cout << "\n=== Test 6: Assignment operator ===" << std::endl;
    MutantStack<int> mstack2;
    mstack2 = mstack;
    std::cout << "Assigned stack size: " << mstack2.size() << std::endl;
    std::cout << "Assigned stack top: " << mstack2.top() << std::endl;
    
    std::cout << "\n=== Test 7: Empty stack check ===" << std::endl;
    MutantStack<int> emptyStack;
    std::cout << "Empty stack size: " << emptyStack.size() << std::endl;
    std::cout << "Is empty: " << (emptyStack.empty() ? "Yes" : "No") << std::endl;
    
    return 0;
}