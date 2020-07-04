#pragma once
#include "FileManager.h"
#include "Circle.h"
#include "Rectangle.h"

/// <summary>
/// Main class that contains svg file handler and an array of svg objects.
/// </summary>
class SVGManager {
	private:
		/// Instance of the file managing system.
		FileManager fileManager;

		/// Polymorphic array
		Object** objectArray;

		/// Current amount of elemnts in the array.
		unsigned currentAmount;

		/// Maximum amount of elements in the array.
		unsigned maxAmount;

		/// Resizes the polymorphic array.
		void resizeObjectArray();

		/// Removes all objects in polymorphic array.
		void destroyObjects();

		/// Interpreting a line in a file as an svg object.
		void interpretAsObject(char* objectLine, unsigned short lineLen);

		/// Detects whether a circle is inside a rectangle.
		bool circRec(float cx, float cy, float cr, float rx, float ry, float rw, float rh);

		/// Detects whether a circle is inside another circle.
		bool circCirc(float c1x, float c1y, float c1r, float c2x, float c2y, float c2r);

		/// Detects whether a rectangle is inside another rectangle.
		bool recRec(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h);

		/// Calculates the length of a line with given coordinates.
		float lengthOfLine(float x1, float y1, float x2, float y2);
	public:
		SVGManager();
		~SVGManager();

		/// Calls the file manager delete function.
		void deleteFile(char* fileName);

		/// Calls the file manager create function.
		void createFile(char* fileName);

		/// Calls the file manager open function.
		void openFile(char * fileName);

		/// Calls the file manager close function.
		void closeFile();

		/// Saves the information from the polymorphic array in the currently opened file.
		void saveFile();

		/// Prints all SVG objects in the array.
		void print();

		/// Creates SVG object.
		void create(char* objectType, char** parameters, unsigned short parameterCount);

		/// Erases an element from the polymorphic array.
		void erase(unsigned short objectNumber);

		/// Translates SVG horizontally / vertically.
		void translate(float vertical, float horizontal = 0, unsigned short number = 0);

		/// Calls boolean intersection functions.
		void within(char* shape, char** parameters, unsigned short parameterCount);

		/// Loads information from the currently opened file.
		void loadFromFile();
};