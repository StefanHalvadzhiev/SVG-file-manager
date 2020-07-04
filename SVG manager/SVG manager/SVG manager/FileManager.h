#pragma once
#include <fstream>
using namespace std;

/// <summary>
/// Very basic file handler. This class can only create, open / close, write and read and delete files.
/// </summary>

class FileManager {
	private:
		bool isOpen;
		bool isSaved;
		/// The name of the currently opened file
		char* name;
		/// Write file
		///@note both write and read files represent the same file.
		ofstream writeFile;

		/// Read file
		ifstream readFile;

		/// Checks whether a string contains a proper file extension. If the string does not contain a proper extention it concatenates it to 
		void checkFileName(char* fileName);

	public:
		/// Returns the count of lines in the currently opened file
		unsigned int getLineCount();

		/// Checks if a file is opened.
		bool checkIfOpen();
		FileManager();
		~FileManager();

		/// Empties the contentes of a file.
		void emptyFile();

		/// Creates a file.
		void createFile(char* fileName);

		/// Opens a file.
		void openFile(char* fileName);

		/// Deletes a file.
		void deleteFile(char *fileName);

		/// Closes currently opened file.
		void closeFile();

		/// Writes a string in a file.
		void writeToFile(const char* textToBeWritten);

		/// Reads all lines from the opened file.
		void getLines(char** parameterArr, unsigned short lineSize);
};