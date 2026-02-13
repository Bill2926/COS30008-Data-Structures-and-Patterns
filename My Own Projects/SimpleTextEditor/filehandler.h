// This class handle file handling

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class FileHandler {
private:
	vector<string> tempDoc;
	string fileName;
	fstream fileHandler;
public:
	FileHandler(string fn);

	vector<string>& loadFile();
	void saveFile(const vector<string>& doc);
};