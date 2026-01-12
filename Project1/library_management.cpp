// This is a simple OOP librabry management system program
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

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

class Member {
private:
	int id;
	string name;
	string phone;
	vector<string> borrowed_book_isbn;
	int borrowLimit;

	int genUserId() {
		return (rand() % 100) + 1; // between 1 and 100; 
	}

public:
	// Constructor
	Member(string new_name, string new_phone)
		: id(genUserId()), name(new_name), phone(new_phone), borrowLimit(3) {
	}

	// Getters
	int showID() const { return id; }
	string showUName() const { return name; }
	string showPhone() const { return phone; }
	int showBorrowLimit() const { return borrowLimit; }
	int numberOfBorrowed() const { return borrowed_book_isbn.size(); }
	vector<string> showBorrowedList() const { return borrowed_book_isbn; }

	// Setters
	void setName(const string& newName) { name = newName; }
	void setPhoneNumber(const string& newPhone) { phone = newPhone; }
	void borrowBook(const string& isbn) { borrowed_book_isbn.push_back(isbn); }
};

class Library {
private:
	vector<Book> bookShelf;
	vector<Member> memberList;

public:
	// Methods
	void addToShelf(Book b) {
		for (int i = 0; i < bookShelf.size(); i++) {
			if (bookShelf.at(i).showISBN() == b.showISBN()) {
				cout << "This book ISBN is already in the library." << endl;
				return;
			}
		}
		bookShelf.push_back(b);
		cout << "Added book successfully." << endl;
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

	void registerMember(string name, string phone) {
		for (int i = 0; i < memberList.size(); i++) {
			if (memberList.at(i).showPhone() == phone) {
				cout << "Phone number is already used." << endl;
				return;
			}
		}
		Member newMember = Member(name, phone);
		memberList.push_back(newMember);
		cout << "Registered successfully with ID: " << newMember.showID() << endl;
	}

	void borrowBook(int member_id, string book_isbn) {
		// Init null pointers
		Member* m = nullptr;
		Book* b = nullptr;

		// Find member by id and see if they already hit the limit
		for (int i = 0; i < memberList.size(); i++) {
			if (memberList.at(i).showID() == member_id) {
				m = &memberList.at(i);
				break;
			}
		}

		if (m == nullptr) {
			cout << "Can not find the member ID." << endl;
			return;
		}

		if (m->numberOfBorrowed() == m->showBorrowLimit()) {
			cout << "This user can not borrow this time. Please return some books first." << endl;
			return;
		}

		// Find book by isbn
		for (int i = 0; i < bookShelf.size(); i++) {
			if (bookShelf.at(i).showISBN() == book_isbn) {
				b = &bookShelf.at(i);
				break;
			}
		}

		if (b == nullptr) {
			cout << "Can not find the book ISBN." << endl;
			return;
		}

		if (b->showAvailability() == 0) {
			cout << "This book is not available now." << endl;
			return;
		}

		// All passed
		b->updateAvail(false);
		m->borrowBook(book_isbn);
	}
};

int main() {
	srand(time(0));

	cout << "=== LIBRARY SYSTEM TEST ===" << endl;

	Library lib;

	// Add books
	cout << "\n1. Adding books..." << endl;
	lib.addToShelf(Book("1984", "Orwell", "001", true, 1949));
	lib.addToShelf(Book("Mockingbird", "Lee", "002", true, 1960));
	lib.showBookShelf();

	// Register members
	cout << "\n2. Registering members..." << endl;
	lib.registerMember("Alice", "111-1111");
	lib.registerMember("Bob", "222-2222");

	// Test borrowing (Note: IDs are random!)
	/*Member alice("Alice", "111-1111");*/
	/*cout << "\n3. Alice (ID: " << alice.showID() << ") borrows book..." << endl;*/
	int input_id;
	cout << "Your id?: ";
	cin >> input_id;
	lib.borrowBook(input_id, "001");

	lib.showBookShelf();

	cout << "\n=== TEST COMPLETE ===" << endl;
	return 0;
}