#include <iostream>
#include "Iridescent.h"

int main(int argc, char *argv[])
{
	
	Test();
	
	std::cout << std::endl;
	std::cout << "Type any char and press Enter" << std::endl;
	
	char c;
	std::cin >> c;
	
	return 0;
    // wait for keypress
    std::cin.get();
}