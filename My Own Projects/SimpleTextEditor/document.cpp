// This class will represent the document itself
#include "document.h"


Document::Document() {};

void Document::insertDoc(const vector<string>& tempDoc) {
	doc = tempDoc;
};

void Document::insertLine(string aLine) {
	// Insert to the last line
	doc.push_back(aLine);
};

void Document::deleteLine(size_t lineIndex) {
	if (lineIndex > 0 && lineIndex - 1 < doc.size()) {
		// Erase needs an iterator
		size_t actualIndex = lineIndex - 1;
		doc.erase(doc.begin() + actualIndex);
	}
	else {
		cout << "Error: Line " << lineIndex << " does not exist." << endl;
	}
};

void Document::editLine(size_t lineIndex, string editContent) {
	if (lineIndex > 0 && lineIndex - 1 < doc.size()) {
		size_t actualIndex = lineIndex - 1;
		doc.at(actualIndex) = editContent;
	}
	else {
		cout << "Error: Line " << lineIndex << " does not exist." << endl;
	}
};

void Document::showDoc() {
	int i = 1;
	for (const string& aLine : doc) {
		cout << i << ".   " << aLine << endl;
		i++;
	}
};

const vector<string>& Document::getDoc() const {
	return doc;
};