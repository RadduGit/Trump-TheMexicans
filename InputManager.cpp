#include "InputManager.h"
#include "InputManager.h"
#include <iostream>
//#include "entityManager.h"



void InputManager::Verificare(sf::Keyboard::Key key)
{
	/*
	W -> 1
	A -> 2
	S -> 3
	D -> 4
	*/

	switch (key) {
	case sf::Keyboard::Key::W :
		//entityManager.check(1);
		std::cout << "A fost apasata tasta W\n";
		break;

	case sf::Keyboard::Key::A:
		//entityManager.check(2);
		std::cout << "A fost apasata tasta A\n";
		break;

	case sf::Keyboard::Key::S:
		//entityManager.check(3);
		std::cout << "A fost apasata tasta S\n";
		break;

	case sf::Keyboard::Key::D:
		//entityManager.check(4);
		std::cout << "A fost apasata tasta D\n";
		break;
	}
}
InputManager InputManager::input(0);

