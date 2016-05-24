#include "Game.hpp"

#include <iostream>

int main()
{
	try
	{
		Game game;
		game.Run();
	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
			
	
	return 0;
}
