#include "Circle.h"
#include <cstring>
#include <iostream>
using namespace std;

Circle::Circle() {
	objectName = new char[7];
	x = 0;
	y = 0;
	radius = 0;
	color = new char[8];
	strcpy(objectName, "circle");
}

Circle::~Circle() {
	delete[] objectName;
	delete[] color;
}

Circle::Circle(const float x, const float y, const float radius, const char* color) {
	this->x = x;
	this->y = y;
	this->radius = radius;
	this->color = new char[strlen(color) + 1];
	strcpy(this->color, color);
	this->objectName = new char[7];
	strcpy(objectName, "circle");
}

void Circle::printInformation() {
	std::cout << "Type: Circle, x: " << x << ", y: " << y << ", radius: " << radius << ", color: " << color << std::endl;
}

char* Circle::translateInSVG() {
	char* floatString = nullptr;
	strcpy(objectTranslation, "<circle x=\"");
	floatToString(x, floatString, 3);
	strcat(objectTranslation, floatString);
	strcat(objectTranslation, "\" ");

	strcat(objectTranslation, "y=\"");
	floatToString(y, floatString, 3);
	strcat(objectTranslation, floatString);
	strcat(objectTranslation, "\" ");

	strcat(objectTranslation, "r=\"");
	floatToString(radius, floatString, 3);
	strcat(objectTranslation, floatString);
	strcat(objectTranslation, "\" ");

	strcat(objectTranslation, "fill=\"");
	strcat(objectTranslation, color);
	strcat(objectTranslation, "\"/>");
	return objectTranslation;
}

void Circle::changeHorizontally(float constant) {
	y += constant;
}

void Circle::changeVertically(float constant) {
	x += constant;
}

float Circle::getX() {
	return x;
}

float Circle::getY() {
	return y;
}

float Circle::getRadius() {
	return radius;
}

char* Circle::getName() {
	return objectName;
}