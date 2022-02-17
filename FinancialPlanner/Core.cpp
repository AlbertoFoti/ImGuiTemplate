#include "Core.h"

double Core::CompoundInterestCalculate(double initialNW, double interestRate, double annualDeposits, int investmentYears)
{
	if (investmentYears < 0 || interestRate < 0 || initialNW < 0) {
		return 0.00;
	}

	if (investmentYears > 0) {
		double curr_nw = initialNW + annualDeposits + ((initialNW + annualDeposits) * (interestRate / 100));
		return this->CompoundInterestCalculate(curr_nw, interestRate, annualDeposits, investmentYears - 1);
	}
	else {
		return initialNW;
	}

	return 0.00;
}
