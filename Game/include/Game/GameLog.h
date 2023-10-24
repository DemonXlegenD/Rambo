#pragma once
#include <iostream>
#include <string>

class GameLog
{
public:
	static void log(std::string message);
	static void debug(std::string message);
	static void error(std::string message);
};
