#include "SoundManager.h"
#include <SFML\Audio.hpp>
#include <iostream>
#include <string>
void SoundManager::playSound()
{
  std::cout << soundFile << "\n";
	if (!music.openFromFile(soundFile)) {
		std::cout << "ERROR : Music file not found ! \n";
	}
   std::cout<<"Found";
		music.play();

}
void SoundManager::stopSound()
{
	if (music.Playing) {
		music.stop();
	}
}
void SoundManager::setLoop()
{
	music.setLoop(true);
};

SoundManager::SoundManager()
{
}

SoundManager::SoundManager(const std::string& musicName)
{
	soundFile = musicName;
}


SoundManager::~SoundManager()
{
}
