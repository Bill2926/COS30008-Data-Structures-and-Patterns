#include <iostream>
#include <string>
#include <vector>

using namespace std;

unsigned long factorial(unsigned long n) {

	// The BASE (a small enough problem to end): termination condition since 1! and 0! are still 1
	if (n < 2) {
		return 1;
	}

	// Deferred operation: it waits until the multiplication is done
	return n * factorial(n - 1);	// recursion -> call itself
}

unsigned long fibonacci(unsigned long n) {
	if (n <= 2) {
		return 1;
	}

	return fibonacci(n - 1) + fibonacci(n - 2);
}

void happyNewYear(int n) {
	if (n == 0) {
		cout << 0 << endl;
		return;
	}

	cout << n << endl;
	happyNewYear(n - 1);

}

int sum(int n) {
	if (n == 1) {
		return 1;
	}
	return n + sum(n - 1);
}

string rev(string aString, int length) {
	//if (length == 1) {
	//	return aString[0];
	//}
	if (length == 1) {
		return string(1, aString[0]);
	}
	return aString[length-1] + rev(aString, length - 1);
}



int main() {
	//cout << "Recursion for n=5: " << factorial(5) << endl;
	//cout << "The 11th num in Fib is: " << fibonacci(11) << endl;
	//happyNewYear(5);

	//cout << "Sum of 10: " << sum(10) << endl;
	//cout << rev("happy", 5) << endl;

	return 0;
}