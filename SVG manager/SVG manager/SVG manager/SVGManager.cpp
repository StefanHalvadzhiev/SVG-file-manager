#include "SVGManager.h"
#include <iostream>
#include "Object.h"
#include "Circle.h"
#include <math.h>
using namespace std;

void SVGManager::deleteFile(char* fileName) {
	fileManager.deleteFile(fileName);
}

void SVGManager::createFile(char* fileName) {
	fileManager.createFile(fileName);
}

void SVGManager::openFile(char* fileName) {
	cout << "Opening file.." << endl;
	fileManager.openFile(fileName);
	loadFromFile();
}

void SVGManager::closeFile() {
	destroyObjects();
	fileManager.closeFile();
}

void SVGManager::saveFile() {
	fileManager.emptyFile();
	fileManager.writeToFile("<svg>");
	for (unsigned short i = 0; i < currentAmount; i++)
		fileManager.writeToFile(objectArray[i]->translateInSVG());
	fileManager.writeToFile("</svg>");
	cout << "Contents saved." << endl;
}

void SVGManager::print() {
	if (!fileManager.checkIfOpen()) {
		cout << "No file opened." << endl;
		return;
	}
	for (unsigned i = 0; i < currentAmount; i++) {
		cout << i + 1 << ". ";
		this->objectArray[i]->printInformation();
	}
}

void SVGManager::create(char* objectType, char** parameters, unsigned short parameterCount) {
	if (!fileManager.checkIfOpen()) {
		cout << "No file opened. Can not create object." << endl;
		return;
	}
	if (strcmp(objectType, "circle") == 0) {
		if (parameterCount < 4) {
			cout << "Insufficient parameters" << endl;
			return;
		}
		Circle* newCircle = new Circle(atof(parameters[0]),atof(parameters[1]), atof(parameters[2]), parameters[3]);
		objectArray[currentAmount] = newCircle;
		currentAmount++;
		if (currentAmount == maxAmount)
			resizeObjectArray();
	}
	if (strcmp(objectType, "rectangle") == 0) {
		if (parameterCount < 5) {
			cout << "Insufficient parameters" << endl;
			return;
		}
		Rectangle* newRect = new Rectangle(atof(parameters[0]), atof(parameters[1]), atof(parameters[2]), atof(parameters[3]), parameters[4]);
		objectArray[currentAmount] = newRect;
		currentAmount++;
		if (currentAmount == maxAmount)
			resizeObjectArray();
	}
}

void SVGManager::translate(float vertical, float horizontal, unsigned short number) {
	if (!fileManager.checkIfOpen()) {
		cout << "No file opened. Can not execute command." << endl;
		return;
	}
	if (number == 0) {
		for (unsigned short i = 0; i < currentAmount; i++) {
			objectArray[i]->changeVertically(vertical);
			objectArray[i]->changeHorizontally(horizontal);
		}
		cout << "Changed values for all objects" << endl;
		return;
	}
	if (number > currentAmount) {
		cout << "Invalid number" << endl;
		return;
	}
	objectArray[number - 1]->changeVertically(vertical);
	objectArray[number - 1]->changeHorizontally(horizontal);
	cout << "Changed value for  object " << number << endl;
}

void SVGManager::within(char* shape, char** parameters, unsigned short parameterCount) {
	if (!fileManager.checkIfOpen()) {
		cout << "No file opened. Can not execute command." << endl;
		return;
	}
	bool checker = false;
	bool anyWithin = false;
	if (strcmp(shape, "circle") == 0) {
		if (parameterCount < 3) {
			cout << "Insufficient parameters" << endl;
			return;
		}
		cout << "Objects within: " << endl;
		for (unsigned short i = 0; i < currentAmount; i++) {
			checker = false;
			if (strcmp(objectArray[i]->getName(), "circle") == 0) {
				if (circCirc(atof(parameters[0]), atof(parameters[1]), atof(parameters[2]), objectArray[i]->getX(), objectArray[i]->getY(), objectArray[i]->getRadius())) {
					anyWithin = true;
					checker = true;
				}
			}
			else if (strcmp(objectArray[i]->getName(), "rectangle") == 0) {
				if (circRec(atof(parameters[0]), atof(parameters[1]), atof(parameters[2]), objectArray[i]->getX(), objectArray[i]->getY(), objectArray[i]->getWidth(), objectArray[i]->getHeight())) {
					anyWithin = true;
					checker = true;
				}
			}
			if (checker == true) {
				cout << i + 1 << ". ";
				objectArray[i]->printInformation();
				cout << endl;
			}
		}
	}
	else if (strcmp(shape, "rectangle") == 0) {
		if (parameterCount < 5) {
			cout << "Insufficient parameters" << endl;
			return;
		}
		cout << "Objects within: " << endl;
		for (unsigned short i = 0; i < currentAmount; i++) {
			checker = false;
			if (strcmp(objectArray[i]->getName(), "circle") == 0) {
				if (circRec(objectArray[i]->getX(), objectArray[i]->getY(), objectArray[i]->getRadius(), atof(parameters[0]), atof(parameters[1]), atof(parameters[2]), atof(parameters[3]))) {
					anyWithin = true;
					checker = true;
				}
			}
			else if (strcmp(objectArray[i]->getName(), "rectangle") == 0) {
				if (recRec(atof(parameters[0]), atof(parameters[1]), atof(parameters[2]), atof(parameters[3]), objectArray[i]->getX(), objectArray[i]->getY(), objectArray[i]->getWidth(), objectArray[i]->getHeight())) {
					anyWithin = true;
					checker = true;
				}
			}
			if (checker == true) {
				cout << i + 1 << ". ";
				objectArray[i]->printInformation();
				cout << endl;
			}
		}

	}
	if (!anyWithin)
		cout << "No objects within." << endl;
	cout << "======" << endl;
}

