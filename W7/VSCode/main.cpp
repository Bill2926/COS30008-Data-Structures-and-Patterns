#include <iostream>
#include <string>

using namespace std;

template<typename T> 
T add(T a, T b) {
    return a+b;
}

int main() {
    cout << "Hello, World!" << endl;
    // int a = 10;
    // int b = 20;
    // int sum = a + b;
    // cout << "The sum of " << a << " and " << b << " is: " << sum << endl;
    cout << add(10, 20) << endl;
    // cout << add("ec", "ngu") << endl;
    return 0;
}