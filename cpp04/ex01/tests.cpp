/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:41:03 by acardona          #+#    #+#             */
/*   Updated: 2023/08/27 18:21:23 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

static void	generateDogThoughts(std::string ideas[BRAIN_SIZE]);
static void	generateCatThoughts(std::string ideas[BRAIN_SIZE]);
void testAnimals( void );
void testWrongAnimals( void );

int main()
{
	srand(time(0));
	testAnimals();
	return 0;
}



static std::string	indexedString(std::string str, int index)
{
	std::stringstream	s;
	s << index;
	return (str + s.str());
}

static void	generateDogThoughts(std::string ideas[BRAIN_SIZE])
{
	int i(-1);
	while (++i < 20)
		ideas[i] = indexedString("Where is the ball? #", i);
	i--;
	while (++i < 40)
		ideas[i] = indexedString("A bone!!! #", i);
	i--;
	while (++i < 60)
		ideas[i] = indexedString("If only I had a shoe to chew... #", i);
	i--;
	while (++i < 80)
		ideas[i] = indexedString("I'm a good boy! #", i);
	i--;
	while (++i < BRAIN_SIZE)
		ideas[i] = indexedString("Have I heard 'Park'? #", i);
}

static void	generateCatThoughts(std::string ideas[BRAIN_SIZE])
{
	int i(-1);
	while (++i < 20)
		ideas[i] = indexedString("Bring me food human #", i);
	i--;
	while (++i < 40)
		ideas[i] = indexedString("I swear I saw a green point of light ! #", i);
	i--;
	while (++i < 60)
		ideas[i] = indexedString("Did I tell you to stop petting me ? #", i);
	i--;
	while (++i < 80)
		ideas[i] = indexedString("Time to clean myself #", i);
	i--;
	while (++i < BRAIN_SIZE)
		ideas[i] = indexedString("I think this human undestands me, lets act weirdly to confuse him #", i);
}

void testWrongAnimals( void )
{
	std::cout << " === WrongAnimal ====" << std::endl << std::endl;

	std::cout << "=> Class WrongAnimal : " << std::endl;
	const WrongAnimal* theWrongAnimal = new WrongAnimal();
	std::cout << theWrongAnimal->getType() << " says:" << std::endl;
	theWrongAnimal->makeSound();
	delete theWrongAnimal;
	std::cout << std::endl;
	
	std::cout << "=> Class WrongDog : " << std::endl;
	const WrongAnimal* theWrongDog = new WrongDog();
	std::cout << theWrongDog->getType() << " says:" << std::endl;
	theWrongDog->makeSound();
	delete theWrongDog;
	std::cout << std::endl;

	std::cout << "=> Class WrongCat: " << std::endl;
	const WrongAnimal* theWrongCat = new WrongCat();
	std::cout << theWrongCat->getType() << " says:" << std::endl;
	theWrongCat->makeSound(); //will output the cat sound!
	std::cout << std::endl;
	delete theWrongCat;
}