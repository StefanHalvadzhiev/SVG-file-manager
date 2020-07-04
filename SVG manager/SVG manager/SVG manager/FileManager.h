#pragma once
#include <fstream>
using namespace std;


class FileManager {
	private:
		bool isOpen;
		bool isSaved;
		char* name;

		ofstream writeFile;
		ifstream readFile;

		void checkFileName(char* fileName);

	public:
		FileManager();
		~FileManager();

		void emptyFile();
		void createFile(char* fileName);
		void openFile(char* fileName);
		void deleteFile(char *fileName);
		void closeFile();
		void writeToFile(const char* textToBeWritten);
		void getLines(char** parameterArr, unsigned short lineSize);

		unsigned int getLineCount();
		bool checkIfOpen();
};