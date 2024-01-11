/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:11:54 by acardona          #+#    #+#             */
/*   Updated: 2024/01/11 18:07:31 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

static void	_test_random_child_class(void);

int main ( void )
{
	srand(time(NULL));

	Base basic;
	Base &basic_ref = basic;
	std::cout << "The reals class is Base:" << std::endl;
	identify(&basic);
	identify(basic_ref);

	for (int i = 0; i < 10; ++i)
	{
		std::cout << std::endl;
		_test_random_child_class();
	}
	return (0);
}

static void	_test_random_child_class(void)
{
	Base *base = generate();
	Base &refBase = *base;

	identify(base);
	identify(refBase);

	delete (base);
}

/**
 * @brief It randomly instanciates A, B or C and returns the instance as a Base pointer. 
 * 
 * @return Base* 
 */
Base * generate(void)
{
	int	n (rand() % 3);
	if (DEBUG)
	{
		std::string class_is[3] = {"The real class is A:", "The real class is B:", "The real class is C:"};
		std::cout << class_is[n] << std::endl;
	}
	switch (n)
	{
		case 0:
			return (new(A));
		case 1:
			return (new(B));
		default :
			return (new(C));
	}
}

/**
 * @brief It prints the actual type of the object pointed to by p: "A", "B" or "C".
 * 
 * @param p 
 */
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "the class is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "the class is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "the class is C" << std::endl;
	else
		std::cout << "the class is Base" << std::endl;
}

/**
 * @brief It prints the actual type of the object pointed to by p: "A", "B" or "C". 
 * 
 * @param p 
 */
void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "the class is A" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "the class is B" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "the class is C" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}
	std::cout << "the class is Base" << std::endl;
}
