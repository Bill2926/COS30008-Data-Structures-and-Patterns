// This is a simple OOP librabry management system program

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Book {
public:
	string title;
	string author;
	string ISBN;
	bool isAvailable;
	int publicationYear;

	// Constructor
	Book(string title, string auth, string ISBN, bool avail, int publicY)
		: title(title), author(auth), ISBN(ISBN),
		isAvailable(avail), publicationYear(publicY) {
		// another logic (optional)
	}

	// Getter functions
	string showTitle() const { return title; }
	string showAuthor() const { return author; }
	string showISBN() const { return ISBN; }
	bool showAvailability() const { return isAvailable; }
	int showPublicationYear() const { return publicationYear; }

	// Setters
	void updateAvail(bool status) { isAvailable = status; }
};

int main() {
	Book steel("Thep da toi the day", "UK guy", "123abc", true, 1990);

	cout << steel.showTitle() << " written by " << steel.author << endl;

	return 0;
};