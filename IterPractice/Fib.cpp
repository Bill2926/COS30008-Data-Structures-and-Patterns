#include "FibonacciSequence.h"
#include "FibonacciSequenceIterator.h"
#include <stdexcept>


FibonacciSequence::FibonacciSequence(uint64_t aLimit)
	: fLimit(aLimit), fPosition(1), fCurrent(1), fPrevious(0) { }

const uint64_t& FibonacciSequence::current() const
{
	return fCurrent;
}

void FibonacciSequence::advance()
{
	if (fLimit == 0 || fPosition <= fLimit)
	{
		uint64_t tmp = fCurrent;
		fCurrent = fCurrent + fPrevious;
		fPrevious = tmp;
		fPosition++;
	}
	else
	{
		throw std::out_of_range("Out of range.");
	}
}

const uint64_t& FibonacciSequence::getLimit() const
{
	return fLimit;
}

void FibonacciSequence::reset()
{
	fPosition = fCurrent = 1;
	fPrevious = 0;
}

FibonacciSequenceIterator FibonacciSequence::begin() const
{
	FibonacciSequence copy = *this;
	copy.reset();

	return FibonacciSequenceIterator(copy);
}

FibonacciSequenceIterator FibonacciSequence::end() const
{
	FibonacciSequence copy = *this;
	uint64_t sentinel = (fLimit == 0) ? 0 : (fLimit + 1);

	return FibonacciSequenceIterator(copy, sentinel);
}