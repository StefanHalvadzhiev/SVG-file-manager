#pragma once
#include "Object.h"

class Rectangle :public Object {
	private:
		float x, y;
		float width, height;
		char* color;
	public:
		Rectangle(const double x, const double y,const double width, const double height, const char* color);
		Rectangle();
		~Rectangle();

		float getX();
		float getY();
		float getWidth();
		float getHeight();

		void changeHorizontally(float constant);
		void changeVertically(float constant);
		void printInformation();

		char* translateInSVG();
		char* getName();
};