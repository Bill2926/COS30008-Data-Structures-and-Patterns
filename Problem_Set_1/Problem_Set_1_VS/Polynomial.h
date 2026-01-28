// COS30008, Problem Set 1/2, 2022

#pragma once

#include <iostream>

#define MAX_POLYNOMIAL 10               // max degree for input
#define MAX_DEGREE MAX_POLYNOMIAL*2+1   // max degree = 10 + 10 + 1 = 21

class Polynomial
{
private:
	size_t fDegree;					    // the maximum degree of the polynomial
	double fCoeffs[MAX_DEGREE+1];	    // the coefficients (0..10, 0..20)

public:
	Polynomial() : fDegree(0) {
		for (int i = 0; i <= MAX_DEGREE; i++) {
			fCoeffs[i] = 0.0;
		}
	};

	// binary operator* to multiple to polynomials
	// arguments are read-only, signified by const
	// the operator* returns a fresh polynomial with degree i+j
	Polynomial operator*(const Polynomial& aRHS) const {
		Polynomial Result;
		//Logic
		for (int i = fDegree; i >= 0; i--) {
			double thisCoeff = fCoeffs[i];
			Result.fDegree = fDegree + aRHS.fDegree;
			for (int j = aRHS.fDegree; j >= 0; j--) {
				int newExpo = i + j;
				double newCoeff = thisCoeff * aRHS.fCoeffs[j];
				Result.fCoeffs[newExpo] += newCoeff;
			}
		}
		return Result;
	};

	// binary operator== to compare two polynomials
	// arguments are read-only, signified by const
	// the operator== returns true if this polynomial is
	// structurally equivalent to the aRHS polynomial
	bool operator==(const Polynomial& aRHS) const {
		if (fDegree == aRHS.fDegree) {
			// Check for the inside coeffs arr
			for (int i = 0; i <= fDegree; i++) {
				if (fCoeffs[i] != aRHS.fCoeffs[i]) { return false; }
			}
			return true;
		}
		else { return false; }
	};

	// input operator for polynomials (highest to lowest)
	friend std::istream& operator>>(std::istream& aIStream, Polynomial& aObject) {
		aIStream >> aObject.fDegree;
		// This is because for the input, the coeff for the first term (largest power) is entered first
		// but then stored at the last index of the fCoeffs array
		for (int i = aObject.fDegree; i >= 0; i--) {
			aIStream >> aObject.fCoeffs[i];
		}

		return aIStream;
	};

	// output operator for polynomials (highest to lowest)
	friend std::ostream& operator<<(std::ostream& aOStream, const Polynomial& aObject) {
		bool firstTerm = true;
		for (int i = aObject.fDegree; i >= 0; i--) {
			double coeff = aObject.fCoeffs[i];
			if (coeff == 0.0) {
				continue;
			}
			else {
				if (firstTerm == true) {
					aOStream << coeff << "x^" << i;
					firstTerm = false;
				}
				else {
					aOStream << " + " << coeff << "x^" << i;
				}
			}
		}

		return aOStream;
	};
    
    // Problem Set 1 extension
    
    // call operator to calculate polynomial for a given x (i.e., aX)
    double operator()( double aX ) const;

    // compute derivative: the derivative is a fresh polynomial with degree
    // fDegree-1, the method does not change the current object
    Polynomial getDerivative() const;

    // compute indefinite integral: the indefinite integral is a fresh
    // polynomial with degree fDegree+1
    // the method does not change the current object
    Polynomial getIndefiniteIntegral() const;

    // calculate definite integral: the method does not change the current
    // object; the method computes the indefinite integral and then
    // calculates it for xlow and xhigh and returns the difference
    double getDefiniteIntegral( double aXLow, double aXHigh ) const;
};
