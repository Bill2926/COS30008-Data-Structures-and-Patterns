#include "iterator.cpp"
#include "range.cpp"
#include <iostream>

using namespace std;

int main() {
	Range r(2, 10, 2);
	Iterator i(r);

	for (auto it = r.begin(); it != r.end(); ++it) {
		cout << *it << endl;
	}
	

	return 0;
};