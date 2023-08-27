/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:58:29 by acardona          #+#    #+#             */
/*   Updated: 2023/08/27 18:30:11 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>

#include "Dog.hpp"
#include "Cat.hpp"

#define ARRAY_SIZE 10

static void	generateDogThoughts(std::string ideas[BRAIN_SIZE]);
static void	generateCatThoughts(std::string ideas[BRAIN_SIZE]);
static int generateAnimalArray(Animal *array[ARRAY_SIZE]);
static void	destroyAnimalArray (Animal *array[ARRAY_SIZE]);
static void generalTestOfAnimals( void );


int main(void)
{
	Animal	*array[ARRAY_SIZE];

	generateAnimalArray(array);	
	std::cout << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << i << ": " << array[i]->getType() << ":" << std::endl;
		array[i]->makeSound();
	}
	std::cout << std::endl;
	destroyAnimalArray(array);
	
	std::cout << std::endl << std::endl;
	generalTestOfAnimals();
	
	return (0);
}

// ==== Thoughts generation ====

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

// ---- End: Thoughts generation ----


// ==== Array generation and destruction ====

static int generateAnimalArray(Animal *array[ARRAY_SIZE])
{
	int	i(0);
	
	std::string catThougts[BRAIN_SIZE];
	generateCatThoughts(catThougts);
	while (i < ARRAY_SIZE / 2)
	{
		std::cout << i << ": ";
		array[i] = new Cat(catThougts);
		if (!array[i])
		{
			std::cout << "Allocation error" << std::endl;
			while (--i >= 0)
				delete array[i];
			return (1);
		}
		i++;
	}
	std::string dogThougts[BRAIN_SIZE];
	generateDogThoughts(dogThougts);
	while (i < ARRAY_SIZE)
	{
		std::cout << i << ": ";
		array[i] = new Dog(dogThougts);
		if (!array[i])
		{
			std::cout << "Allocation error" << std::endl;
			while (--i >= 0)
				delete array[i];
			return (1);
		}
		i++;
	}
	return (0);
}

static void	destroyAnimalArray (Animal *array[ARRAY_SIZE])
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << i << ": ";
		delete array[i];
	}
}

// ---- End: Array generation  and destruction ----



// ==== General tests ====

static void generalTestOfAnimals( void )
{
	std::cout << " === Animal ====" << std::endl << std::endl;

	std::cout << "=> Class Animal : " << std::endl;
	std::string			catThougts[BRAIN_SIZE];
	generateCatThoughts(catThougts);
	const Animal* theAnimal = new Animal();
	std::cout << theAnimal->getType() << " says:" << std::endl;
	theAnimal->makeSound();
	delete theAnimal;
	std::cout << std::endl;

	std::cout << "=> Class Dog : " << std::endl;
	std::string			dogThougts[BRAIN_SIZE];
	generateDogThoughts(dogThougts);
	const Animal* theDog = new Dog(dogThougts);
	std::cout << theDog->getType() << " says:" << std::endl;
	theDog->makeSound();
	delete theDog;
	std::cout << std::endl;

	std::cout << "=> Class Cat : " << std::endl;
	const Animal* theCat = new Cat(catThougts);
	// const Animal* theCat = new Cat();
	std::cout << theCat->getType() << " says:" << std::endl;
	theCat->makeSound();
	delete theCat;
	
	
	std::cout << std::endl << "=> Deep copy tests : " << std::endl;
	Cat aCat(catThougts);
	std::cout << aCat.getBrain()->getIdea(0) << std::endl;
	//modif on aCat :
	aCat.getBrain()->setIdea(0, "Modified thought");
	std::cout << "aCat: " << aCat.getBrain()->getIdea(0) << std::endl;
	//copy of aCat (and modifications to check if deepcopy)
	Cat aCatBis(aCat);
	std::cout << "aCatBis: " << aCatBis.getBrain()->getIdea(0) << std::endl;
	aCat.getBrain()->setIdea(0, "Updated modified thought");
	std::cout << "Modification : " << std::endl << "aCat: " << aCat.getBrain()->getIdea(0) << std::endl << "aCatBis: " << aCatBis.getBrain()->getIdea(0) << std::endl;
	//check of the = operator
	*aCatBis.getBrain() = *aCat.getBrain();
	 std::cout << "operator = : " << std::endl << "aCat: " << aCat.getBrain()->getIdea(0) << std::endl<<  "aCatBis: " << aCatBis.getBrain()->getIdea(0) << std::endl;

	
}

// ----	End: General tests ----	