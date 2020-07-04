#pragma once
class SVGObject {
	protected:
		double x;
		double y;
		char* fill;
	public:
		SVGObject();
		~SVGObject();
		virtual void setX(const double x);
		virtual void setY(const double y);
		virtual double getX();
		virtual double getY();
		void setFill(const char* color);
};