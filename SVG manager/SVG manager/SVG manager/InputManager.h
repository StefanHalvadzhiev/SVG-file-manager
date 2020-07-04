#pragma once
#include "SVGManager.h"

class InputManager {
	private:
		SVGManager svg;
		char* input;
		size_t inputLen;

		bool executeCommand(char** input, unsigned short wordCount);
		unsigned short getCommandWordCount(char* input);
		void separateWords(char** separatedWords, unsigned short wordCount);

	public:
		InputManager();
		~InputManager();

		bool recieveCommand(const char* userInput);
};