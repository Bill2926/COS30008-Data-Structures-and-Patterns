// 02/02/2026

#include "FibonacciSequence.h"
#include "FibonacciSequenceIterator.h"
#include <iostream>
#include <cstdint>

using namespace std;

FibonacciSequence::FibonacciSequence(uint64_t aLimit) 
	: fLimit(aLimit), fPrevious(0), fCurrent(1), fPosition(1)
{};

const uint64_t& FibonacciSequence::current() const {
	return fCurrent;
};

void FibonacciSequence::advance() {
	if (fLimit == 0 || fPosition <= fLimit) {
		uint64_t next = fPrevious + fCurrent;
		fPrevious = fCurrent;
		fCurrent = next;
		fPosition++;
	}
	else {
		throw out_of_range("exceeding limit");
	}
};

const uint64_t& FibonacciSequence::getLimit() const {
	return fLimit;
};

void FibonacciSequence::reset() {
	fPrevious = 0;
	fCurrent = 1;
	fPosition = 1;
};

FibonacciSequenceIterator FibonacciSequence::begin() const {
	return FibonacciSequenceIterator(*this);
};

FibonacciSequenceIterator FibonacciSequence::end() const {
	return FibonacciSequenceIterator(*this, fLimit+1);
};