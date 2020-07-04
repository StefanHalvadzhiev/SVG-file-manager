#include "Object.h"
#include <cstring>
#include <math.h>
#include <iostream>
using namespace std;

void Object::floatToString(double number, char*& string, unsigned short precision) {
	long long newNumber = abs(number * pow(10, precision));
	if (string != nullptr)
		delete[] string;
	unsigned short numberOfDigits = getDigitCount(newNumber);
	short constant = 2;
	if (number < 1 && number > 0)
		constant = 3;
	else if (number > -1 && number < 0)
		constant = 4;
	else if (number < -1)
		constant = 3;
	string = new char[numberOfDigits + constant];
	string[numberOfDigits + constant - 1] = '\0';
	for (short i = numberOfDigits + constant - 2; i >= constant-2; i--) {
		if (i == numberOfDigits + constant - precision - 1) {
			string[i] = 48 + newNumber % 10;
			string[i - 1] = '.';
			i--;
			newNumber /= 10;
		}
		else {
			string[i] = 48 + newNumber % 10;
			newNumber /= 10;
		}
	}
	if (number < 1 && number > 0) 
		string[0] = '0';
	else if (number > -1 && number < 0) {
		string[0] = '-';
		string[1] = '0';
	}
	else if (number <= -1)
		string[0] = '-';
}

unsigned short Object::getDigitCount(long long number) {
	unsigned short digits = 0; 
	while (number != 0) { 
		number /= 10; 
		digits++; 
	}
	return digits;
}

Object::Object() {
	objectTranslation = new char[200];
}

Object::~Object() {
	delete[] objectTranslation;
}

char* Object::translateInSVG() {
	char* nothing = nullptr;
	return nothing;
}

void Object::printInformation() {
	std::cout << "This is an object" << std::endl;
}

void Object::changeHorizontally(float constant) {
	return;
}

void Object::changeVertically(float constant) {
	return;
}

char* Object::getName() {
	cout << "This is a basic object." << endl;
	return nullptr;
}

float Object::getX() {
	return 0;
}
float Object::getY() {
	return 0;
}
float Object::getWidth() {
	return 0;
}
float Object::getHeight() {
	return 0;
}
float Object::getRadius() {
	return 0;
}
