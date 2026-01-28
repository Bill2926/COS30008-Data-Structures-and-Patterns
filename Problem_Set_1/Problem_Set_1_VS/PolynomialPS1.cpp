
#include "Polynomial.h"
#include <cmath>


double Polynomial::operator()(double aX) const
{
	double result = 0.0;
	// Replace each terms with input value of x and calculate
	// Therefore we don't have to reverse the for loop
	for (size_t i = 0; i <= fDegree; i++) {
		result += fCoeffs[i] * pow(aX, i);
	}
	return result;
};

Polynomial Polynomial::getDerivative() const
{

	if (fDegree == 0) {
		return Polynomial();
	}

	Polynomial result;
	result.fDegree = fDegree - 1;
	for (size_t i = 1; i <= fDegree; i++) {
		// The 0 term will disappear
		size_t newTerm = i - 1;
		double newCoeff = fCoeffs[i] * i;
		result.fCoeffs[newTerm] = newCoeff;
	}

	return result;
};

Polynomial Polynomial::getIndefiniteIntegral() const
{
	Polynomial result;

	result.fDegree = fDegree + 1;
	for (size_t i = 0; i <= fDegree; i++) {
		size_t newTerm = i + 1;
		double newCoeff = fCoeffs[i] / newTerm;
		result.fCoeffs[newTerm] = newCoeff;
	}

	return result;
};

double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const
{
	double result = 0.0;
	Polynomial afterInIntegral = getIndefiniteIntegral();
	double lowValue = afterInIntegral.operator()(aXLow);
	double highValue = afterInIntegral.operator()(aXHigh);
	result = highValue - lowValue;
	return result;
};