/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalananz <oalananz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:02:33 by oalananz          #+#    #+#             */
/*   Updated: 2025/10/03 23:19:55 by oalananz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
    Animal *animal[4];
    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0)
            animal[i] = new Cat();
        else
            animal[i] = new Dog();
    }
    std::string catBrain[15] = {
        "Chasing mice",
        "Climbing trees",
        "Playing with yarn",
        "Napping in the sun",
        "Scratching furniture",
        "Purring softly",
        "Hunting insects",
        "Exploring new places",
        "Cuddling with humans",
        "Knocking things off tables",
        "Staring out the window",
        "Chasing laser pointers",
        "Eating treats",
        "Hiding in boxes",
        "Watching birds"
    };
    std::string dogBrain[15] = {
        "Fetching the ball",
        "Chasing squirrels",
        "Digging holes",
        "Barking at strangers",
        "Playing tug-of-war",
        "Going for walks",
        "Chewing on toys",
        "Rolling in the grass",
        "Cuddling with humans",
        "Learning new tricks",
        "Swimming in the lake",
        "Sniffing everything",
        "Eating treats",
        "Sleeping by the fireplace",
        "Wagging tail excitedly"
    };
    Brain catbrain(catBrain, 15);
    Cat *cat = new Cat;
    cat->setBrain(catbrain);
    Brain dogbrain(dogBrain, 15);
    Dog *dog = new Dog;
    dog->setBrain(dogbrain);
    std::cout << "Cat brain idea[5]: "
              << cat->getBrain()->getIdea(5) << std::endl;
    std::cout << "Dog brain idea[10]: "
              << dog->getBrain()->getIdea(10) << std::endl;
    for (int i = 0; i < 4; i++)
        delete animal[i];
    delete cat;
    delete dog;
    return 0;
}
