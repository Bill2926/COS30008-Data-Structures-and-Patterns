#include "BernsteinBasisPolynomial.h"
#include <cmath>

// my code

BernsteinBasisPolynomial::BernsteinBasisPolynomial(unsigned int aV, unsigned int aN) : fFactor(aN, aV) {};

double BernsteinBasisPolynomial::operator()(double aX) const {
	unsigned int aV = fFactor.getK();
	unsigned int aN = fFactor.getN();
	
	if ((aX == 0.0 && aV != 0) || (aX == 1 && aV != aN)) {
		return 0.0;
	}

	double result = 0.0;

	double module1 = fFactor();
	double module2 = pow(aX, aV);
	double module3 = pow((1 - aX), (aN - aV));

	result = module1 * module2 * module3;

	return result;
};