#pragma once

#include <SFML\Audio.hpp>
#include <string>
class SoundManager
{
private:
	sf::Music music;
	std::string soundFile;
public:
	void playSound();
	void stopSound();
	void setLoop();
	SoundManager();
	SoundManager(const std::string &musicName);
	~SoundManager();
};

