//#include <iostream>
//#include <vector>
//#include <iterator>
//
//using namespace std;
//
//class IntArrIterator {
//private:
//	const int* fElements;
//	const int fArrLength;
//	int fIndex;
//public:
//	IntArrIterator(const int anArr[], const int length, const int index = 0)
//		: fElements(anArr), fArrLength(length)
//	{
//		fIndex = index;
//	}
//
//	const int& operator*() const {
//		// Dereference
//		return fElements[fIndex];
//	};
//
//	IntArrIterator& operator++() {
//		// prefix => move to the new pos and return the new copy of itself (on the new pos already)
//		fIndex++;
//		return *this;
//	};
//
//	IntArrIterator operator++(int) {	// int here is dummy, just to distinguish 
//		//postfix => move to the new pos and return the old copy of itself
//		IntArrIterator temp = *this;
//		++(*this);	// reuse the code of the prefix
//		return *this;
//	};
//
//	bool operator==(const IntArrIterator& another) const {
//		return (fIndex == another.fIndex) && (fElements == another.fElements);
//	};
//
//	bool operator!=(const IntArrIterator& another) const {
//		return !(*this == another);
//	};
//
//	IntArrIterator begin() {
//		IntArrIterator result = *this;	// Copy the current one
//		result.fIndex = 0;
//		return result;
//	};
//
//	IntArrIterator end() {
//		IntArrIterator result = *this;
//		result.fIndex = fArrLength;
//		return result;
//	};
//};
//
//
//int main() {
//	int arr[] = { 1, 2, 3, 4, 5 };
//	int sum = 0;
//
//	/*for (IntArrIterator IAI(arr, 5); IAI != IAI.end(); IAI++) {
//		sum += *IAI;
//	}*/
//
//	for (const auto& i : IntArrIterator(arr, 5)) {
//		sum += i;
//	};
//
//	cout << "Result " << sum << endl;
//
//	//vector<int> arr = { 1, 2, 3, 4, 5 };
//	//vector<int>::iterator it;	// Pointer-like obj
//	//it = arr.begin();
//	//cout << &it << endl;
//	//cout << *it << endl;
//	//it++;
//	//cout << *it << endl;
//	//++it;
//	//cout << *it << endl;
//
//	/*cout << "Enter some num: " << endl;
//	istream_iterator<int> input_it(cin);
//	istream_iterator<int> eos;
//	int sum = 0;
//	while (input_it != eos) {
//		sum += *input_in;
//		++input_in;
//	}
//	cout << "The sum is: " << sum << endl;*/
//
//	
//	/*vector<string> arr = { "a", "b", "c", "d" };
//	ostream_iterator<string> output_it(cout, ", ");
//	*output_it = "k";
//	++output_it;
//	copy(arr.begin(), arr.end(), output_it);*/
//
//
//	return 0;
//}