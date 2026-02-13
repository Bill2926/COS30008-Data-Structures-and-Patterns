#pragma once
#include <iostream>
#include <string>
#include "document.h"
#include "filehandler.h"

using namespace std;

int main() {
	Document sample;
	Document* ptr = &sample;
	FileHandler fhandler("abc.txt");
	sample.insertDoc(fhandler.loadFile());
	
	string choice;
	cout << "Simple Text Editor C++ " << endl;
	cout << "Enter editor mode you want:" << endl << "> ";
	cin >> choice;
	if (choice == "ins") {
		string input;
		cout << "Type in to insert: " << endl << "> ";
		cin.ignore(1000, '\n'); // Simple version of ignore
		getline(cin, input);
		sample.insertLine(input);
		sample.showDoc();
		fhandler.saveFile(sample.getDoc());
	}
	else if (choice == "ed") {
		size_t index;
		string input;

		cout << "Type in the line number you want to edit: " << endl << "> ";
		cin.ignore(1000, '\n');
		cin >> input;	// Only takes str so I have to parse into size_t
		unsigned long long temp = stoull(input);
		index = static_cast<size_t>(temp);

		cout << "Make your changes: " << endl << "> ";
		getline(cin, input);
		sample.editLine(index, input);
		sample.showDoc();
		fhandler.saveFile(sample.getDoc());
	}
	else if (choice == "del") {
		size_t index;
		string input;

		cout << "Type in the line number you want to edit: " << endl << "> ";
		cin.ignore(1000, '\n');
		cin >> input;
		unsigned long long temp = stoull(input);
		index = static_cast<size_t>(temp);
		sample.deleteLine(index);
		sample.showDoc();
		fhandler.saveFile(sample.getDoc());
	}
	else if (choice == "sh") {
		sample.showDoc();
	}

	return 0;
}