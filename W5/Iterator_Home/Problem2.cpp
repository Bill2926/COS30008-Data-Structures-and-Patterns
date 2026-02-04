#include "FibonacciSequenceIterator.h"
#include <iostream>

using namespace std;

FibonacciSequenceIterator::FibonacciSequenceIterator(const FibonacciSequence& aSequenceObject, uint64_t aStart)
	: fSequenceObject(aSequenceObject), fIndex(aStart) {};

FibonacciSequenceIterator::FibonacciSequenceIterator(uint64_t aLimit, uint64_t aStart)
	: fSequenceObject(aLimit), fIndex(aStart) {};

const uint64_t& FibonacciSequenceIterator::operator*() const {
	return fSequenceObject.current();
};

FibonacciSequenceIterator& FibonacciSequenceIterator::operator++() {
	fSequenceObject.advance();
	fIndex++;
	return *this;
};

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int) {
	FibonacciSequenceIterator temp = *this;
	++(*this);	// Reuse
	return temp;
};

bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator& aOther) const
{
	return fIndex == aOther.fIndex;
};

bool FibonacciSequenceIterator::operator!=(const FibonacciSequenceIterator& aOther) const
{
	return !(*this == aOther);
};

FibonacciSequenceIterator FibonacciSequenceIterator::begin() const
{
	FibonacciSequenceIterator result = fSequenceObject.begin();	
	result.fIndex = 1;
	return result;
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const
{
	FibonacciSequenceIterator result = fSequenceObject.end();
	result.fIndex = fSequenceObject.getLimit();
	return result;
}