/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:58:29 by acardona          #+#    #+#             */
/*   Updated: 2023/09/14 11:18:46 by acardona         ###   ########.fr       */
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
static int generateAanimalArray(Aanimal *array[ARRAY_SIZE]);
static void	destroyAanimalArray (Aanimal *array[ARRAY_SIZE]);
static void generalTestOfAanimals( void );


int main(void)
{
	// Aanimal notWorking;
	
	Aanimal	*array[ARRAY_SIZE];

	generateAanimalArray(array);	
	std::cout << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << i << ": " << array[i]->getType() << ":" << std::endl;
		array[i]->makeSound();
	}
	std::cout << std::endl;
	destroyAanimalArray(array);
	
	std::cout << std::endl << std::endl;
	generalTestOfAanimals();
	
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

static int generateAanimalArray(Aanimal *array[ARRAY_SIZE])
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

static void	destroyAanimalArray (Aanimal *array[ARRAY_SIZE])
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << i << ": ";
		delete array[i];
	}
}

// ---- End: Array generation  and destruction ----



// ==== General tests ====

static void generalTestOfAanimals( void )
{
	std::cout << " === Aanimal ====" << std::endl << std::endl;

	// std::cout << "=> Class Aanimal : " << std::endl;
	// const Aanimal* theAanimal = new Aanimal();
	// std::cout << theAanimal->getType() << " says:" << std::endl;
	// theAanimal->makeSound();
	// delete theAanimal;
	// std::cout << std::endl;

	std::cout << "=> Class Dog : " << std::endl;
	std::string			dogThougts[BRAIN_SIZE];
	generateDogThoughts(dogThougts);
	const Aanimal* theDog = new Dog(dogThougts);
	std::cout << theDog->getType() << " says:" << std::endl;
	theDog->makeSound();
	delete theDog;
	std::cout << std::endl;

	std::cout << "=> Class Cat : " << std::endl;
	std::string			catThougts[BRAIN_SIZE];
	generateCatThoughts(catThougts);
	const Aanimal* theCat = new Cat(catThougts);
	// const Aanimal* theCat = new Cat();
	std::cout << theCat->getType() << " says:" << std::endl;
	theCat->makeSound();
	delete theCat;
	
	
	std::cout << std::endl << "=> Deep copy tests : " << std::endl;
	Cat aCat(catThougts);
	std::cout << "aCat initial though #0: " << std::endl << "  " << aCat.getBrain()->getIdea(0) << std::endl;
	//modif on aCat :
	aCat.getBrain()->setIdea(0, "Modified thought");
	std::cout << "aCat modified though #0: " << std::endl << "  " << aCat.getBrain()->getIdea(0) << std::endl;
	//copy of aCat (and modifications to check if deepcopy)
	Cat aCatBis(aCat);
	std::cout << "aCatBis, copy of aCat: " << std::endl << "  " << aCatBis.getBrain()->getIdea(0) << std::endl;
	aCat.getBrain()->setIdea(0, "Updated modified thought");
	std::cout << "Modification on aCat:" << std::endl << "  aCat: " << aCat.getBrain()->getIdea(0) << std::endl << "  aCatBis: " << aCatBis.getBrain()->getIdea(0) << std::endl;
	//check of the = operator
	*aCatBis.getBrain() = *aCat.getBrain();
	 std::cout << "operator = : " << std::endl << "  aCat: " << aCat.getBrain()->getIdea(0) << std::endl<<  "  aCatBis: " << aCatBis.getBrain()->getIdea(0) << std::endl;
}

// ----	End: General tests ----	