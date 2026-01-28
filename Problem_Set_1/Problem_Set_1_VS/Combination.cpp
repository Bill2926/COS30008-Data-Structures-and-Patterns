#include "Combination.h"
#include <cstddef>


Combination::Combination(size_t aN, size_t aK) : fN(aN), fK(aK) {};
size_t Combination::getN() const { return fN; };
size_t Combination::getK() const { return fK; };

unsigned long long Combination::operator()() const {
	if (fN < fK) { return 0ULL; }
	unsigned long long result = 1ULL;
	// Now the index is = fK
	for (size_t i = 1; i <= fK; i++) {
		unsigned long long divisor = fN - (i - 1);
		unsigned long long dividend = i;
		result = (result * divisor) / dividend;
		
	}
	return result;
};