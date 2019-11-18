#include "helperfunctions.h"



bool arefloatsequal(const float &A, const float &B, const float &maxRelDiff){
	// Calculate the difference.
	const float diff = fabs(A - B);
	// Find the largest of A/B abs. and assign to largest
	const float largest = (fabs(B) > fabs(A)) ? fabs(B) : fabs(A);
	if (diff <= largest * maxRelDiff) {
		return true;
	}
	return false;
}


float clamped_acos(const float & value)
{
	if (value <= -1.0) {
		return static_cast<float>(PI);
	}
	else if (value >= 1.0) {
		return static_cast<float>(0);
	}
	else {
		return acos(value);
	}
}

void progressbar(float &processed, float &oldprocessed, const size_t &progresscounter, const size_t &sizeporevec)
{
	oldprocessed = processed;
	processed = std::roundf(static_cast<float>(progresscounter) / static_cast<float>(sizeporevec) * 100); // fertig in prozent (0.xy)
	if (oldprocessed != processed) { // new percent values only
		std::cout << "\rprocessed " << processed << "% of pores!";
	}
}
