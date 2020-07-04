#pragma once
#include "Object.h"

/// <summary>
/// This class inherits the base class Object and represents an SVG rectangle.
/// </summary>

class Rectangle :public Object {
	private:
		float x, y;
		float width, height;
		char* color;
	public:
		Rectangle(const double x, const double y,const double width, const double height, const char* color);
		Rectangle();
		~Rectangle();
		/// Returns the X coordinate of the rectangle.
		float getX();

		/// Returns the Y coordinate of the rectangle.
		float getY();

		/// Returns the width of the rectangle.
		float getWidth();

		/// Returns the height of the rectangle.
		float getHeight();

		/// Increases / decreases the X coordinate of the rectangle.
		void changeHorizontally(float constant);

		/// Increases / decreases the Y coordinate of the rectangle.
		void changeVertically(float constant);

		/// Prints the information about the rectangle (x, y, width, height, color).
		void printInformation();

		/// Translates the information about the rectangle as an html tag.
		char* translateInSVG();
		char* getName();
};