#include "FibonacciSequenceIterator.h"

FibonacciSequenceIterator::FibonacciSequenceIterator(const FibonacciSequence& aSequenceObject, uint64_t aStart)
	: fSequenceObject(aSequenceObject), fIndex(aStart) { }

FibonacciSequenceIterator::FibonacciSequenceIterator(uint64_t aLimit, uint64_t aStart)
	: fSequenceObject(FibonacciSequence(aLimit)), fIndex(aStart) { }

const uint64_t& FibonacciSequenceIterator::operator*() const
{
	return fSequenceObject.current();
}

FibonacciSequenceIterator& FibonacciSequenceIterator::operator++()
{
	fSequenceObject.advance();
	fIndex++;
	return *(this);
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int)
{
	FibonacciSequenceIterator old = *this;
	fSequenceObject.advance();
	fIndex++;
	return old;
}

bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator& aOther) const
{
	return fIndex == aOther.fIndex;
}

bool FibonacciSequenceIterator::operator!=(const FibonacciSequenceIterator& aOther) const
{
	return !(*this == aOther);
}

FibonacciSequenceIterator FibonacciSequenceIterator::begin() const
{
	FibonacciSequenceIterator newCopy = *this;
	newCopy.fIndex = 1;
	return newCopy;
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const
{
	FibonacciSequenceIterator newCopy = *this;
	uint64_t limit = fSequenceObject.getLimit();
	newCopy.fIndex = (limit == 0) ? 0 : (limit + 1);
	return newCopy;
}