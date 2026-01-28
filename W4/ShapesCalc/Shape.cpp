#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Shape {
private:
	string type;
public:
	Shape(string t) : type(t){};

	// Destructor
	virtual ~Shape() {};

	virtual double getPerimeter() = 0;
	virtual double getArea() = 0;
	string getType() const {
		return type;
	};

	friend vector<Shape*> readFile(string fileName);
};

class Rectangle : public Shape {
private:
	// it got every things from Shape's private + its own
	double dHeight;
	double dWidth;
public:
	Rectangle(double h, double w) : Shape("Rectangle"), dHeight(h), dWidth(w) {};

	double getPerimeter() override {
		double result = (dHeight + dWidth) * 2;
		return result;
	};

	double getArea() override {
		double result = dHeight * dWidth;
		return result;
	};
};

double const PI = 3.14;

class Circle : public Shape {
private:
	double dRadius;
public:
	Circle(double r) : Shape("Circle"), dRadius(r) {};

	double getPerimeter() override {
		return 2 * dRadius * PI;
	};

	double getArea() override {
		return PI * pow(dRadius, 2);
	};
};

class Trapezium : public Shape {
private:
	double dHeight;
	double dSmall;
	double dBig;
	double leftS;
	double rightS;
public:
	Trapezium(double h, double s, double b, double ls, double rs ) : Shape("Trapezium"), dHeight(h), dSmall(s), dBig(b), leftS(ls), rightS(rs) {};

	double getPerimeter() override {
		return dSmall + dBig + leftS + rightS;
	};

	double getArea() override {
		return 0.5 * (dSmall + dBig) * dHeight;
	};
};


// Helper function:
void shapeInfo(Shape& s) {
	[](string type) {cout << "This shape is " << type << endl; }(s.getType());
	[](double result) {cout << "Perimeter of this shape is " << result << endl; }(s.getPerimeter());
	[](double result) {cout << "Area of this shape is " << result << endl; }(s.getArea());
};

void ptrShapeInfo(Shape* sptr) {
	[](string type) {cout << "This shape is " << type << endl; }(sptr->getType());
	[](double result) {cout << "Perimeter of this shape is " << result << endl; }(sptr->getPerimeter());
	[](double result) {cout << "Area of this shape is " << result << endl; }(sptr->getArea());
	[](Shape* add) {cout << "The memory address of it: " << add << endl; }(sptr);
};

istream& readFile(istream& istr, string fileName) {
	string text;
	istr.read(fileName);
	while (getline())
	return istr;
};


// Main prog
int main() {
	// Rectangle
	Rectangle r(2, 3);
	/*shapeInfo(r);*/
	Shape* rptr = &r;
	ptrShapeInfo(rptr);
	cout << &r << endl;
	cout << "====================" << endl;

	// Circle
	Circle c(2);
	/*shapeInfo(c);*/
	Shape* cptr = &c;
	ptrShapeInfo(rptr);
	cout << &c << endl;
	cout << "====================" << endl;

	// Trapezium
	Trapezium t(2, 3, 4, 5, 6);
	/*shapeInfo(t);*/
	Shape* tptr = &t;
	ptrShapeInfo(rptr);
	cout << &t << endl;

	return 0;
};