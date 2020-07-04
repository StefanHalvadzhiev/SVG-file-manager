#pragma once
#include "Object.h"



class Circle : public Object {
	private:
		float x, y;
		float radius;
		char* color;
		 
	public:
		Circle(const float x, const float y, const float radius, const char* color);
		Circle();
		~Circle();

		float getX();
		float getY();
		float getRadius();

		void changeHorizontally(float constant);
		void changeVertically(float constant);
		void printInformation();

		char* translateInSVG();
		char* getName();
};