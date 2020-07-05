#include <iostream>
#include "InputManager.h"
#include "FileManager.h"
#include "SVGManager.h"
#include <cstring>
#include "UtilityFunctions.h"

InputManager::InputManager() {
	input = new(nothrow) char[150];
	inputLen = 0;
}

InputManager::~InputManager() {
	delete[] input;
}

bool InputManager::recieveCommand(const char* userInput) {
	strcpy(input, userInput);
	inputLen = strlen(input);
	unsigned short commandWordCount = getCommandWordCount(input);
	if (!commandWordCount) {
		std::cout << "No command given!" << std::endl;
		return true;
	}
	char** separatedWords = new char* [commandWordCount];
	for (unsigned short i = 0; i < commandWordCount; i++)
		separatedWords[i] = new char[100];
	if (separatedWords == nullptr) {
		std::cout << "Error allocating memory, terminating program.." << std::endl;
		return false;
	}
	separateWords(separatedWords, commandWordCount);
	
	bool returnStatus = executeCommand(separatedWords, commandWordCount);

	for (unsigned short i = 0; i < commandWordCount; i++)
		delete[] separatedWords[i];
	delete[] separatedWords;

	return returnStatus;
}

void InputManager::separateWords(char** separatedWords, unsigned short wordCount) {
	char buffer[100];
	unsigned short bufferPosition = 0;
	unsigned short wordCounter = 0;
	for (unsigned short z = 0; z < inputLen; z++) {
		if (input[z] == ' '){
			buffer[bufferPosition] = '\0';
			strcpy(separatedWords[wordCounter], buffer);
			bufferPosition = 0;
			wordCounter++;
			continue;
		}
		buffer[bufferPosition] = input[z];
		bufferPosition++;
	}
	buffer[bufferPosition] = '\0';
	strcpy(separatedWords[wordCount-1], buffer);
}

unsigned short InputManager::getCommandWordCount(char* input) {
	unsigned short spacesCount = 0;
	for (unsigned short i = 0; i < inputLen; i++)
		if (input[i] == ' ') {
			spacesCount++;
			while (input[i + 1] == ' ')
				i++;
		}
	if (inputLen == 0)
		return 0;
	if (spacesCount == 0)
		return 1;
	return spacesCount + 1;
}

bool InputManager::executeCommand(char** separatedCommands, unsigned short wordCount) {
	bool returnStatus = true;
	if (strcmp(separatedCommands[0], "exit") == 0) {
		std::cout << "Thank you for using the program!" << std::endl;
		returnStatus = false;
	}
	else if (strcmp(separatedCommands[0], "help") == 0) {
		help();
	}
	else if (strcmp(separatedCommands[0], "createfile") == 0) {
		svg.createFile(separatedCommands[1]);
	}
	else if (strcmp(separatedCommands[0], "close") == 0) {
		svg.closeFile();
	}
	else if (strcmp(separatedCommands[0], "delete") == 0) {
		svg.deleteFile(separatedCommands[1]);
	}
	else if (strcmp(separatedCommands[0], "open") == 0) {
		svg.openFile(separatedCommands[1]);
	}
	else if (strcmp(separatedCommands[0], "save") == 0) {
		svg.saveFile();
	}
	else if (strcmp(separatedCommands[0], "create") == 0) {
		char** parameterString = new char* [wordCount - 2];
		for (unsigned short i = 0; i < wordCount-2; i++) {
			parameterString[i] = new char[30];
			strcpy(parameterString[i], separatedCommands[i + 2]);
		}
		svg.create(separatedCommands[1], parameterString, wordCount-2);
		for (unsigned short i = 0; i < wordCount - 2; i++)
			delete[] parameterString[i];
		delete[] parameterString;
	}
	else if (strcmp(separatedCommands[0], "erase") == 0) {
		svg.erase(atoi(separatedCommands[1]));
	}
	else if (strcmp(separatedCommands[0], "print") == 0) {
		svg.print();
	}
	else if (strcmp(separatedCommands[0], "translate") == 0) {
		if (wordCount == 4)
			svg.translate(atof(separatedCommands[1]), atof(separatedCommands[2]), atoi(separatedCommands[3]));
		else if (wordCount == 3)
			svg.translate(atof(separatedCommands[1]), atof(separatedCommands[2]));
		else if (wordCount == 2)
			svg.translate(atof(separatedCommands[1]));
		else
			cout << "Too few arguments in function call." << endl;
	}
	else if (strcmp(separatedCommands[0], "within") == 0) {
		if (wordCount <= 2) {
			cout << "Please try again using proper input." << endl;
		}
		char** parameterString = new char* [wordCount - 2];
		for (unsigned short i = 0; i < wordCount - 2; i++) {
			parameterString[i] = new char[30];
			strcpy(parameterString[i], separatedCommands[i + 2]);
		}
		svg.within(separatedCommands[1], parameterString, wordCount-2);
		for (unsigned short i = 0; i < wordCount - 2; i++)
			delete[] parameterString[i];
		delete[] parameterString;
	}
	else {
		cout << "Invalid command." << endl;
	}
	return returnStatus;
}