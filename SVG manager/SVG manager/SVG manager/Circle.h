#pragma once
#include "Object.h"

/// <summary>
/// This class represents an SVG circle and inherits the Object class
/// </summary>

class Circle : public Object {
	private:
		float x, y;
		float radius;
		char* color;
	public:
		Circle(const float x, const float y, const float radius, const char* color);
		Circle();
		~Circle();
		/// Returns the X coordinate of the circle.
		float getX();

		/// Returns the Y coordinate of the circle.
		float getY();

		/// Returns the radius of the circle.
		float getRadius();

		/// Increases / decreases the X coordinate of the circle.
		void changeHorizontally(float constant);

		/// Increases / decreases the Y coordinate of the circle.
		void changeVertically(float constant);

		/// Prints information about the circle (x, y, radius, color).
		void printInformation();

		/// Translates the information about the circle as an html tag.
		char* translateInSVG();
		char* getName();
};