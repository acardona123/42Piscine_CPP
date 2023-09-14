/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:25:04 by acardona          #+#    #+#             */
/*   Updated: 2023/09/14 15:19:13 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"


static int _subject_main( void );
static void _testMateria( void );
static void _testCharacter( void );
static void	_testMateriaSource(void);


int main( void )
{
	if (1)
	{
		_subject_main();
		std::cout << std::endl << std::endl;
	}

	if (1)
	{
		_testMateria();
		std::cout << std::endl << std::endl;
	}
	if (1)
	{
		_testCharacter();
		std::cout << std::endl << std::endl;
	}

	if (1)
	{
		_testMateriaSource();
		std::cout << std::endl << std::endl;
	}
	
	if (1) //correction tests here...
	{
	}
	
	return (0);
}


static int _subject_main( void )
{
	std::cout << CYELLOW_H << "==== Tests main subject ====" << CBLACK << std::endl << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl << CYELLOW_H << "---- End: Tests main subject ----" << CBLACK << std::endl;
	
	return 0;
}

static void _testMateria( void )
{
	std::cout << CYELLOW_H << "==== Tests Materia ====" << CBLACK << std::endl << std::endl;
	{
		std::cout << CGREEN << "= Ice =" << CBLACK << std::endl;
		
		std::cout << CGREEN << "- Default construction :" << CBLACK << std::endl;
		Ice	ice1;
		std::cout << "ice1: " << &ice1 << std::endl;
		std::cout << "Type: " << ice1.getType() << std::endl;

		{
			std::cout << CGREEN << "- Copy construction :" << CBLACK << std::endl;
			Ice	ice2(ice1);
			std::cout << "ice2: " << &ice2 << std::endl;
			std::cout << "Type: " << ice2.getType() << std::endl;

			std::cout << CGREEN << "- Assignation operator :" << CBLACK << std::endl;
			ice2 = ice1;
			std::cout << "ice2: " << &ice2 << std::endl;
			std::cout << "Type: " << ice2.getType() << std::endl;
		}
		
		std::cout << CGREEN << "- Clone construction :" << CBLACK << std::endl;
		Ice *p_ice3 = ice1.clone();
		std::cout << "ice3: " << &p_ice3 << std::endl;
		std::cout << "Type: " << p_ice3->getType() << std::endl;	
		delete p_ice3;

		std::cout << CGREEN << "- Character construction for Materia::use :" << CBLACK << std::endl;
		Character	toto("Toto");
		std::cout << CGREEN << " -> Materia::use :" << CBLACK << std::endl;
		ice1.use(toto);
	}
	std::cout << std::endl;
	{
		std::cout << CGREEN << "= Cure =" << CBLACK << std::endl;
		
		std::cout << CGREEN << "- Default construction :" << CBLACK << std::endl;
		Cure	Cure1;
		std::cout << "Cure1: " << &Cure1 << std::endl;
		std::cout << "Type: " << Cure1.getType() << std::endl;

		{
			std::cout << CGREEN << "- Copy construction :" << CBLACK << std::endl;
			Cure	Cure2(Cure1);
			std::cout << "Cure2: " << &Cure2 << std::endl;
			std::cout << "Type: " << Cure2.getType() << std::endl;

			std::cout << CGREEN << "- Assignation operator :" << CBLACK << std::endl;
			Cure2 = Cure1;
			std::cout << "Cure2: " << &Cure2 << std::endl;
			std::cout << "Type: " << Cure2.getType() << std::endl;
		}
		
		std::cout << CGREEN << "- Clone construction :" << CBLACK << std::endl;
		Cure *p_Cure3 = Cure1.clone();
		std::cout << "Cure3: " << &p_Cure3 << std::endl;
		std::cout << "Type: " << p_Cure3->getType() << std::endl;	
		delete p_Cure3;

		std::cout << CGREEN << "- Character construction for Materia::use :" << CBLACK << std::endl;
		Character	toto("Toto");
		std::cout << CGREEN << " -> Materia::use :" << CBLACK << std::endl;
		Cure1.use(toto);
	}
	std::cout << std::endl << CYELLOW_H << "---- End: Tests Materia ----" << CBLACK << std::endl;
}

void	_showCharacterInventory(Character & ch)
{
	std::cout << ch.getName() << " inventory: [";
	if (ch.getMateria(0))
		std::cout << ch.getMateria(0)->getType() << " (" << ch.getMateria(0) << "), ";
	else
	 	std::cout << "NULL, ";
	if (ch.getMateria(1))
		std::cout << ch.getMateria(1)->getType() << " (" << ch.getMateria(1) << "), ";
	else
	 	std::cout << "NULL, ";
	if (ch.getMateria(2))
		std::cout << ch.getMateria(2)->getType() << " (" << ch.getMateria(2) << "), ";
	else
	 	std::cout << "NULL, ";
	if (ch.getMateria(3))
		std::cout << ch.getMateria(3)->getType() << " (" << ch.getMateria(3) << ")";
	else
	 	std::cout << "NULL";
	std::cout << "]" << std::endl;
}

static void _testCharacter( void )
{
	std::cout << CYELLOW_H << "==== Tests Character ====" << CBLACK << std::endl << std::endl;
	{
		std::cout << CGREEN << "- Constructing materias to be used by the character:" << CBLACK << std::endl;
		Ice		ice1;
		Cure	cure1;
		Ice		ice2;
		Cure	cure2;
		Ice		ice3;
		Cure	cure3;
		std::cout << std::endl;
		
		std::cout << CGREEN << "- Constructing a character:" << CBLACK << std::endl;
		Character	toto("Toto");
		_showCharacterInventory(toto);
		std::cout << std::endl;
		
		std::cout << CGREEN << "- Testing empty inventory:" << CBLACK << std::endl;
		toto.unequip(0);
		toto.unequip(1);
		toto.unequip(2);
		toto.unequip(3);
		std::cout << std::endl;
		
		std::cout << CGREEN << "- Testing equiping:" << CBLACK << std::endl;
		toto.equip(NULL);
		toto.equip(ice1.clone());
		toto.equip(cure1.clone());
		toto.equip(ice2.clone());
		toto.equip(cure2.clone());
		toto.equip(&ice3);
		toto.equip(&cure3);
		_showCharacterInventory(toto);
		std::cout << std::endl;
		
		std::cout << CGREEN << "- Testing unequiping:" << CBLACK << std::endl;
		AMateria	*tmp1;
		AMateria	*tmp2;
		tmp1 = toto.getMateria(1);
		tmp2 = toto.getMateria(3);
		toto.unequip(1);
		toto.unequip(3);
		_showCharacterInventory(toto);
		if (tmp1)
			delete (tmp1);
		if (tmp2)
			delete (tmp2);
		std::cout << std::endl;

		std::cout << CGREEN << "- Testing re-equiping:" << CBLACK << std::endl;
		toto.equip(cure3.clone());
		_showCharacterInventory(toto);
		std::cout << std::endl;

		std::cout << CGREEN << "- Testing copy constructor:" << CBLACK << std::endl;
		{
			Character	shadow(toto);
			_showCharacterInventory(toto);
			_showCharacterInventory(shadow);
		}
		std::cout << std::endl;

		std::cout << CGREEN << "- Testing assignement operator:" << CBLACK << std::endl;
		{
			Character	bob("Bob");
			_showCharacterInventory(bob);
			_showCharacterInventory(toto);
			bob = toto;
			_showCharacterInventory(bob);
			AMateria *tmp;
			tmp = toto.getMateria(0);
			toto.unequip(0);
			delete tmp;
			_showCharacterInventory(toto);
			_showCharacterInventory(bob);
			
			bob = toto;
			_showCharacterInventory(bob);
		}
		
		std::cout << std::endl;
		std::cout << CGREEN << "- Destroying character and materias:" << CBLACK << std::endl;

	}
	std::cout << std::endl << CYELLOW_H << "---- End: Tests Character ----" << CBLACK << std::endl;
}


void	_showMateriaContent(MateriaSource & mc)
{
	std::cout << "Materias learnt: [";
	if (mc.getMateria(0))
		std::cout << mc.getMateria(0)->getType() << " (" << mc.getMateria(0) << "), ";
	else
	 	std::cout << "NULL, ";
	if (mc.getMateria(1))
		std::cout << mc.getMateria(1)->getType() << " (" << mc.getMateria(1) << "), ";
	else
	 	std::cout << "NULL, ";
	if (mc.getMateria(2))
		std::cout << mc.getMateria(2)->getType() << " (" << mc.getMateria(2) << "), ";
	else
	 	std::cout << "NULL, ";
	if (mc.getMateria(3))
		std::cout << mc.getMateria(3)->getType() << " (" << mc.getMateria(3) << ")";
	else
	 	std::cout << "NULL";
	std::cout << "]" << std::endl;
}

static void	_testMateriaSource(void)
{
	{
		std::cout << CYELLOW_H << "==== Tests MateriaSource ====" << CBLACK << std::endl << std::endl;
		
		std::cout << CGREEN << "- Constructing Ice and Cure Materias to learn later:" << CBLACK << std::endl;
		Ice		ice1;
		Cure	cure1;
		std::cout << std::endl;

		{
			std::cout << CGREEN << "- Default construction of MateriaSource && Learning Materia:" << CBLACK << std::endl;
			MateriaSource	source1;
			_showMateriaContent(source1);
			source1.learnMateria(new Ice);
			source1.learnMateria(new Cure);
			source1.learnMateria(new Ice);
			source1.learnMateria(new Cure);
			source1.learnMateria(&ice1);
			_showMateriaContent(source1);
		}
		std::cout << std::endl;
		
		{
			std::cout << CGREEN << "- Copy construction of MateriaSource :" << CBLACK << std::endl;
			std::cout << "~ Materia of reference :" << std::endl;
			MateriaSource	source1;
			source1.learnMateria(new Ice);
			source1.learnMateria(new Cure);
			source1.learnMateria(new Ice);
			_showMateriaContent(source1);
			std::cout << "~ Copy Materia:" << std::endl;
			MateriaSource	source2(source1);
			_showMateriaContent(source2);
			std::cout << "~ Modifying Copy Mat:" << std::endl;
			source2.learnMateria(new Ice);
			_showMateriaContent(source2);
			std::cout << "~ Assigning ref = copy:" << std::endl;
			source1 = source2;
			_showMateriaContent(source1);
		}
		std::cout << std::endl;

		{
			std::cout << CGREEN << "- Creates Materia:" << CBLACK << std::endl;
			std::cout << "~ Creates MateriaSource filled with 3 Materias of reference :" << std::endl;
			MateriaSource	source1;
			source1.learnMateria(new Ice);
			source1.learnMateria(new Cure);
			source1.learnMateria(new Ice);
			_showMateriaContent(source1);
			std::cout << "~ Creates materia from references :" << std::endl;
			AMateria	*generated;
			generated = source1.createMateria("test");
			std::cout << generated << std::endl;
			generated = source1.createMateria("ice");
			std::cout << generated << ": " << generated->getType() << std::endl;
			delete generated;
			generated = source1.createMateria("cure");
			std::cout << generated << ": " << generated->getType() << std::endl;
			delete generated;
		}
		std::cout << std::endl;
		std::cout << CGREEN << "- Destroying materias:" << CBLACK << std::endl;
	}
	std::cout << std::endl << CYELLOW_H << "---- End: Tests MateriaSource ----" << CBLACK << std::endl;

}