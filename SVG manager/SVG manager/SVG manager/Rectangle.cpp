#include "Rectangle.h"
#include <cstring>
#include <iostream>

Rectangle::Rectangle() {
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	color = new char[8];
	objectName = new char[10];
	strcpy(objectName, "rectangle");
}

Rectangle::~Rectangle() {
	delete[] color;
	delete[] objectName;
}

Rectangle::Rectangle(const double x, const double y, const double width, const double height, const char* color) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->color = new char[strlen(color) + 1];
	strcpy(this->color, color);
	objectName = new char[10];
	strcpy(objectName, "rectangle");
}

void Rectangle::printInformation() {
	std::cout << "Type: Rectangle, x: " << x << ", y: " << y << ", width: " << width << ", height: " << height << ", color: " << color << std::endl;
}

char* Rectangle::translateInSVG() {
	char* floatString = nullptr;
	strcpy(objectTranslation, "<rectangle x=\"");
	floatToString(x, floatString, 3);
	strcat(objectTranslation, floatString);
	strcat(objectTranslation, "\" ");

	strcat(objectTranslation, "y=\"");
	floatToString(y, floatString, 3);
	strcat(objectTranslation, floatString);
	strcat(objectTranslation, "\" ");

	strcat(objectTranslation, "width=\"");
	floatToString(width, floatString, 3);
	strcat(objectTranslation, floatString);
	strcat(objectTranslation, "\" ");

	strcat(objectTranslation, "height=\"");
	floatToString(height, floatString, 3);
	strcat(objectTranslation, floatString);
	strcat(objectTranslation, "\" ");

	strcat(objectTranslation, "fill=\"");
	strcat(objectTranslation, color);
	strcat(objectTranslation, "\"/>");
	return objectTranslation;
}

void Rectangle::changeHorizontally(float constant) {
	y += constant;
}

void Rectangle::changeVertically(float constant) {
	x += constant;
}

float Rectangle::getX() {
	return x;
}

float Rectangle::getY() {
	return y;
}

float Rectangle::getWidth() {
	return width;
}

float Rectangle::getHeight() {
	return height;
}

char* Rectangle::getName() {
	return objectName;
}