#include <iostream>

using namespace std;

// Product classes
class Course {
public:
	virtual ~Course() {};
	virtual void essential() {};
};

// ConcreteProduct
class TechCourse : public Course {
public:
	void essential() override {
		cout << "Laptop";
	}
};

class FinCourse : public Course {
public:
	void essential() override {
		cout << "Sheet";
	}
};


// CREATOR and Factories
class CourseMan {
public:
	virtual ~CourseMan() {};
	virtual Course* assignCourse() = 0;// This is the Factory Method
	void handEssential() {
		Course* chosenCourse = assignCourse();
		chosenCourse->essential();
		delete chosenCourse;	// when the function end, the memory still being taken => memory leak
	};
};

// Factories
class TechCourseFactory : public CourseMan {
public:
	Course* assignCourse() override {
		return new TechCourse();
	}
};

class FinCourseFactory : public CourseMan {
public:
	Course* assignCourse() override {
		return new FinCourse();
	}
};