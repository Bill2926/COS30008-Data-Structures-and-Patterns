// This class will represent the document itself
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Document {
private:
	vector<string> doc;
public:
	Document();

	void insertDoc(const vector<string>& tempDoc);
	void insertLine(string aLine);
	void deleteLine(size_t lineIndex);
	void editLine(size_t lineIndex, string editContent);
	void showDoc();
	const vector<string>& getDoc() const;
};