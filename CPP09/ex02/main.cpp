/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:15:35 by oalananz          #+#    #+#             */
/*   Updated: 2025/11/23 17:15:37 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    PmergeMe Ford;

    if (!Ford.parseInput(argc, argv)) {
        return 1;
    }
    Ford.displayBefore();
    Ford.sortWithList();
    Ford.sortWithDeque();
    Ford.displayAfter();
    Ford.displayTimes();

    return 0;
}