SVGManager::SVGManager() {
	objectArray = new Object*[20];
	currentAmount = 0;
	maxAmount = 20;
}

SVGManager::~SVGManager() {
	delete[] objectArray;
}

void SVGManager::resizeObjectArray() {
	Object** copyArray;
	copyArray = new Object * [maxAmount];
	for (unsigned short i = 0; i < currentAmount; i++)
		copyArray[i] = objectArray[i];
	maxAmount += 20;
	delete[] objectArray;
	objectArray = new Object * [maxAmount];
	for (unsigned i = 0; i < currentAmount; i++)
		objectArray[i] = copyArray[i];
	delete[] copyArray;
}

void SVGManager::destroyObjects() {
	for (unsigned short i = 0; i < currentAmount; i++)
		delete objectArray[i];
	currentAmount = 0;
}

void SVGManager::erase(unsigned short position) {
	if (position > currentAmount) {
		cout << "There is no object on position " << position << endl;
		return;
	}
	else if (position == 0) {
		cout << "Can not delete 0 element" << endl;
		return;
	}
	delete objectArray[position-1];
	for (unsigned short i = position - 1; i < currentAmount - 1; i++) 
		objectArray[i] = objectArray[i + 1];
	currentAmount--;
	cout << "Done" << endl;
}

void SVGManager::loadFromFile() {
	unsigned short lineCount = fileManager.getLineCount();
	char** parametersFromFile = new char* [lineCount];
	for (unsigned short i = 0; i < lineCount; i++)
		parametersFromFile[i] = new char[250];
	fileManager.getLines(parametersFromFile, 250);
	for (unsigned short i = 0; i < lineCount; i++)
		interpretAsObject(parametersFromFile[i], strlen(parametersFromFile[i]) + 1);

	cout << "Content loaded" << endl;
	for (unsigned short i = 0; i < lineCount; i++)
		delete[] parametersFromFile[i];
	delete[] parametersFromFile;
}

void SVGManager::interpretAsObject(char* objectLine, unsigned short lineLen) {
	char objectType[10];
	short counter = 0;
	for(unsigned short i = 0; i < lineLen-1; i++)
		if (objectLine[i] != '<' && objectLine[i] != ' ') {
			objectType[counter] = objectLine[i];
			counter++;
		}
		else if (objectLine[i] == ' ') {
			objectType[counter] = '\0';
			break;
		}
	char** parametersForObject;
	unsigned short parameterCount = 0;
	if (strcmp(objectType, "circle") == 0)
		parameterCount = 4;
	if (strcmp(objectType, "rectangle") == 0)
		parameterCount = 5;
	parametersForObject = new char* [parameterCount];
	for (unsigned short i = 0; i < parameterCount; i++) {
		parametersForObject[i] = new char[50];
	}

	bool checker = false;
	counter = -1;
	short inStringPos = 0;
	for (unsigned short i = strlen(objectType) + 2; i < lineLen; i++) {
		if (objectLine[i] == '\"') {
			if (checker == false) {
				checker = true;
				counter++;
				inStringPos = 0;
				i++;
			}
			else {
				checker = false;
				i++;
				if (inStringPos != 0) {
					parametersForObject[counter][inStringPos] = '\0';
				}
			}
		}
		if (checker == true) {
			parametersForObject[counter][inStringPos] = objectLine[i];
			inStringPos++;
		}
	}

	create(objectType, parametersForObject, parameterCount);

	for (unsigned short i = 0; i < parameterCount; i++)
		delete[] parametersForObject[i];
	delete[] parametersForObject;
}

float SVGManager::lengthOfLine(float x1, float y1, float x2, float y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool SVGManager::circCirc(float c1x, float c1y, float c1r, float c2x, float c2y, float c2r){
	float lenFromCenterToCenter = lengthOfLine(c1x, c1y, c2x, c2y);
	if (lenFromCenterToCenter + c2r -c1r <= 0)
		return true;
	return false;
}

bool SVGManager::circRec(float cx, float cy, float cr, float rx, float ry, float rw, float rh) {
	float distX = abs(cx - (rx + rw / 2));
	float distY = abs(cx - (rx + ry / 2));
	if (distX + cr> (rw / 2) || distY + cr > (rh / 2 + cr))
		return false; 

	if (distX + cr <= (rw / 2) && distY + cr <= (rh / 2))
		return true;
}

bool SVGManager::recRec(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h) {
	float distX = abs(r2x + r2w / 2 - (r1x + r1w / 2));
	float distY = abs(r2y + r2h / 2 - (r1y + r1h / 2));
	if (distX + r2w / 2 <= r1w && distY + r2h / 2 <= r1h)
		return true;
	return false;
}