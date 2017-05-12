#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Player;

class InputManager
{
private:
	static InputManager instance;

	InputManager() {}
	void operator= (InputManager&);
	InputManager(const InputManager&);

public:
	static InputManager& getHandle() {
		return instance;
	}

	void CatchInput(Player*);

};



