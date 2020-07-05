#pragma once
#include "SVGManager.h"

class InputManager {
	private:
		SVGManager svg;
		char* input;
		unsigned int inputLen;

		bool executeCommand(char** input, unsigned short wordCount);
		unsigned short getCommandWordCount(char* input);
		void separateWords(char** separatedWords, unsigned short wordCount);

	public:
		InputManager();
		~InputManager();
		InputManager& operator= (const InputManager& cpy) = delete;
		InputManager(const InputManager& cpy) = delete;
		bool recieveCommand(const char* userInput);
};