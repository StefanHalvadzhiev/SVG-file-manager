#pragma once
#include "FileManager.h"
#include "Circle.h"
#include "Rectangle.h"

class SVGManager {
	private:
		FileManager fileManager;
		Object** objectArray;

		unsigned currentAmount;
		unsigned maxAmount;

		void resizeObjectArray();
		void destroyObjects();
		void interpretAsObject(char* objectLine, unsigned short lineLen);

		bool circRec(float cx, float cy, float cr, float rx, float ry, float rw, float rh);
		bool circCirc(float c1x, float c1y, float c1r, float c2x, float c2y, float c2r);
		bool recRec(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h);

		float lengthOfLine(float x1, float y1, float x2, float y2);

	public:
		SVGManager();
		~SVGManager();
		void deleteFile(char* fileName);
		void createFile(char* fileName);
		void openFile(char * fileName);
		void closeFile();
		void saveFile();
		void print();
		void create(char* objectType, char** parameters, unsigned short parameterCount);
		void erase(unsigned short objectNumber);
		void translate(float vertical, float horizontal = 0, unsigned short number = 0);
		void within(char* shape, char** parameters, unsigned short parameterCount);
		void loadFromFile();
};