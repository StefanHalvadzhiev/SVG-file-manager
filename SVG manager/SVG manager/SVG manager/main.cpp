#include <iostream>
#include "SVGObject.h"
#include <string>
#include "SVGManager.h"
#include "FileManager.h"	
#include "InputManager.h"

/*! \mainpage Personal Calendar
 *
 * The sole purpose of this programme is to operate easily with svg files. <br>
 * Currently the system can do basic file operations with svg files, objects, translate the objects and erase them. <br>
 *
 * <br> Made by Stefan Halvadzhiev, Informatics, FN: 45678, 4th group.
 */


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