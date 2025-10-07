/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:15:02 by oalananz          #+#    #+#             */
/*   Updated: 2025/06/22 23:50:35 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; ++i)
    {
        for (char *p = argv[i]; *p; ++p)
        {
            *p = std::toupper(*p);
        }
        std::cout << argv[i];
        if(i < argc - 1)
            std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}
