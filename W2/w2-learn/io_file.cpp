#pragma once
#include <iostream>
#include <fstream> // Used when working with external files
#include <string>

using namespace std;

int main() {
	/*string arr[3];
	int i = 0;
	ifstream readOnlyFile("Text.txt");*/
	/*string eachLine;*/
	/*if (readOnlyFile.is_open()) {
		while (getline(readOnlyFile, eachLine)) {
			cout << eachLine << endl;
		}
		readOnlyFile.close();
	}*/

	/*while (readOnlyFile >> arr[i]) {
		i++;
	};


	for (int index = 0; index < sizeof(arr) / sizeof(arr[0]); index++) {
		cout << arr[index] << endl;
	};*/
	/*ofstream iWillWrite("Text.txt", ios::ate);
	if (iWillWrite.is_open()) {
		iWillWrite << "\nAI Engineer" << endl;
		iWillWrite << "Swinburne Australia" << endl;
		cout << "Done!!" << endl;
		iWillWrite.close();
	}*/

	string arr[3] = { "node1", "node2", "node3" };
	int elementNum = sizeof(arr) / sizeof(arr[0]);
	// Circle
	for (int i = 0; i < elementNum; i++) {
		/*if (i != 0 && elementNum % i == 0) {
			cout << arr[i] << " connected to " << arr[0];
			break;
		};*/
		/*cout << elementNum << endl;
		cout << i << endl;*/
		/*if (i == elementNum - 1) {
			cout << arr[i] << " connected to " << arr[0];
			break;
		}*/
		int next_index = (i + 1) % elementNum;
		cout << arr[i] << " connected to " << arr[next_index] << endl;
	};

	return 0;
}