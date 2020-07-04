#include <iostream>
#include "SVGObject.h"
#include <string>
#include "SVGManager.h"
#include "FileManager.h"	
#include "InputManager.h"

int main() {
	std::cout << "Use \"help\" to list all functions." << endl;
	InputManager userInput;
	char* command = new(nothrow) char[100];
	bool isAlive = true;
	while (isAlive) {
		std::cin.getline(command, 100);
		isAlive = userInput.recieveCommand(command);
		std::cout << std::endl;
	}
	delete[] command;
	return 0;
}