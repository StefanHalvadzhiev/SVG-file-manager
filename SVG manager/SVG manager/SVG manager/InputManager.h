#pragma once
#include "SVGManager.h"
/// <summary>
/// A basic console command handler
/// </summary>

class InputManager {
	private:
		/// Contains the non-separated user input.
		char* input;

		/// Contains the length of the user input
		size_t inputLen;

		/// Executes the correct commands in the svg class
		bool executeCommand(char** input, unsigned short wordCount);

		/// Returns the count of individual commands in the user input
		unsigned short getCommandWordCount(char* input);

		/// Separates the user input into individual commands
		void separateWords(char** separatedWords, unsigned short wordCount);
		SVGManager svg;
	public:
		InputManager();
		~InputManager();

		/// Recieves the command line from the user input and calls it's execution
		bool recieveCommand(const char* userInput);
};