/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:41:03 by acardona          #+#    #+#             */
/*   Updated: 2023/08/27 15:32:54 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

void testAnimals( void );
void testWrongAnimals( void );

int main()
{
	testAnimals();

	std::cout << std::endl << std::endl ;
	
	testWrongAnimals();

	return 0;
}

void testAnimals( void )
{
	std::cout << " === Animal ====" << std::endl << std::endl;

	std::cout << "=> Class Animal : " << std::endl;
	const Animal* theAnimal = new Animal();
	std::cout << theAnimal->getType() << " says:" << std::endl;
	theAnimal->makeSound();
	delete theAnimal;
	std::cout << std::endl;

	std::cout << "=> Class Dog : " << std::endl;
	const Animal* theDog = new Dog();
	std::cout << theDog->getType() << " says:" << std::endl;
	theDog->makeSound();
	delete theDog;
	std::cout << std::endl;

	std::cout << "=> Class Cat : " << std::endl;
	const Animal* theCat = new Cat();
	std::cout << theCat->getType() << " says:" << std::endl;
	theCat->makeSound(); //will output the cat sound!
	delete theCat;
	std::cout << std::endl;
	
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