#include "filehandler.h"

FileHandler::FileHandler(string fn) : fileName(fn) {};

vector<string>& FileHandler::loadFile() {
	fileHandler.open(fileName, ios::in);
	string aLine;
	while (getline(fileHandler, aLine)) {
		tempDoc.push_back(aLine);
	}
	fileHandler.close();
	return tempDoc;
};

void FileHandler::saveFile(const vector<string>& doc) {
	fileHandler.open(fileName, ios::out);
	tempDoc = doc;
	fileHandler << tempDoc.at(0);
	for (int i = 1; i < tempDoc.size(); i++) {
		fileHandler << endl << tempDoc.at(i);
	}
	fileHandler.close();
};