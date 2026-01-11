// This is a simple OOP librabry management system program

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

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

class LibraryContainer {
private:
	vector<Book> bookShelf;

public:
	// Methods
	void addToShelf(Book b) {
		bookShelf.push_back(b);
	}

	void removeFromShelf(Book b) {
		string check_isbn = b.showISBN();
		bool isSuccess = false;
		for (int i = 0; i < bookShelf.size(); i++) {
			if (check_isbn == bookShelf.at(i).showISBN()) {
				bookShelf.erase(bookShelf.begin() + i);
				return;
			}
		}
		if (isSuccess == false) {
			cout << "Can not find book " << b.showTitle() << " (" << b.showISBN()
				<< ")" << endl;
		}
	}

	void showBookShelf() {
		if (bookShelf.empty() == 1) {
			cout << "The library is empty for now ?" << endl;
		}

		int i = 0;
		while (i < bookShelf.size()) {
			string t = bookShelf.at(i).showTitle();
			string a = bookShelf.at(i).showAuthor();
			string isbn = bookShelf.at(i).showISBN();
			bool avail = bookShelf.at(i).showAvailability();
			int y = bookShelf.at(i).showPublicationYear();
			cout << boolalpha;
			cout << i + 1 << ". "
				<< t << " (" << y << ")" << " written by "
				<< a << endl
				<< "ISBN: " << isbn << endl
				<< "On shelf ?: " << avail
				<< endl << endl;
			i++;
		}
		cout << noboolalpha;
	}
};

//int main() {
//	Book steel("Thep da toi the day", "UK guy", "123abc", true, 1990);
//	Book book2("1984", "George Orwell", "456def", true, 1949);
//	LibraryContainer bs;
//	bs.addToShelf(steel);
//	bs.addToShelf(book2);
//	bs.showBookShelf();
//	return 0;
//};

int main() {
    cout << "=== LIBRARY MANAGEMENT SYSTEM TEST ===" << endl;
    cout << "\n--- Test 1: Creating Books ---" << endl;
    Book steel("Thep da toi the day", "UK guy", "123abc", true, 1990);
    Book book2("1984", "George Orwell", "456def", true, 1949);
    Book book3("To Kill a Mockingbird", "Harper Lee", "789ghi", true, 1960);
    Book book4("The Great Gatsby", "F. Scott Fitzgerald", "101jkl", false, 1925);
    cout << "✓ Created 4 books successfully" << endl;

    cout << "\n--- Test 2: Creating Empty Library ---" << endl;
    LibraryContainer bs;
    cout << "✓ Library created" << endl;

    cout << "\n--- Test 3: Showing Empty Library ---" << endl;
    bs.showBookShelf();

    cout << "\n--- Test 4: Adding Books to Library ---" << endl;
    bs.addToShelf(steel);
    cout << "✓ Added: " << steel.showTitle() << endl;
    bs.addToShelf(book2);
    cout << "✓ Added: " << book2.showTitle() << endl;
    bs.addToShelf(book3);
    cout << "✓ Added: " << book3.showTitle() << endl;
    bs.addToShelf(book4);
    cout << "✓ Added: " << book4.showTitle() << endl;

    cout << "\n--- Test 5: Displaying All Books ---" << endl;
    bs.showBookShelf();

    cout << "\n--- Test 6: Removing Existing Book ---" << endl;
    cout << "Attempting to remove: " << book2.showTitle() << endl;
    bs.removeFromShelf(book2);
    cout << "\nLibrary after removal:" << endl;
    bs.showBookShelf();

    cout << "\n--- Test 7: Removing Non-Existent Book ---" << endl;
    Book nonExistent("Fake Book", "Nobody", "999zzz", true, 2000);
    cout << "Attempting to remove non-existent book:" << endl;
    bs.removeFromShelf(nonExistent);

    cout << "\n--- Test 8: Removing First Book ---" << endl;
    cout << "Attempting to remove first book: " << steel.showTitle() << endl;
    bs.removeFromShelf(steel);
    cout << "\nLibrary after removal:" << endl;
    bs.showBookShelf();

    cout << "\n--- Test 9: Removing Last Book ---" << endl;
    cout << "Attempting to remove last book: " << book4.showTitle() << endl;
    bs.removeFromShelf(book4);
    cout << "\nLibrary after removal:" << endl;
    bs.showBookShelf();

    cout << "\n--- Test 10: Removing Until Empty ---" << endl;
    bs.removeFromShelf(book3);
    cout << "\nLibrary after removing all books:" << endl;
    bs.showBookShelf();

    cout << "\n--- Test 11: Adding Books Back ---" << endl;
    bs.addToShelf(steel);
    bs.addToShelf(book2);
    bs.addToShelf(book3);
    cout << "✓ Added 3 books back" << endl;
    bs.showBookShelf();

    cout << "\n--- Test 12: Testing Book Getters ---" << endl;
    cout << "Book details for '" << steel.showTitle() << "':" << endl;
    cout << "  Title: " << steel.showTitle() << endl;
    cout << "  Author: " << steel.showAuthor() << endl;
    cout << "  ISBN: " << steel.showISBN() << endl;
    cout << "  Available: " << boolalpha << steel.showAvailability() << noboolalpha << endl;
    cout << "  Year: " << steel.showPublicationYear() << endl;

    cout << "\n--- Test 13: Testing Availability Update ---" << endl;
    cout << "Before: " << steel.showTitle() << " availability = "
        << boolalpha << steel.showAvailability() << noboolalpha << endl;
    steel.updateAvail(false);
    cout << "After update: " << steel.showTitle() << " availability = "
        << boolalpha << steel.showAvailability() << noboolalpha << endl;
    steel.updateAvail(true);  // Reset
    cout << "Reset to: " << boolalpha << steel.showAvailability() << noboolalpha << endl;

    /*cout << "\n--- Test 14: Adding Duplicate ISBN ---" << endl;
    Book duplicate("Different Title", "Different Author", "123abc", true, 2020);
    cout << "Adding book with duplicate ISBN (123abc):" << endl;
    bs.addToShelf(duplicate);
    cout << "Note: Your system allows duplicates. Consider adding validation!" << endl;
    bs.showBookShelf();*/

    cout << "\n=== ALL TESTS COMPLETED ===" << endl;

    return 0;
}