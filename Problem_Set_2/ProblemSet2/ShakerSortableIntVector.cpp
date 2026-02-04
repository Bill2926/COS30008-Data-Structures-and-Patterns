#include "ShakerSortableIntVector.h"

ShakerSortableIntVector::ShakerSortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
	: SortableIntVector(aArrayOfIntegers, aNumberOfElements) { };

void ShakerSortableIntVector::sort(Comparable aOrderFunction)
{
	int arrLength = this->size();
	for (int i = 0; i < arrLength/2; i++) {
		for (int j = 0; j < arrLength - 1 - i; j++) {
			int leftVal = this->get(j);
			int rightVal = this->get(j + 1);
			if (aOrderFunction(leftVal, rightVal)) {
				this->swap(j, j+1);
			}
		}
		// now going backward
		for (int k = arrLength - 2 - i; k >= i; k--) {
			int leftVal = this->get(k);
			int rightVal = this->get(k + 1);
			if (aOrderFunction(leftVal, rightVal)) {
				this->swap(k, k + 1);
			}
		}
	}
};