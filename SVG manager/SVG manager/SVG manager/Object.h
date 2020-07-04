#pragma once

/// <summary>
/// This is the base class for all SVG objects.
/// </summary>

class Object {
	protected: 
		char* objectTranslation;
		char* objectName;
		unsigned short getDigitCount(long long number);
	public:
		Object();
		virtual ~Object();
		virtual char* getName();
		virtual void printInformation();
		virtual char* translateInSVG();
		virtual void changeHorizontally(float constant);
		virtual void changeVertically(float constant);
		void floatToString(double num, char*& string, unsigned short precision);
		virtual float getX();
		virtual float getY();
		virtual float getWidth();
		virtual float getHeight();
		virtual float getRadius();
};	