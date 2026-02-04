#include "SortableIntVector.h"

SortableIntVector::SortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
	: IntVector(aArrayOfIntegers, aNumberOfElements)
{ };

void SortableIntVector::sort(Comparable aOrderFunction) {
	size_t ArrSize = this->size();
	for (int i = 0; i < ArrSize; i++) {
		for (size_t j = 0; j < ArrSize - 1 - i; j++) {
			// since the larger ele is sorted, we don't need to check for it anymore
			size_t leftVal = this->get(j);
			size_t rightVal = this->get(j + 1);
			if (!aOrderFunction(leftVal, rightVal)) {
				this->swap(j, j+1);
			}
		}
	}
};