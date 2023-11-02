#pragma once
#include <SFML/Audio.hpp>

#include <map>
class AudioManager
{
public:

	static int GetVolume() { return volume; }
	static void SetVolume(float& _volume) { 
		volume = _volume;
		music->setVolume(_volume); 
		sound->setVolume(_volume); 
	}
	static void Loop(bool _state) { music->setLoop(_state); }

	static void Play(std::string _key);

	static void Pause() { music->pause(); }
	static void Stop() { music->stop(); }

	static void PlaySound(std::string _key);

	static void AddMusic(std::string _key, std::string _fileName);
	static void AddSound(std::string _key, std::string _fileName);

private:
	static int volume;
	static sf::Music* music;
	static sf::Music* sound;
	static std::map<std::string, sf::Music*> musics;
	static std::map<std::string, sf::Music*> sounds;
};

